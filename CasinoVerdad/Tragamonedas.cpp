

#include "Tragamonedas.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

Tragamonedas::Tragamonedas() {
    saldo = 0;
    apuesta = 0;

    if (!fondoTexture.loadFromFile("FondoTragamonedas.png")) {
        cout << "Error cargando fondo" << endl;
    }
    fondo.setTexture(fondoTexture);
    fondo.setPosition(0, 0);
    fondo.setScale(900.0f / fondoTexture.getSize().x, 700.0f / fondoTexture.getSize().y);

    if (!font.loadFromFile("arial.ttf")) {
        cout << "Error cargando fuente" << endl;
    }

    imagenes[0] = "estrellatragamonedas.png";
    imagenes[1] = "numero7.png";
    imagenes[2] = "campanaTragamonedas.png";
    imagenes[3] = "cereza.png";
    imagenes[4] = "diamante.png";

    for (int i = 0; i < 3; i++) {
        if (!iconosTexture[i].loadFromFile(imagenes[i])) {
            cout << "Error cargando imagen " << imagenes[i] << endl;
        }
        iconos[i].setTexture(iconosTexture[i]);
        iconos[i].setScale(0.3f, 0.3f); // Ajuste de tamaño para mejorar la apariencia
        iconos[i].setPosition(200 + (i * 200), 350);
    }

    mensaje.setFont(font);
    mensaje.setCharacterSize(30);
    mensaje.setPosition(250, 600);
    mensaje.setFillColor(sf::Color::White);
    mensaje.setString("Ingrese su saldo inicial y apuesta");
}

void Tragamonedas::setSaldo(double cantidad) {
    saldo = cantidad;
}

void Tragamonedas::setApuesta(double cantidad) {
    apuesta = cantidad;
}

void Tragamonedas::jugar() {
    if (saldo < apuesta) {
        mensaje.setString("Saldo insuficiente");
        return;
    }

    saldo -= apuesta;
    srand(time(0));
    int resultados[3];
    for (int i = 0; i < 3; i++) {
        resultados[i] = rand() % 5;
        if (!iconosTexture[i].loadFromFile(imagenes[resultados[i]])) {
            cout << "Error cargando imagen " << imagenes[resultados[i]] << endl;
        }
        iconos[i].setTexture(iconosTexture[i]);
        iconos[i].setScale(0.3f, 0.3f); // Ajuste para mantener el tamaño correcto
    }

    if (resultados[0] == resultados[1] && resultados[1] == resultados[2]) {
        double ganancia = apuesta * 5; // Multiplicador de ganancia
        saldo += ganancia;
        mensaje.setString("GANASTE! Premio: " + to_string(ganancia) + "\nSaldo: " + to_string(saldo));
    } else {
        mensaje.setString("Intenta de nuevo\nSaldo: " + to_string(saldo));
    }
}

void Tragamonedas::render(sf::RenderWindow &window) {
    window.clear(sf::Color::Black); // Asegura que el fondo se limpia correctamente
    window.draw(fondo); // Dibuja el fondo primero
    for (int i = 0; i < 3; i++) {
        window.draw(iconos[i]); // Dibuja las imágenes de los símbolos sobre los rectángulos
    }
    window.draw(mensaje);  // Mostrar el mensaje en pantalla
}

void Tragamonedas::startGame() {
    sf::RenderWindow window(sf::VideoMode(900, 700), "Tragamonedas - Casino");  // Crear la ventana de SFML
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    jugar();  // Jugar al presionar la barra espaciadora
                }
            }
        }

        render(window);  // Renderizar el juego
        window.display();  // Mostrar el contenido renderizado
    }
}
