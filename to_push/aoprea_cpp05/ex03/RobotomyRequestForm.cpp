#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("robotomy", target, 72, 45) {
	std::cout << "RobotomyRequestForm constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src.getName(), src.getTarget(), src.getSignGrade(), src.getExecGrade()) {
	*this = src;
	std::cout << "RobotomyRequestForm copy created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	(void)rhs;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (this->isSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized succesfully" << std::endl;
	else
		std::cout << "Robotomy of " << this->getTarget() << " failed" << std::endl;
}