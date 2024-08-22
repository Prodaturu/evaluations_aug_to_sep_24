#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
		void execute(const Bureaucrat&) const;
};