

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "MenuApuestas.h"
#include "Ruleta.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "Registro.h"

Ruleta::Ruleta() {
    font.loadFromFile("arial.ttf");
    titleText.setFont(font);
    resultText.setFont(font);
    messageText.setFont(font);
    betText.setFont(font);
    saldoText.setFont(font);
    
    titleText.setString("Juego de la Ruleta");
    titleText.setPosition(250, 50);
    
    resultText.setPosition(350, 400);
    messageText.setPosition(250, 500);
    betText.setPosition(250, 450);
    saldoText.setPosition(250, 550);
    
    rueda.setSize(sf::Vector2f(300, 300));
    rueda.setFillColor(sf::Color::Red);
    rueda.setPosition(250, 150);
    
    indicador.setRadius(10);
    indicador.setFillColor(sf::Color::White);
    indicador.setPosition(390, 140);
    
    if (!fondoTexture.loadFromFile("FondodeRuleta.jpg")) {
        std::cout << "Error cargando fondo de ruleta" << std::endl;
    }
    fondo.setTexture(fondoTexture);
    fondo.setScale(800.0f / fondoTexture.getSize().x, 600.0f / fondoTexture.getSize().y);

    srand(static_cast<unsigned>(time(0)));
    girando = false;
    resultado = -1;
    apuesta = 0;
    tipoApuesta = -1;
    numeroApostado = -1;
    colorApostado = "";
    docenaApostada = -1;
    columnaApostada = -1;
    saldo = 50; 
}

void Ruleta::startGame(int cantidad) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ruleta - Casino");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            handleInput(event, cantidad);
        }
        update();
        window.clear();
        render(window);
        window.display();
    }
}

bool Ruleta::esRojo(int numero) {
    int rojos[] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    for (int i : rojos) {
        if (i == numero) return true;
    }
    return false;
}

bool Ruleta::esPar(int numero) {
    return numero % 2 == 0 && numero != 0 && numero != 37;
}

int Ruleta::obtenerDocena(int numero) {
    if (numero >= 1 && numero <= 12) return 1;
    if (numero >= 13 && numero <= 24) return 2;
    if (numero >= 25 && numero <= 36) return 3;
    return -1;
}

int Ruleta::obtenerColumna(int numero) {
    return (numero - 1) % 3 + 1;
}

void Ruleta::solicitarApuesta(int cantidad) {
    int tipo, numero = -1, docena = -1, columna = -1;
    std::string color = "";
    
    /*std::cout << "Ingrese la cantidad a apostar: ";
    std::cin >> cantidad;*/
    //cantidad = 1;
    tipo = menuApuestas.mostrarMenuApuestas();
    
    if (tipo == 0) {
        std::cout << "Ingrese el numero (0-36 o 37 para 00): ";
        std::cin >> numero;
    } else if (tipo == 1 || tipo == 2) {
        color = (tipo == 1) ? "Rojo" : "Negro";
    } else if (tipo == 5) {
        std::cout << "Seleccione la docena (1: 1-12, 2: 13-24, 3: 25-36): ";
        std::cin >> docena;
    } else if (tipo == 6) {
        std::cout << "Seleccione la columna (1, 2 o 3): ";
        std::cin >> columna;
    }
    
    setApuesta(cantidad, tipo, numero, color, docena, columna);
}

void Ruleta::setSaldo(double saldo) {
    this->saldo = saldo;
    saldoText.setString("Saldo: " + std::to_string(saldo));
}

void Ruleta::setApuesta(int cantidad, int tipo, int numero, std::string color, int docena, int columna) {
    apuesta = cantidad;

    tipoApuesta = tipo;
    numeroApostado = numero;
    colorApostado = color;
    docenaApostada = docena;
    columnaApostada = columna;
    betText.setString("Apostaste: " + std::to_string(cantidad));
}

void Ruleta::calcularGanancia() {
    if (tipoApuesta == 0 && resultado == numeroApostado) {
        saldo += apuesta * 35;
        messageText.setString("Ganaste! x35");
    } else if (tipoApuesta == 1 && esRojo(resultado)) {
        saldo += apuesta * 2;
        messageText.setString("Ganaste al rojo! x2");
    } else if (tipoApuesta == 2 && !esRojo(resultado) && resultado != 0 && resultado != 37) {
        saldo += apuesta * 2;
        messageText.setString("Ganaste al negro! x2");
    } else if (tipoApuesta == 3 && esPar(resultado)) {
        saldo += apuesta * 2;
        messageText.setString("Ganaste al par! x2");
    } else if (tipoApuesta == 4 && !esPar(resultado)) {
        saldo += apuesta * 2;
        messageText.setString("Ganaste al impar! x2");
    } else if (tipoApuesta == 5 && obtenerDocena(resultado) == docenaApostada) {
        saldo += apuesta * 3;
        messageText.setString("Ganaste a la docena! x3");
    } else if (tipoApuesta == 6 && obtenerColumna(resultado) == columnaApostada) {
        saldo += apuesta * 3;
        messageText.setString("Ganaste a la columna! x3");
    } else {
        saldo -= apuesta;
        messageText.setString("Perdiste! Intenta de nuevo");
    }
    saldoText.setString("Saldo: " + std::to_string(saldo));
}

void Ruleta::generarResultado() {
    resultado = rand() % 38; // 0-36 + 37 representa el 00
    std::string resultadoTexto = (resultado == 37) ? "00" : std::to_string(resultado);
    resultText.setString("Resultado: " + resultadoTexto);
    calcularGanancia();
}

void Ruleta::handleInput(sf::Event event, int cantidad) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !girando) {
        solicitarApuesta(cantidad);
        girando = true;
        messageText.setString("Girando la ruleta...");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        generarResultado();
    }
}

void Ruleta::update() {
    if (!girando && resultado != -1) {
        messageText.setString("Presiona ESPACIO para jugar otra vez");
    }
}

void Ruleta::render(sf::RenderWindow& window) {
    window.draw(fondo);
    window.draw(titleText);
    window.draw(rueda);
    window.draw(indicador);
    window.draw(resultText);
    window.draw(messageText);
    window.draw(betText);
    window.draw(saldoText);
}

