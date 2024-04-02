#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	std::cout << Default constructor called << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << constructor called << std::endl;
}

Bureaucrat::(const Bureaucrat &clone)
{
	
}

int			Bureaucrat::getName()
{
	return (this->_grade);
}

std::string	Bureaucrat::getName()
{
	return (this->_name);
}

void		Bureaucrat::increseGrade()
{
	if (this->_grade == 1)
	{
		std::cout << "Can't increse the grade" << std::endl;
	}
	else
	{
		this->_grade--;
		std::cout << "Bruaucrat grade : " << this->_grade + 1 << " -> " << this->_grade << std::endl;
	}
}

void		Bureaucrat::decreseGrade()
{
	if (this->_grade == 150)
	{
		std::cout << "Can't decrese the grade" << std::endl;
	}
	else
	{
		this->_grade++;
		std::cout << "Bruaucrat grade : " << this->_grade - 1 << " -> " << this->_grade << std::endl;
	}
}