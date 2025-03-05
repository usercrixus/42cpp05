#ifndef Shru
#define Shru

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

class ShrubberyCreationForm: public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm(/* args */);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);

	virtual int execute(Bureaucrat const & executor) const;
};

#endif