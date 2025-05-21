#include <iostream>
#include <string>
#include <exception>

class CustumizedError : public std::exception
{
    public:
        const char* what() const noexcept override{
            return "Erro custumizado: Algo deu errado";
        }
};

void generateException(int type)
{
    if (type == 1)
        throw 42; //throw an exception type int
    else if (type == 2)
        throw std::string("String error");
    else if (type == 3)
        throw CustumizedError();
    else
        throw std::runtime_error("Unknown Error");
}

int main(){

    int type;
    std::cout << "Write the type exception (1 int, 2 string, 3 CustumizedError): ";
    std::cin >> type;

    try{
        generateException(type);
    }
    catch (int e){
        std::cout << "Exception captured (int): " << e << std::endl;
    }
    catch (const std::string& e){
        std::cout << "Exception captured (string): " << e << std::endl;
    }
    catch (const CustumizedError& e){
        std::cout << "Exception captured (CustumizedError): " << e.what() << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "Exception captured (std::exception): " << e.what() << std::endl;
    }
    return (0);
}

