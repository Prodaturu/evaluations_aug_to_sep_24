#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
		void execute(const Bureaucrat&) const;
};