

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Blackjack.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tragamonedas.h"
#include "Registro.h"

Blackjack::Blackjack() {
    font.loadFromFile("arial.ttf");
    playerText.setFont(font);
    dealerText.setFont(font);
    messageText.setFont(font);

    playerText.setPosition(50, 400);
    dealerText.setPosition(50, 100);
    messageText.setPosition(250, 300);

    // Cargar la imagen de fondo
    if (!fondoTexture.loadFromFile("FondoBlackJack.jpg")) {
        std::cout << "Error cargando fondo de Blackjack" << std::endl;
    }
    fondo.setTexture(fondoTexture);
    fondo.setPosition(0, 0);
    fondo.setScale(800.0f / fondoTexture.getSize().x, 600.0f / fondoTexture.getSize().y);

    srand(static_cast<unsigned>(time(0)));
    resetGame();
}

void Blackjack::startGame() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Blackjack - Casino");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            handleInput(event);
        }
        window.clear();
        render(window);
        window.display();
    }
}

void Blackjack::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed && !gameOver) {
        if (event.key.code == sf::Keyboard::H) {  // Hit (Pedir carta)

            dealCard(playerHand);
            checkGameState();
        } else if (event.key.code == sf::Keyboard::S) {  // Stand (Quedarse)
            while (calculateScore(dealerHand) < 17) {
                dealCard(dealerHand);
            }
            checkGameState();
        } else if (event.key.code == sf::Keyboard::F) {  // Fold (Rendirse)
            messageText.setString("Perdiste! Te retiraste.");
            gameOver = true;
        }
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
        resetGame();  // Reiniciar partida con 'Q'
    }
}

void Blackjack::dealCard(std::vector<int>& hand) {
    hand.push_back(rand() % 10 + 1);
}

int Blackjack::calculateScore(const std::vector<int>& hand) {
    int sum = 0;
    for (int card : hand) {
        sum += card;
    }
    return sum;
}

void Blackjack::checkGameState() {
    int playerScore = calculateScore(playerHand);
    int dealerScore = calculateScore(dealerHand);

    if (playerScore > 21) {
        messageText.setString("Perdiste! Te pasaste de 21.");
        gameOver = true;
    } else if (dealerScore > 21 && dealerScore > 17) {
        messageText.setString("Ganaste! El dealer se paso de 21.");
        gameOver = true;
    } else if (playerScore == 21) {
        messageText.setString("Blackjack! Ganaste!");
        gameOver = true;
    }
}


void Blackjack::render(sf::RenderWindow& window) {
    window.draw(fondo);  // Dibuja el fondo antes de los textos

    std::string playerScore = "Jugador: ";
    for (int card : playerHand) {
        playerScore += std::to_string(card) + " ";
    }
    playerText.setString(playerScore);

    std::string dealerScore = "Dealer: ";
    for (int card : dealerHand) {
        dealerScore += std::to_string(card) + " ";
    }
    dealerText.setString(dealerScore);

    window.draw(playerText);
    window.draw(dealerText);
    window.draw(messageText);
}

void Blackjack::resetGame() {
    playerHand.clear();
    dealerHand.clear();
    gameOver = false;
    messageText.setString("");
    dealCard(playerHand);
    dealCard(playerHand);
    dealCard(dealerHand);
    dealCard(dealerHand);
}