#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
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
	this->_grade = grade;
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

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::increaseGrade()
{
	std::cout << "Bureaucrat increaseGrade function called" << std::endl;
	if (this->_grade == 1)
	{
		throw (Bureaucrat::GradeTooHighException());
	}
	else
	{
		this->_grade--;
		std::cout << "Bruaucrat grade : " << this->_grade + 1 << " -> " << this->_grade << std::endl;
	}
}

void	Bureaucrat::decreaseGrade()
{
	if (this->_grade == 150)
	{
		throw (Bureaucrat::GradeTooLowException());
	}
	else
	{
		this->_grade++;
		std::cout << "Bruaucrat grade : " << this->_grade - 1 << " -> " << this->_grade << std::endl;
	}
}

const	char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Error : Grade too high");
}

const	char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Error : Grade too Low");
}

void	Bureaucrat::signForm(AForm *form) const
{
	if (form->getSign())
	{
		std::cout << "already signed" << std::endl;
	}
	else
	{
		form->beSigned(*this);
	}
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (out);
}