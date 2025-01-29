#include "../include/GamblingMachine.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

GamblingMachine::GamblingMachine() {
    // Inicializa la semilla para la generación de números aleatorios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // Define los símbolos disponibles
    //simbolos = {'🍒', '🍋', '🍊', '🍉', '🍇', '🔔', '⭐', '💰', '🍀', '🍏'};
    simbolos = {'C', 'L', 'N', 'S', 'U', 'K', 'E', 'D', 'T', 'M'};
}

void GamblingMachine::spin() {
    this->rodillos.clear(); // Limpia los rodillos antes de girar
    // Limpia la pantalla
    std::cout << "\nGirando los rodillos...\n";
    // Genera un símbolo aleatorio para cada rodillo
    for (int i = 0; i < 2; ++i) {
        int indice = std::rand() % this->simbolos.size();
        this->rodillos.push_back(this->simbolos[indice]);
    }
}

void GamblingMachine::show() {
    std::cout << "Resultado: | ";
    for (const auto& simbolo : this->rodillos) {
        std::cout << simbolo << " | ";
    }
    std::cout << std::endl;
}

bool GamblingMachine::check() {
    // Verifica si hay una combinación ganadora
    int i = 0;
    bool win = false;
    for (i = 1; i < this->rodillos.size(); ++i) {
        if (this->rodillos[0] == this->rodillos[i]) {
            win = true;
        }
        else {
            win = false;
            break;
        }
    }
    return win;
}

void GamblingMachine::play() {
    // Esto ta sin usar
    char continuar;
    do {
        this->rodillos.clear(); // Limpia los rodillos antes de girar
        spin();
        show();
        std::cout << "¿Quieres jugar de nuevo? (s/n): ";
        std::cin >> continuar;
    } while (continuar == 's' || continuar == 'S');
}

