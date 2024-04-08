#include "Bureaucrat.hpp"
#include "Form/PresidentialPardonForm.hpp"
#include "Form/RobotomyRequestForm.hpp"
#include "Form/ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat	person("person", 1);
	Bureaucrat	person2("person2", 150);

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
	std::cout << std::endl;

	std::cout << "-------------- ShrubberyCreationForm test -----------------" << std::endl;
	person.executeForm(*form1);

	std::cout << std::endl;
	std::cout << "-------------- error test -----------------" << std::endl;
	
	person2.executeForm(*form1);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-------------- RobotomyRequestForm test -----------------" << std::endl;
	RobotomyRequestForm robo = RobotomyRequestForm("robo");
	person.signForm(&robo);
	person.executeForm(robo);

	std::cout << std::endl;
	std::cout << "-------------- error test -----------------" << std::endl;
	person2.executeForm(robo);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-------------- PresidentialPardonForm test -----------------" << std::endl;
	PresidentialPardonForm resi = PresidentialPardonForm("resi");
	person.signForm(&resi);
	person.executeForm(resi);

	std::cout << "-------------- error test -----------------" << std::endl;
	person2.executeForm(resi);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-------------- operator overloading test -----------------" << std::endl;
	std::cout << *form1 << std::endl;
}