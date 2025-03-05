#ifndef FORM
#define FORM

#include <string>
#include <ostream>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _signRequiredGrade;
		const int _executeRequiredGrade;
	public:
		AForm();
		AForm(std::string name, int reqSignGrade, int reqExecGrade);
		AForm(const AForm &cpy);
		~AForm();
		AForm &operator=(const AForm &cpy);

		bool beSigned(Bureaucrat& b);
		virtual int execute(Bureaucrat const & executor) const = 0;

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

	class UnsignedForm : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif