#include "Form.hpp"

Form::Form(std::string name, int sign_grade, int exec_grade) : name(name), sign_grade(sign_grade), exec_grade(exec_grade) {
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructed" << std::endl;
}

Form::Form(const Form& src) : name(src.name), sign_grade(src.sign_grade), exec_grade(src.exec_grade), is_signed(src.is_signed) {
	if (src.sign_grade < 1 || src.exec_grade < 1)
		throw Form::GradeTooHighException();
	if (src.sign_grade > 150 || src.exec_grade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form copy created" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructed" << std::endl;
}

Form& Form::operator=(const Form& rhs) {
	if (rhs.sign_grade < 1 || rhs.exec_grade < 1)
		throw Form::GradeTooHighException();
	if (rhs.sign_grade > 150 || rhs.exec_grade > 150)
		throw Form::GradeTooLowException();
	this->is_signed = rhs.is_signed;
	return *this;
}

std::ostream& operator<<(std::ostream& o, Form& b) {
	o << "Form name:     " << b.getName() << "\nSign grade:    " << b.getSignGrade() << "\nExecute grade: " << b.getExecGrade() << "\nSigned:        ";
	if (b.isSigned())
		o << "Yes";
	else
		o << "No";
	return o;
}

int	Form::getSignGrade() const {
	return this->sign_grade;
}

int	Form::getExecGrade() const {
	return this->exec_grade;
}

std::string	Form::getName() const {
	return this->name;
}

bool Form::isSigned() const {
	return this->is_signed;
}

void Form::beSigned(Bureaucrat& b) {
	if (this->sign_grade < b.getGrade())
		throw Form::GradeTooLowException();
	this->is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade too low";
}