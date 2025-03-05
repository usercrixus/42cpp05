#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

class PresidentialPardonForm: public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm(/* args */);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &cpy);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &cpy);

	virtual int execute(Bureaucrat const & executor) const;
};
