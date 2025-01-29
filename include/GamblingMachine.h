#ifndef GAMBLINGMACHINE_H
#define GAMBLINGMACHINE_H

#include <vector>
#include <string>

class GamblingMachine {
private:
    std::vector<int> simbolos;   // Símbolos de la máquina
    std::vector<char> rodillos;  // Resultados de los rodillos
public:
    GamblingMachine();           // Constructor
    void spin();                 // Método para girar los rodillos
    void show();                 // Método para mostrar el resultado
    bool check();                // Método para verificar si hay una combinación ganadora
    void play();                 // Método para jugar
};

#endif