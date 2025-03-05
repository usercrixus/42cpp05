#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat b("Chirac", 10);
		std::cout << b;
		b.decrementGrade();
		std::cout << "\n\n";
		Form f("Test", 10, 10);
		std::cout << f;
		std::cout << "\n\n";
		b.signForm(f);
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}