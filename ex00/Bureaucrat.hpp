#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <stdexcept>

class	Bureaucrat
{
	private:
		int					_grade;
		const std::string	_name;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &clone);
		ostream operator<<(const Bureaucrat &clone);

		~Bureaucrat();

		std::string	getName();
		int			getGrade();
		void		increseGrade();
		void		decreseGrade();

};

#endif