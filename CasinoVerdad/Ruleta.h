#ifndef RULETA_H
#define RULETA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Ruleta {
private:
    sf::Font font;
    sf::Text titleText, resultText, messageText, betText, winningsText;
    sf::RectangleShape rueda;
    sf::CircleShape indicador;
    int resultado;
    bool girando;
    int apuesta;
    int tipoApuesta; // 0 = número, 1 = rojo, 2 = negro, 3 = par, 4 = impar, 5 = docena, 6 = columna
    int numeroApostado;
    std::string colorApostado;
    int docenaApostada;
    int columnaApostada;
    int ganancias;
    
    void generarResultado();
    void calcularGanancia();
    bool esRojo(int numero);
    bool esPar(int numero);
    int obtenerDocena(int numero);
    int obtenerColumna(int numero);

public:
    Ruleta();
    void startGame();
    void handleInput(sf::Event event);
    void update();
    void render(sf::RenderWindow& window);
    void solicitarApuesta();
    void setApuesta(int cantidad, int tipo, int numero, std::string color, int docena = -1, int columna = -1);
};

#endif