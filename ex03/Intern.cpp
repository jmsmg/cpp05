#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern &intern)
{
	Intern a = intern;

	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &intern)
{
	Intern a = intern;
	std::cout << "Intern operator assignment called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm	*Intern::makeForm(const std::string &form_name, const std::string &form_target)
{
	int			i = 0;
	AForm		*form = NULL;
	std::string	form_type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	while (i < 3)
	{
		if (form_type[i] == form_name)
		{
			break;
		}
		i++;
	}

	switch (i)
	{
		case SHRUBBERYCREATIONFORM:
			form = new ShrubberyCreationForm(form_target);
			break;

		case ROBOTOMYREQUESTFORM:
			form = new RobotomyRequestForm(form_target);
			break;
	
		case PRESIDENTIALPARDONFORM:		
			form = new PresidentialPardonForm(form_target);
			break;
		default:
			throw(DoesNotExistException());
	}

	return (form);
}

const char *Intern::DoesNotExistException::what(void) const throw()
{
	return ("Error : does not exist exception");
}