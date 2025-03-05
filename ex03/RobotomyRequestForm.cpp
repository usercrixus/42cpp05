#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
AForm("RobotomyRequestForm", 72, 45),
_target("target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("RobotomyRequestForm", 72, 45),
_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy):
AForm(cpy)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	(void)cpy;
	return *this;
}

int RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    static int x = 0;
    if (!getIsSigned())
        throw AForm::UnsignedForm();
    if (executor.getGrade() > this->getExecuteRequiredGrade())
        throw AForm::GradeTooLowException();
    std::cout << "drilling noises" << std::endl;
    if (x % 2)
        std::cout << _target << " has been robotomized successfully\n" << std::endl;
    else
        std::cout << _target << " robotomy failed" << std::endl;
    x++;
    return (1);
}
