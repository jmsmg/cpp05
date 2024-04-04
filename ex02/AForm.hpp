#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>
#include <string>
#include <stdexcept>

#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private:
		std::string	_name;
		bool		_sign;
		int			_required_grade;
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
		AForm();
		AForm(const std::string name, const bool sign, const int required_grade, const int execute_grade);
		AForm(const AForm &obj);
		AForm	&operator=(const AForm &obj);
		~AForm();

		std::string	getName() const;
		bool		getSign() const;
		int			getRequiredGrade() const;
		int			getExecuteGrade() const;

		virtual void	beSigned(const Bureaucrat &bureaucrat) = 0;
};

std::ostream	&operator<<(std::ostream &out, const AForm &obj);

#endif