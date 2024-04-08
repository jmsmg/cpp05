#include "Bureaucrat.hpp"
#include "Form/PresidentialPardonForm.hpp"
#include "Form/RobotomyRequestForm.hpp"
#include "Form/ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat	person("person", 10);
	AForm		*form1 = new ShrubberyCreationForm("home");

	std::cout << "-------------- ok test -----------------" << std::endl;
	person.signForm(form1);

	std::cout << std::endl;

	std::cout << "-------------- error test -----------------" << std::endl;
	person.decreaseGrade();
	try
	{
		person.signForm(form1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "-------------- operator overloading test -----------------" << std::endl;
	std::cout << *form1 << std::endl;
}