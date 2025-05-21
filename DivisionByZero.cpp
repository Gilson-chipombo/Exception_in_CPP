#include <iostream>

int main()
{
    int a, b;

    std::cout << "Digite o numerador: ";
    std::cin >> a;
    std::cout << "Digite o denominador: ";
    std::cin >> b;

    try{
        if (b == 0)
            throw "Division by zero!";
        std::cout << (double)(a / b) << std::endl;
    }catch(const char* msg)
    {
        std::cout << msg << std::endl;
    }
}