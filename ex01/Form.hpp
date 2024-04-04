#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include <stdexcept>

#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		std::string	_name;
		bool		_sign;
		int			_sign_grade;
		int			_execute_grade;

		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	public:
		Form();
		Form(const std::string name, const bool sign, const int sign_grade, const int execute_grade);
		Form(const Form &obj);
		Form	&operator=(const Form &obj);
		~Form();

		std::string	getName() const;
		bool		getSign() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		void	beSigned(const Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream &out, const Form &obj);

#endif