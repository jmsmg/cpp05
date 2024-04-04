#include "Form.hpp"

Form::Form(): _name("default"), _sign(false), _required_grade(150), _execute_grade(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const std::string name, const bool sign, const int required_grade, const int execute_grade)
{
	if (150 < required_grade || 150 < execute_grade)
	{
		throw (Form::GradeTooLowException());
	}
	else if(required_grade < 1 || execute_grade < 1)
	{
		throw (Form::GradeTooHighException());
	}
	this->_name = name;
	this->_sign = sign;
	this->_required_grade = required_grade;
	this->_execute_grade = execute_grade;
}

Form::Form(const Form &obj)
{
	this->_name = obj.getName();
	this->_sign = obj.getSign();
	this->_required_grade = obj.getRequiredGrade();
	this->_execute_grade = obj.getExecuteGrade();

	std::cout << "Form copy constructor called" << std::endl;
}

Form	&Form::operator=(const Form &obj)
{
	if (this != &obj)
	{
		this->_name = obj.getName();
		this->_sign = obj.getSign();
		this->_required_grade = obj.getRequiredGrade();
		this->_execute_grade = obj.getExecuteGrade();
	}
		std::cout << "Form copy assignment operator called" << std::endl;
	return (*this);
}

Form::~Form(){}

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSign() const
{
	return (this->_sign);
}

int		Form::getRequiredGrade() const
{
	return (this->_required_grade);
}

int		Form::getExecuteGrade() const
{
	return (this->_execute_grade);
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("error : Form GradeTooHighException");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("error : Form GradeTooLowException");
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_required_grade < bureaucrat.getGrade())
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->_name
		<< " because grade too low" << std::endl;
		throw (Form::GradeTooLowException());
	}
	else
	{
		this->_sign = true;
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, const Form &obj)
{
	out << obj.getName() << ", Form sign " << std::boolalpha << obj.getSign() << ", Form required grade "
	<< obj.getRequiredGrade() << ", Form execute grade " << obj.getExecuteGrade();
	return (out);
}