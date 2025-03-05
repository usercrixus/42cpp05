#ifndef Inte
#define Inte

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm *makePresident(const std::string target);
		AForm *makeRobot(const std::string target);
		AForm *makeShrubbery(const std::string target);
	public:
		Intern(/* args */);
		~Intern();
		
		AForm *makeForm(std::string formName, std::string target);

		class NotFoundForm : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif