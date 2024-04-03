#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (150 < grade)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	this->_name = bureaucrat._name;
	this->_grade = bureaucrat._grade;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
	{
		this->_name = bureaucrat._name;
		this->_grade = bureaucrat._grade;
		std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	}
	return (*this);

}

Bureaucrat::~Bureaucrat(){}

int			Bureaucrat::getGrade(void)
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
		throw Bureaucrat::GradeTooHighException();
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
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		this->_grade++;
		std::cout << "Bruaucrat grade : " << this->_grade - 1 << " -> " << this->_grade << std::endl;
	}
}

const	char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("")
}