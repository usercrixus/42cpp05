#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat b("Chirac", 10);
	PresidentialPardonForm pd;
	RobotomyRequestForm rq;
	ShrubberyCreationForm sc;
	b.signAForm(pd);
	b.executeForm(pd);
	b.signAForm(rq);
	b.executeForm(rq);
	b.signAForm(sc);
	b.executeForm(sc);

	return (0);
}