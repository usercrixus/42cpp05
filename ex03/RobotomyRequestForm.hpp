#ifndef Rob
#define Rob

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

class RobotomyRequestForm: public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm(/* args */);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &cpy);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);

	virtual int execute(Bureaucrat const & executor) const;
};

#endif