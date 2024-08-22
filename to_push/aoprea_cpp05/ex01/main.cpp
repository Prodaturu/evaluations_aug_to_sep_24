#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b("Joe", 51);
	Form f("Form", 50, 30);
	std::cout << std::endl;

	std::cout << f << std::endl;
	b.signForm(f);
	b.incrementGrade();
	b.signForm(f);
	std::cout << std::endl;
}