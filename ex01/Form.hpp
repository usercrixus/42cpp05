#ifndef FORM
#define FORM

#include <string>
#include <ostream>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _signRequiredGrade;
		const int _executeRequiredGrade;
	public:
		Form();
		Form(std::string name, int reqSignGrade, int reqExecGrade);
		Form(const Form &cpy);
		~Form();
		Form &operator=(const Form &cpy);

		bool beSigned(Bureaucrat& b);

		const std::string getName() const;
		bool getIsSigned() const;
		int getSignRequiredGrade() const;
		int getExecuteRequiredGrade() const;

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif