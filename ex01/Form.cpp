#include "Form.hpp"

Form::Form():
_name(""),
_isSigned(false),
_signRequiredGrade(150),
_executeRequiredGrade(150)
{
	if (_signRequiredGrade < 1)
		throw Form::GradeTooHighException();
	if (_signRequiredGrade > 150)
		throw Form::GradeTooLowException();
	if (_executeRequiredGrade < 1)
		throw Form::GradeTooHighException();
	if (_executeRequiredGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string name, int reqSignGrade, int reqExecGrade):
_name(name),
_signRequiredGrade(reqSignGrade),
_executeRequiredGrade(reqExecGrade)
{
}

Form::Form(const Form &cpy):
_name(cpy._name),
_isSigned(cpy._isSigned),
_signRequiredGrade(cpy._signRequiredGrade),
_executeRequiredGrade(cpy._executeRequiredGrade)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &cpy)
{
	(void)cpy;
	return *this;
}

bool Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= _signRequiredGrade)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
	return true;
}

const std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getSignRequiredGrade() const
{
	return _signRequiredGrade;
}

int Form::getExecuteRequiredGrade() const
{
	return _executeRequiredGrade;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Name: " << f.getName();
	os << "\nis signed: " << f.getIsSigned();
	os << "\nsign required grade: " << f.getSignRequiredGrade();
	os << "\nexecute required grade: " << f.getExecuteRequiredGrade();
	os << "\n";
	return os;
}
