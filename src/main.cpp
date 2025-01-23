#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Tragaperras {
private:
    std::vector<int> simbolos; // Símbolos de la máquina
    std::vector<char> rodillos;  // Resultados de los rodillos

public:
    Tragaperras() {
        // Inicializa la semilla para la generación de números aleatorios
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        // Define los símbolos disponibles
        //simbolos = {'🍒', '🍋', '🍊', '🍉', '🍇', '🔔', '⭐', '💰', '🍀', '🍏'};
        simbolos = {'C', 'L', 'N', 'S', 'U', 'K', 'E', 'D', 'T', 'M'};
    }

    void girarRodillos() {
        // Limpia la pantalla
        std::cout << "\nGirando los rodillos...\n";
        // Genera un símbolo aleatorio para cada rodillo
        for (int i = 0; i < 2; ++i) {
            int indice = std::rand() % simbolos.size();
            rodillos.push_back(simbolos[indice]);
        }
    }

    void mostrarResultado() {
        std::cout << "Resultado: | ";
        for (const auto& simbolo : rodillos) {
            std::cout << simbolo << " | ";
        }
        std::cout << std::endl;

        // Verifica si hay una combinación ganadora
        if (rodillos[0] == rodillos[1]) {
            std::cout << "¡Felicidades! Has ganado.\n";
        } else {
            std::cout << "Intenta de nuevo.\n";
        }
    }

    void jugar() {
        char continuar;
        do {
            rodillos.clear(); // Limpia los rodillos antes de girar
            girarRodillos();
            mostrarResultado();
            std::cout << "¿Quieres jugar de nuevo? (s/n): ";
            std::cin >> continuar;
        } while (continuar == 's' || continuar == 'S');
    }
};

int main() {
    std::setlocale(LC_ALL, "es_ES.UTF-8");
    // Resto del código...
    Tragaperras maquina;
    maquina.jugar();
    return 0;
}
