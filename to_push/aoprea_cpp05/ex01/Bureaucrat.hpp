#pragma once

#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		Bureaucrat();

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rhs);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, Bureaucrat& b);