#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): _target("target")
{
	this->setSignGrade(25);
	this->setExecuteGrade(5);
	this->setSign(false);
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
{
	this->_target = target;
	this->setSignGrade(145);
	this->setExecuteGrade(137);
	this->setSign(false);

	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj)
{
	this->_target = obj._target;
	this->setName(obj.getName());
	this->setSign(obj.getSign());
	this->setSignGrade(obj.getSignGrade());
	this->setExecuteGrade(obj.getExecuteGrade());

	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (this != &obj)
	{
		this->_target = obj._target;
		this->setSignGrade(obj.getSignGrade());
		this->setExecuteGrade(obj.getExecuteGrade());
		this->setSign(obj.getSign());
	}

	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!(this->getSign()))
	{
		std::cout << "this is not signed" << std::endl;
		throw (PresidentialPardonForm::IsNotSignedException());
	}
	else if (5 < executor.getGrade())
	{
		std::cout << "Permission denied" << std::endl;
		throw (PermissionDeniedException());
	}

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
