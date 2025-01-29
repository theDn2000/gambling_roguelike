#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "../include/GamblingMachine.h"

int main() {
    // Configuración //
    std::setlocale(LC_ALL, "es_ES.UTF-8");
    
    // Declaraciones //
    GamblingMachine maquina;

    
    int spins = 5; // Contador de tiradas
    int wins = 0;  // Contador de victorias

    // Aqui se define la logica del juego en conjunto. Las rondas, tiradas totales, etc.
    std::cout << "Bienvenido a la Gambling Machine! Tienes " << spins << " intentos para ganar.\n";

    for (int i = 0; i < 5; ++i) {
        maquina.spin();
        if (maquina.check()) {
            wins++;
        }
        maquina.show();
        std::cout << "Intentos restantes: " << 5 - i - 1 << std::endl;

        spins++;
    }

    if (wins > 0) {
        std::cout << "¡Felicidades! Has ganado " << wins << " veces.\n";
    }
    else {
        std::cout << "¡Lo siento! No has ganado ninguna vez.\n";
    }


    return 0;
}
