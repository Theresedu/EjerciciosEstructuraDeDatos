
#ifndef RULETA_H
#define RULETA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "MenuApuestas.h"
#include "Registro.h"

class Ruleta {
private:
    sf::Font font;
    sf::Text titleText, resultText, messageText, betText, saldoText;
    sf::RectangleShape rueda;
    sf::CircleShape indicador;
    sf::Texture fondoTexture;
    sf::Sprite fondo;

    int resultado;
    bool girando;
    int apuesta;
    int tipoApuesta; // 0 = número, 1 = rojo, 2 = negro, 3 = par, 4 = impar, 5 = docena, 6 = columna
    int numeroApostado;
    std::string colorApostado;
    int docenaApostada;
    int columnaApostada;
    double saldo;  // Saldo del usuario

    MenuApuestas menuApuestas;

    void generarResultado();
    void calcularGanancia();
    bool esRojo(int numero);
    bool esPar(int numero);
    int obtenerDocena(int numero);
    int obtenerColumna(int numero);

public:
    Registro numeromonto;
    Ruleta();
    void startGame(int cantidad);
    void handleInput(sf::Event event, int);
    void update();
    void render(sf::RenderWindow& window);
    void solicitarApuesta(int cantidad);
    void setApuesta(int cantidad, int tipo, int numero, std::string color, int docena = -1, int columna = -1);
    void setSaldo(double saldo);  // Método para establecer el saldo
};

#endif
