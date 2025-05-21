#include <iostream>
#include <string>
#include <stdexcept>  // Para std::exception

// Definindo a estrutura Person
struct Person {
    std::string name;
    int age;

    // Construtor da estrutura
    Person(std::string n, int a) : name(n), age(a) {
        if (a < 0 || a > 150) {
            throw std::out_of_range("Idade fora do intervalo válido (0 a 150).");
        }
    }

    // Método para exibir a informação da pessoa
    void displayInfo() const {
        std::cout << "Nome: " << name << ", Idade: " << age << std::endl;
    }
};

// Função que pode lançar exceção
void divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Divisão por zero!");
    }
    std::cout << "Resultado da divisão: " << a / b << std::endl;
}

int main() {
    try {
        // Tentando criar um objeto com idade inválida (fora do intervalo)
        Person p1("Carlos", 200); // Lançará exceção

        // Tentando dividir por zero
        divide(10, 0); // Lançará exceção

        // Outro objeto com idade válida
        Person p2("Ana", 30);
        p2.displayInfo(); // Executará normalmente
    } catch (std::exception& e) {
        // Captura qualquer exceção que herda de std::exception
        std::cout << "Erro capturado: " << e.what() << std::endl;
    }

    return 0;
}
