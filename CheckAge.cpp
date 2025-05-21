#include <iostream>

bool checkAge(int age)
{
    if (age < 0)
        throw "Age cannot be negative!";
    return (true);
}
int main()
{
    int age;
    std::cout << "Insert your age: ";
    std::cin >> age;
    try{
        if (checkAge(age))
        std::cout << "Valid age" << std::endl;
    }catch (const char* msg)
    {
        std::cout << msg << std::endl;
    }
}