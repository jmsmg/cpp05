#include "AForm.hpp"

AForm::AForm(): _name("default"), _sign(false), _required_grade(150), _execute_grade(150)
{
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const bool sign, const int required_grade, const int execute_grade)
{
	if (150 < required_grade || 150 < execute_grade)
	{
		throw (AForm::GradeTooLowException());
	}
	else if(required_grade < 1 || execute_grade < 1)
	{
		throw (AForm::GradeTooHighException());
	}
	this->_name = name;
	this->_sign = sign;
	this->_required_grade = required_grade;
	this->_execute_grade = execute_grade;
}

AForm::AForm(const AForm &obj)
{
	this->_name = obj.getName();
	this->_sign = obj.getSign();
	this->_required_grade = obj.getRequiredGrade();
	this->_execute_grade = obj.getExecuteGrade();

	std::cout << "AForm copy constructor called" << std::endl;
}

AForm	&AForm::operator=(const AForm &obj)
{
	if (this != &obj)
	{
		this->_name = obj.getName();
		this->_sign = obj.getSign();
		this->_required_grade = obj.getRequiredGrade();
		this->_execute_grade = obj.getExecuteGrade();
	}
		std::cout << "AForm copy assignment operator called" << std::endl;
	return (*this);
}

AForm::~AForm(){}

std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSign() const
{
	return (this->_sign);
}

int		AForm::getRequiredGrade() const
{
	return (this->_required_grade);
}

int		AForm::getExecuteGrade() const
{
	return (this->_execute_grade);
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("error : AForm GradeTooHighException");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("error : AForm GradeTooLowException");
}

// void	AForm::beSigned(const Bureaucrat &bureaucrat)
// {
// 	if (this->_required_grade < bureaucrat.getGrade())
// 	{
// 		std::cout << bureaucrat.getName() << " couldn't sign " << this->_name
// 		<< " because grade too low" << std::endl;
// 		throw (AForm::GradeTooLowException());
// 	}
// 	else
// 	{
// 		this->_sign = true;
// 		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
// 	}
// }

std::ostream	&operator<<(std::ostream &out, const AForm &obj)
{
	out << obj.getName() << ", AForm sign " << std::boolalpha << obj.getSign() << ", AForm required grade "
	<< obj.getRequiredGrade() << ", AForm execute grade " << obj.getExecuteGrade();
	return (out);
}