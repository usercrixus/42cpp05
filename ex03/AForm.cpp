#include "AForm.hpp"

AForm::AForm():
_name(""),
_isSigned(false),
_signRequiredGrade(150),
_executeRequiredGrade(150)
{
	if (_signRequiredGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signRequiredGrade > 150)
		throw AForm::GradeTooLowException();
	if (_executeRequiredGrade < 1)
		throw AForm::GradeTooHighException();
	if (_executeRequiredGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int reqSignGrade, int reqExecGrade):
_name(name),
_signRequiredGrade(reqSignGrade),
_executeRequiredGrade(reqExecGrade)
{
}

AForm::AForm(const AForm &cpy):
_name(cpy._name),
_isSigned(cpy._isSigned),
_signRequiredGrade(cpy._signRequiredGrade),
_executeRequiredGrade(cpy._executeRequiredGrade)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &cpy)
{
	(void)cpy;
	return *this;
}

bool AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= _signRequiredGrade)
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
	return true;
}

const std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getSignRequiredGrade() const
{
	return _signRequiredGrade;
}

int AForm::getExecuteRequiredGrade() const
{
	return _executeRequiredGrade;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::UnsignedForm::what() const throw()
{
	return "Unsigned form";
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "Name: " << f.getName();
	os << "\nis signed: " << f.getIsSigned();
	os << "\nsign required grade: " << f.getSignRequiredGrade();
	os << "\nexecute required grade: " << f.getExecuteRequiredGrade();
	os << "\n";
	return os;
}
