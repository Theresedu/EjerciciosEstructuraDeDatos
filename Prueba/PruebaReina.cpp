#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>


// Tamaño del tablero y tamaño de cada celda
int N;
double cellSize;

// Función para dibujar el tablero
void dibujarTablero(sf::RenderWindow &window) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(j * cellSize, i * cellSize);
            cell.setFillColor((i + j) % 2 == 0 ? sf::Color::White : sf::Color::Black);
            window.draw(cell);
        }
    }
}

// Función para dibujar los movimientos de la reina
void dibujarMovimientos(sf::RenderWindow &window, int fila, int col) {
    sf::RectangleShape highlight(sf::Vector2f(cellSize, cellSize));
    highlight.setFillColor(sf::Color(200, 50, 100, 100));

    // Dibujar líneas horizontales y verticales
    for (int i = 0; i < N; i++) {
        highlight.setPosition(i * cellSize, fila * cellSize);
        window.draw(highlight);
        highlight.setPosition(col * cellSize, i * cellSize);
        window.draw(highlight);
    }
    
    // Dibujar diagonales
    for (int i = -N; i < N; i++) {
        int diag1X = col + i, diag1Y = fila + i;
        int diag2X = col + i, diag2Y = fila - i;
        
        if (diag1X >= 0 && diag1X < N && diag1Y >= 0 && diag1Y < N) {
            highlight.setPosition(diag1X * cellSize, diag1Y * cellSize);
            window.draw(highlight);
        }
        
        if (diag2X >= 0 && diag2X < N && diag2Y >= 0 && diag2Y < N) {
            highlight.setPosition(diag2X * cellSize, diag2Y * cellSize);
            window.draw(highlight);
        }
    }
}

int main() {
    std::cout << "Ingrese el tamanio del tablero (hasta 8): ";
    std::cin >> N;
    if (N < 1 || N > 8) {
        std::cerr << "Tamanio invalido. Debe estar entre 1 y 8." << std::endl;
        return -1;
    }
    
    cellSize = 500.0 / N;
    sf::RenderWindow window(sf::VideoMode(500, 500), "Movimiento de la Reina");
    sf::Texture queenTexture;
    if (!queenTexture.loadFromFile("Reina.png")) {
        std::cerr << "Error al cargar la imagen de la reina." << std::endl;
        return -1;
    }

    int fila, col;
    std::cout << "Ingrese la fila (0-" << N-1 << "): ";
    std::cin >> fila;
    std::cout << "Ingrese la columna (0-" << N-1 << "): ";
    std::cin >> col;
    
    if (fila < 0 || fila >= N || col < 0 || col >= N) {
        std::cerr << "Posicion invalida." << std::endl;
        system("pause");
        return -1;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        dibujarTablero(window);
        dibujarMovimientos(window, fila, col);
        
        // Dibujar la reina
        sf::Sprite reinaSprite;
        reinaSprite.setTexture(queenTexture);
        reinaSprite.setScale((cellSize) / queenTexture.getSize().x, (cellSize) / queenTexture.getSize().y);
        reinaSprite.setPosition(col * cellSize, fila * cellSize);
        window.draw(reinaSprite);

        window.display();
    }
    system("pause");
    return 0;
}