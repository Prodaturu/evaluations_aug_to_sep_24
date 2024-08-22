#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
	} catch (AForm::GradeTooLowException e) {
		std::cerr << this->name << " could not sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
	} catch (AForm::NotSignedException e) {
		std::cerr << this->name << " could not execute form " << form.getName() << " because " << e.what() << std::endl;
		return ;
	} catch (AForm::GradeTooLowException e) {
		std::cerr << this->name << " could not execute form " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->name << " executed " << form.getName() << std::endl;

}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "gade too low";
}