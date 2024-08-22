#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>
#include <map>

class Intern
{
	private:

	public:
		Intern();
		Intern(std::string name, std::string target, int sign_grade, int exec_grade);
		Intern(const Intern& src);
		~Intern();
		Intern& operator=(const Intern& rhs);
		AForm* makeForm(std::string name, std::string target);
};
