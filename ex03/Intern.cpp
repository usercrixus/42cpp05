#include "Intern.hpp"

Intern::Intern(/* args */)
{
}

Intern::~Intern()
{
}
AForm	*Intern::makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

const char *Intern::NotFoundForm::what() const throw()
{
	return "Not found";
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
	AForm* (Intern::*all_forms[])(const std::string) = {
		&Intern::makePresident,
		&Intern::makeRobot,
		&Intern::makeShrubbery
	};
	
	size_t i = 0;
	while (i < 3)
	{
		if (forms[i].compare(formName) == 0)
			break;
		i++;
	}
	if (i < 3)
		return (this->*all_forms[i])(target);
	else
		throw Intern::NotFoundForm();
}
