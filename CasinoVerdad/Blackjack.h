

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Tragamonedas.h"
#include "Registro.h"

class Blackjack {
private:
    sf::Texture fondoTexture;   // Fondo del blackjack
    sf::Sprite fondo;           // Sprite para el fondo
    sf::Font font;
    sf::Text playerText, dealerText, messageText, saldoText;
    std::vector<int> playerHand, dealerHand;
    bool gameOver;
    double saldo;  // Saldo del usuario
    Tragamonedas tragamonedas;
    Registro registro;

    void dealCard(std::vector<int>& hand);
    int calculateScore(const std::vector<int>& hand);
    void checkGameState();

public:
    Blackjack();
    void startGame();
    void handleInput(sf::Event event);
    void render(sf::RenderWindow& window);
    void resetGame();
    //void setSaldo(double saldo);  // Método para establecer el saldo
};

#endif