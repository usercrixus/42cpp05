#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("ShrubberyCreationForm", 145, 137),
_target("target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("ShrubberyCreationForm", 145, 137),
_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy):
AForm(cpy)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	(void)cpy;
	return *this;
}

int ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw AForm::UnsignedForm();
    if (executor.getGrade() > this->getExecuteRequiredGrade())
        throw AForm::GradeTooLowException();
    std::ostringstream oss;  // Create an output string stream
    oss << "   o\n";
    oss << "  ooo\n";
    oss << " ooooo\n";
	std::ofstream outFile(_target.c_str());
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return (0);
    }
    outFile << oss.str();
    outFile.close();
	return (1);
}
