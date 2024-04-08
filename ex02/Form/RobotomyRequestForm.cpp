#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): _target("target")
{
	this->setSignGrade(72);
	this->setExecuteGrade(45);
	this->setSign(false);
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
{
	this->_target = target;
	this->setSignGrade(145);
	this->setExecuteGrade(137);
	this->setSign(false);

	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
	this->_target = obj._target;
	this->setName(obj.getName());
	this->setSign(obj.getSign());
	this->setSignGrade(obj.getSignGrade());
	this->setExecuteGrade(obj.getExecuteGrade());

	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this != &obj)
	{
		this->_target = obj._target;
		this->setSignGrade(obj.getSignGrade());
		this->setExecuteGrade(obj.getExecuteGrade());
		this->setSign(obj.getSign());
	}

	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!(this->getSign()))
	{
		std::cout << "this is not signed" << std::endl;
		throw (RobotomyRequestForm::IsNotSignedException());
	}
	else if (45 < executor.getGrade())
	{
		std::cout << "Permission denied" << std::endl;
		throw (PermissionDeniedException());
	}

	std::cout << "ddrrrrrill noise" << std::endl;

	std::srand(std::time(NULL));

	if (rand() % 2)
	{
		std::cout << this->_target << " fail robotomized" << std::endl;
		return ;
	}
	std::cout << this->_target << " succeed robotomized" << std::endl;
}