#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): _target("target")
{
	this->setSignGrade(145);
	this->setExecuteGrade(137);
	this->setSign(false);
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
{
	this->_target = target;
	this->setSignGrade(145);
	this->setExecuteGrade(137);
	this->setSign(false);

	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
{
	this->_target = obj._target;
	this->setSignGrade(obj.getSignGrade());
	this->setExecuteGrade(obj.getExecuteGrade());
	this->setSign(obj.getSign());

	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this != &obj)
	{
		this->_target = obj._target;
		this->setSignGrade(obj.getSignGrade());
		this->setExecuteGrade(obj.getExecuteGrade());
		this->setSign(obj.getSign());
	}

	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (137 < executor.getGrade())
	{
		throw (PermissionDeniedException());
	}
	else
	{
		std::ofstream out(executor.getName() + "_shrubbery");

		std::string	s = "";

		if (out.is_open())
		{
			out << s;
		}
	}
}