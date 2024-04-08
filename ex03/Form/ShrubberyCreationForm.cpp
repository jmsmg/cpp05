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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj)
{
	this->_target = obj._target;
	this->setName(obj.getName());
	this->setSign(obj.getSign());
	this->setSignGrade(obj.getSignGrade());
	this->setExecuteGrade(obj.getExecuteGrade());

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

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!(this->getSign()))
	{
		std::cout << "this is not signed" << std::endl;
		throw (ShrubberyCreationForm::IsNotSignedException());
	}
	else if (137 < executor.getGrade())
	{
		std::cout << "Permission denied" << std::endl;
		throw (PermissionDeniedException());
	}

	std::string		filename = executor.getName() + "_shrubbery";
	std::ofstream	outfile(filename.c_str(), std::ios::out);

	if (outfile.is_open())
	{
		outfile << "       /_-_\\\n";
		outfile << "    /~~    ~~\\\n";
		outfile << "  /~~         ~~\\\n";
		outfile << " {               }\n";
		outfile << " \\\\  _-     -_  /\n";
		outfile << "    ~  \\\\ //  ~\n";
		outfile << " _- -   | | _- _\n";
		outfile << "   _ -  | |   -_\n";
		outfile << "       // \\\\";
	}
}