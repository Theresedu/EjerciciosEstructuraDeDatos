#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Blackjack {
private:
    sf::Font font;
    sf::Text playerText, dealerText, messageText;
    std::vector<int> playerHand, dealerHand;
    bool gameOver;
    
    void dealCard(std::vector<int>& hand);
    int calculateScore(const std::vector<int>& hand);
    void checkGameState();

public:
    Blackjack();
    void startGame();
    void handleInput(sf::Event event);
    void render(sf::RenderWindow& window);
    void resetGame();
};

#endif

