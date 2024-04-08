#ifndef INTERN_HPP
#define INTERN_HPP

#include "./Form/PresidentialPardonForm.hpp"
#include "./Form/RobotomyRequestForm.hpp"
#include "./Form/ShrubberyCreationForm.hpp"

enum e_form
{
	SHRUBBERYCREATIONFORM,
	ROBOTOMYREQUESTFORM,
	PRESIDENTIALPARDONFORM
};

class	Intern
{
	private:
		class	DoesNotExistException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	public:
		Intern();
		Intern(const Intern &intern);
		Intern &operator=(const Intern &intern);
		~Intern();
		AForm	*makeForm(const std::string &form_name, const std::string &form_target);
};

#endif