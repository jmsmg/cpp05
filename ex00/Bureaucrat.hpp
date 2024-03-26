#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <stdexcept>

class	Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &clone);
		operator=(const Bureaucrat &clone);
		ostream operator<<(const Bureaucrat &clone);

		~Bureaucrat();

		std::string	getName();
		int			getGrade();
		void		incrementGrade();
		void		decrementGrade();

};

#endif