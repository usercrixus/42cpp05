#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(/* args */):
_name(""),
_grade(1)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade):
_name(name),
_grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy):
_name(cpy._name),
_grade(cpy._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &cpy)
{
	this->_grade = cpy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::incrementGrade()
{
	_grade++;
	if (_grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	_grade--;
	if (_grade < 1)
		throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
	return os;
}

void Bureaucrat::signAForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
