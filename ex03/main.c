#include "Intern.hpp"

int	main()
{
	Intern		intern;
	AForm		*form1;
	AForm		*form2;
	Bureaucrat	person("person", 1);

	form1 = intern.makeForm("shrubbery creation", "tar");
	try
	{
		form2 = intern.makeForm("hihi", "tar");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << form1->getTarget() << std::endl;

	try
	{
		person.signForm(form1);
		person.executeForm(*form1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete form1;
}