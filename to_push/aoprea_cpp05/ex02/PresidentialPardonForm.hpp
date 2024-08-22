#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
		void execute(const Bureaucrat&) const;
};