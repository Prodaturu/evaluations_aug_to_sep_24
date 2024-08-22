#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Joe", 1);

	std::cout << b << std::endl;

	try {
		Bureaucrat a(b);
	} catch (Bureaucrat::GradeTooHighException e) {
		std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException e) {
		std::cerr << e.what() << std::endl;
	}

	b.incrementGrade();
	std::cout << std::endl;

	try {
		Bureaucrat a = b;
	} catch (Bureaucrat::GradeTooHighException e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		Bureaucrat a("Bob", 151);
	} catch (Bureaucrat::GradeTooLowException e) {
		std::cerr << e.what() << std::endl;
	}
}