#include "Bureaucrat.hpp"

int	main()
{
	
	std::cout << "--------- too high exception test -------" << std::endl;
	Bureaucrat	person1("seonggoc", 1);

	try
	{
		person1.increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "-----------------------" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--------- too low exception test -------" << std::endl;
	Bureaucrat	person2("tmp", 150);

	try
	{
		person2.decreaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "-----------------------" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--------- ok test -----------" << std::endl;

	Bureaucrat	person3("cadet", 100);

	try
	{
		person3.decreaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "-----------------------" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--------- ok test -----------" << std::endl;

	Bureaucrat	person4("cadet2", 100);

	try
	{
		person4.increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "-----------------------" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << person1 << std::endl;
	std::cout << person2 << std::endl;
	std::cout << person3 << std::endl;
	std::cout << person4 << std::endl;
}