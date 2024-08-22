#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) {
	if (src.grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (src.grade > 150)
		throw Bureaucrat::GradeTooLowException();
	*this = src;
	std::cout << "Bureaucrat copy created" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (rhs.grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (rhs.grade > 150)
		throw Bureaucrat::GradeTooLowException();
	grade = rhs.grade;
	return *this;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat& b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}

int	Bureaucrat::getGrade() const {
	return this->grade;
}

std::string	Bureaucrat::getName() const {
	return this->name;
}

void Bureaucrat::incrementGrade() {
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	this->grade++;
}

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
	} catch (Form::GradeTooLowException e) {
		std::cerr << this->name << " could not sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->name << " signed " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "gade too low";
}