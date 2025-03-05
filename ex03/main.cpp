#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include "Intern.hpp"

int main()
{
	try
	{
		Intern i;
		AForm *f = i.makeForm("PresidentialPardon", "test");
		Bureaucrat b("Chirac", 10);
		b.signAForm(*f);
		b.executeForm(*f);
		delete f;
	
		AForm *f1 = i.makeForm("test", "Error");
		std::cout << f1->getName();
	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}