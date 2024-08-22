#include "AForm.hpp"

AForm::AForm(std::string name, std::string target, int sign_grade, int exec_grade) : name(name), target(target), sign_grade(sign_grade), exec_grade(exec_grade) {
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Form constructed" << std::endl;
}

AForm::AForm(const AForm& src) : name(src.name), target(src.target), sign_grade(src.sign_grade), exec_grade(src.exec_grade), is_signed(src.is_signed) {
	if (src.sign_grade < 1 || src.exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (src.sign_grade > 150 || src.exec_grade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Form copy created" << std::endl;
}

AForm::~AForm() {
	std::cout << "Form destructed" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs) {
	if (rhs.sign_grade < 1 || rhs.exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (rhs.sign_grade > 150 || rhs.exec_grade > 150)
		throw AForm::GradeTooLowException();
	this->is_signed = rhs.is_signed;
	return *this;
}

std::ostream& operator<<(std::ostream& o, AForm& b) {
	o << "Form name:     " << b.getName() << "\nSign grade:    " << b.getSignGrade() << "\nExecute grade: " << b.getExecGrade() << "\nSigned:        ";
	if (b.isSigned())
		o << "Yes";
	else
		o << "No";
	return o;
}

int	AForm::getSignGrade() const {
	return this->sign_grade;
}

int	AForm::getExecGrade() const {
	return this->exec_grade;
}

std::string	AForm::getName() const {
	return this->name;
}

std::string	AForm::getTarget() const {
	return this->target;
}

bool AForm::isSigned() const {
	return this->is_signed;
}

void AForm::beSigned(Bureaucrat& b) {
	if (this->sign_grade < b.getGrade())
		throw AForm::GradeTooLowException();
	this->is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
	return "form not signed";
}