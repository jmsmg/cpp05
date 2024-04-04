#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	person("person", 10);
	Form		form1("form1", false, 10, 10);
	Form		form2("form2", false, 10, 10);

	std::cout << "-------------- ok test -----------------" << std::endl;
	person.signForm(&form1);

	std::cout << std::endl;

	std::cout << "-------------- error test -----------------" << std::endl;
	person.decreaseGrade();
	try
	{
		person.signForm(&form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "-------------- operator overloading test -----------------" << std::endl;
	std::cout << form1 << std::endl;
}