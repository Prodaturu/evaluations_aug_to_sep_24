#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern guy;
	AForm* form;
	std::cout << std::endl;

	form = guy.makeForm("shrubbery creation", "plant room");
	delete form;
	std::cout << std::endl;
	guy.makeForm("payment agreement", "salary");
	std::cout << std::endl;
}