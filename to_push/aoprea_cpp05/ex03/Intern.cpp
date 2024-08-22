#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern constructed" << std::endl;
}

Intern::Intern(const Intern& src) {
	*this = src;
	std::cout << "Intern copy created" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructed" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) {
	AForm* form = nullptr;
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*    forms[] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };
	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			form = forms[i];
			std::cout << "Intern creates " << name << std::endl;
		} else {
			delete forms[i];
		}
	}
	if (form == NULL)
		std::cout << "Intern cannot create form " << name << std::endl;
	return form;
} 	
