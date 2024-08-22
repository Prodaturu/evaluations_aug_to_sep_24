#pragma once

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		const int sign_grade;
		const int exec_grade;
		bool is_signed;
		Form();

	public:
		Form(std::string name, int sign_grade, int exec_grade);
		Form(const Form& src);
		~Form();
		Form& operator=(const Form& rhs);
		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;
		void beSigned(Bureaucrat&);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, Form& b);