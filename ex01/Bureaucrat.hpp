#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "Form.hpp"

class	Form;

class	Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &clone);
		Bureaucrat	&operator=(const Bureaucrat &bureaucrat);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		increaseGrade();
		void		decreaseGrade();
		void		signForm(Form *form) const;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj);
#endif