#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

#include "../Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private:
		std::string	_name;
		bool		_sign;
		int			_sign_grade;
		int			_execute_grade;

		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	protected:
		class	PermissionDeniedException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class	IsNotSignedException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

	public:
		AForm();
		AForm(const std::string name, const bool sign, const int sign_grade, const int execute_grade);
		AForm(const AForm &obj);
		AForm	&operator=(const AForm &obj);
		~AForm();

		std::string	getName() const;
		bool		getSign() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		void		setName(const std::string name);
		void		setSign(const bool &sign);
		void		setSignGrade(const int &sign_grade);
		void		setExecuteGrade(const int execute_grade);

		void		beSigned(const Bureaucrat &bureaucrat);

		virtual	void	execute(Bureaucrat const &executor) const = 0;

};

std::ostream	&operator<<(std::ostream &out, const AForm &obj);

#endif