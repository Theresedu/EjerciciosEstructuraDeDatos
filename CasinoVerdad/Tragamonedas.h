

#ifndef TRAGAMONEDAS_H
#define TRAGAMONEDAS_H

#include <SFML/Graphics.hpp>  // Incluir SFML para los gráficos

class Tragamonedas {
private:
    int saldo;
    double apuesta;
    sf::Texture fondoTexture;
    sf::Sprite fondo;
    sf::Font font;
    sf::Text mensaje;
    sf::Texture iconosTexture[5];
    sf::Sprite iconos[3];
    std::string imagenes[5];

public:
    Tragamonedas();
    void setSaldo(double cantidad);
    void setApuesta(double cantidad);
    void jugar();  // Jugar la ronda
    void render(sf::RenderWindow &window); // Para renderizar el juego
    void startGame(); // Iniciar el juego (crear la ventana y gestionar la lógica)
    Tragamonedas(int saldoInicial) : saldo(saldoInicial) {}

    int getSaldo() const {
        return saldo;
    }
};

#endif // TRAGAMONEDAS_H
