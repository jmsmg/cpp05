#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <stdexcept>

class	Bureaucrat
{
	private:
		int					_grade;
		std::string	_name;
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

		std::string	getName();
		int			getGrade();
		void		increseGrade();
		void		decreseGrade();

};

#endif

ostream operator<<(const Bureaucrat &clone);

