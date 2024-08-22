#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("shrubbery", target, 145, 137) {
	std::cout << "ShrubberyCreationForm constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src.getName(), src.getTarget(), src.getSignGrade(), src.getExecGrade()) {
	*this = src;
	std::cout << "ShrubberyCreationForm copy created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	(void)rhs;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (this->isSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::ofstream file(this->getTarget() + "_shrubbery");
	file << "		&&& &&  & &&" << std::endl;
	file << "	&& &\\/&\\|& ()|/ @, &&" << std::endl;
	file << "	&\\/(/&/&||/& /_/)_&/_&" << std::endl;
	file << "&() &\\/&|()|/&\\/ '%' & ()" << std::endl;
	file << "&_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	file << "()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	file << "	&&     \\|||" << std::endl;
	file << "			|||" << std::endl;
	file << "			|||" << std::endl;
	file << "			|||" << std::endl;
	file << "	, -=-~  .-^- _" << std::endl;
	file << std::endl;
	file << "├── bin" << std::endl;
	file << "├── boot" << std::endl;
	file << "│   └── grub" << std::endl;
	file << "│       ├── fonts" << std::endl;
	file << "│       └── locale" << std::endl;
	file << "├── cdrom" << std::endl;
	file << "└── dev" << std::endl;
	file << "	├── block" << std::endl;
	file << "	├── bsg" << std::endl;
	file << "	└── bus" << std::endl;
	file << "		└── usb" << std::endl;
	file << "			├── 001" << std::endl;
	file << "			└── 002" << std::endl;
	file.close();
}