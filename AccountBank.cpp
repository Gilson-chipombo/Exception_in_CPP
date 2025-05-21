#include <iostream>

class AccountBank {
    private: 
        double saldo;
    public:
        AccountBank();
        double sacar(double amount);
        double getSaldo();
        void   setSaldo(double amount);
};

AccountBank::AccountBank(): saldo(0){}

double AccountBank::sacar(double amount)
{
    if (amount > getSaldo())
        throw "Saldo insuficiente";
    if (amount < 0)
        throw "Nao pode sacar quantidade negativa";
    saldo = saldo - amount;
    return (saldo);
}

void AccountBank::setSaldo(double amount)
{
    if (amount < 0)
        throw "Nao pode depositar saldo negativo";
    saldo = amount;
}

double AccountBank::getSaldo()
{
    return (saldo);
}

int main()
{
    AccountBank c;

    try{
        c.setSaldo(100);
        c.sacar(-1);
        std::cout << "Saldo restante: " << c.getSaldo() << std::endl; 
    }catch(const char* msg)
    {
        std::cout << msg << std::endl;
    }

}

