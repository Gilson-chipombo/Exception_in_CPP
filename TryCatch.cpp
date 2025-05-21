#include <iostream>
#include <exception>

struct MyException : public std::exception{
	const char * what () const throw () {
		return "C++ Exception";
	}
};


int main()
{
	try{
		throw MyException();
	} catch(MyException& e)
	{
		std::cout << "MyException caught" << std::endl;
		std::cout << e.what() << std::endl;
	} catch(std::exception& e)
	{
		std::cout << "Other Exception!" << std::endl;
	}
}



// double division(int a, int b)
// {
// 	if (b == 0)
// 		throw "Division by zero condition!";
// 	return (a/b);
// }

// int main()
// {
// 	int x = 50, y = 0;
// 	double z = 0;
	
// 	try{
// 		z = division(x, y);
// 		std::cout << z << std::endl;
// 	}catch (const char* msg)
// 	{
// 		std::cerr << msg << std::endl;
// 	}
// 	return 0;
// }
