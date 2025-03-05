#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <string>
#include <ostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(/* args */);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat &operator=(const Bureaucrat& cpy);
		~Bureaucrat();

		void incrementGrade();
		void decrementGrade();
		void signAForm(AForm& f);
		void executeForm(AForm const & form);

		std::string getName() const;
		int getGrade() const;

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
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif