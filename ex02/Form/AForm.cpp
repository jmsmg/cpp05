#include "AForm.hpp"

AForm::AForm(): _name("default"), _sign(false), _sign_grade(150), _execute_grade(150)
{
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const bool sign, const int sign_grade, const int execute_grade)
{
	if (150 < sign_grade || 150 < execute_grade)
	{
		throw (AForm::GradeTooLowException());
	}
	else if(sign_grade < 1 || execute_grade < 1)
	{
		throw (AForm::GradeTooHighException());
	}
	this->_name = name;
	this->_sign = sign;
	this->_sign_grade = sign_grade;
	this->_execute_grade = execute_grade;
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &obj)
{
	this->_name = obj.getName();
	this->_sign = obj.getSign();
	this->_sign_grade = obj.getSignGrade();
	this->_execute_grade = obj.getExecuteGrade();

	std::cout << "AForm copy constructor called" << std::endl;
}

AForm	&AForm::operator=(const AForm &obj)
{
	if (this != &obj)
	{
		this->_name = obj.getName();
		this->_sign = obj.getSign();
		this->_sign_grade = obj.getSignGrade();
		this->_execute_grade = obj.getExecuteGrade();
	}
		std::cout << "AForm copy assignment operator called" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSign() const
{
	return (this->_sign);
}

int		AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int		AForm::getExecuteGrade() const
{
	return (this->_execute_grade);
}

void		AForm::setSign(const bool &sign)
{
	this->_sign = sign;
}

void		AForm::setSignGrade(const int &sign_grade)
{
	this->_sign_grade = sign_grade;
}

void		AForm::setExecuteGrade(const int execute_grade)
{
	this->_execute_grade = execute_grade;
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("error : AForm GradeTooHighException");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("error : AForm GradeTooLowException");
}

const char	*AForm::PermissionDeniedException::what(void) const throw()
{
	return ("error : PermissionDeniedException");
}

const char	*AForm::IsNotSignedException::what(void) const throw()
{
	return ("error : IsNotSignedException");
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_sign_grade < bureaucrat.getGrade())
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->_name
		<< " because grade too low" << std::endl;
		throw (AForm::GradeTooLowException());
	}
	else
	{
		this->_sign = true;
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, const AForm &obj)
{
	out << obj.getName() << ", AForm sign " << std::boolalpha << obj.getSign() << ", AForm required grade "
	<< obj.getSignGrade() << ", AForm execute grade " << obj.getExecuteGrade();
	return (out);
}