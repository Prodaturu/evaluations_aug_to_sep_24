#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat arthur("Arthur Dent", 100);
	Bureaucrat vogon("Prostetnic Vogon Jeltz", 26);
	Bureaucrat zaphod("Zaphod Beeblebrox", 1);
	std::cout << std::endl;

	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("Marvin");
	PresidentialPardonForm pardon("Ford Prefect");
	std::cout << std::endl;

	arthur.executeForm(shrubbery);
	arthur.signForm(shrubbery);
	arthur.executeForm(shrubbery);
	std::cout << std::endl;

	vogon.signForm(robotomy);
	vogon.executeForm(robotomy);
	vogon.signForm(pardon);
	vogon.incrementGrade();
	vogon.signForm(pardon);
	std::cout << std::endl;

	zaphod.executeForm(pardon);
	std::cout << std::endl;
}