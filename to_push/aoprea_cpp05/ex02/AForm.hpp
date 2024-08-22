#pragma once

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string name;
		const std::string target;
		const int sign_grade;
		const int exec_grade;
		bool is_signed;
		AForm();

	public:
		AForm(std::string name, std::string target, int sign_grade, int exec_grade);
		AForm(const AForm& src);
		~AForm();
		AForm& operator=(const AForm& rhs);
		std::string getName() const;
		std::string getTarget() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;
		void beSigned(Bureaucrat&);
		virtual void execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, AForm& b);