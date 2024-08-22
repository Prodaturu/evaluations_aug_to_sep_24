/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays_in_classes_1.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:39:15 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/21 12:21:07 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Person
{
	private:
		std::string _name;
		int 		_age;

	public:
		void	set_name(std::string name)
		{
			_name = name;
		}

		void	set_age(int age)
		{
			_age = age;
		}

		void	display_info() const
		{
			std::cout << "Name: " << _name << std::endl;
			std::cout << "Birth Year: " << _age << std::endl;
		}

		void	display_info(std::string message)
		const
		{
			std::cout << message << std::endl;
			display_info();
		}
};

class	GroupOfPeople
{
	private:
		Person	_members[5]; // Array of Person Objects that 
		int		_member_count;

	public:

		// --- --- --- Constructors --- --- --- //

		// This constructor initializes the _member_count to 0
		// as soon as a 'GroupOfPeople' object is created
		GroupOfPeople() : _member_count(0)
		{
			// I don't need to do anything here
			// So I just leave it empty
		};
		
		// the above code is equivalent to the following code
		// GroupOfPeople()
		// {
		// _member_count = 0;
		// }
		// or GroupOfPeople() : _member_count(0) {}

		void	add_person(Person new_person)
		{
			if (_member_count < 5)
			{
				_members[_member_count] = new_person;
				_member_count++;
			}
			else
				std::cout << "Group full!" << std::endl;
		};
		
		void	display_group_members()
		const
		{
			int i = 0;

			while (i < _member_count)
			{
				if (_member_count > 0 && i == 0)
				{
					std::cout << std::endl << "Group Members: " << std::endl << std::endl;
					
				}
				_members[i].display_info();
				std::cout << std::endl;
				i++;
			}
		}
};

int	main(void)
{
	Person		Jaggy;
	Person		Özgen;
	Person		Tomek;

	Jaggy.set_name("Jaggy");
	Jaggy.set_age(30);

	Özgen.set_name("Özgen");
	Özgen.set_age(25);

	Tomek.set_name("Tomek");
	Tomek.set_age(31);

	GroupOfPeople	Piscine;

	Piscine.add_person(Jaggy);
	Piscine.add_person(Özgen);
	Piscine.add_person(Tomek);

	Piscine.display_group_members();
}

// class Contact {
// 	private:
// 		std::string firstName;
// 		std::string lastName;

// 	public:
// 		// Constructor
// 		Contact(std::string fName, std::string lName) : firstName(fName), lastName(lName) {
// 			std::cout << "Contact created: " << firstName << " " << lastName << std::endl;
// 		}

// 		// Destructor
// 		~Contact() {
// 			std::cout << "Contact destroyed: " << firstName << " " << lastName << std::endl;
// 		}

// 		void displayContact() {
// 			std::cout << "Name: " << firstName << " " << lastName << std::endl;
// 		}
// };

// class PhoneBook {
// 	private:
// 		Contact Contact[8];  // Array of Contact objects
// 		int contactCount;

// 	public:
// 		PhoneBook() : contactCount(0) {}

// 		void addContact(Contact newContact) {
// 			if (contactCount < 8) {
// 				Contact[contactCount] = newContact;
// 				contactCount++;
// 			} else {
// 				std::cout << "PhoneBook is full!" << std::endl;
// 			}
// 		}

// 		void displayContact() {
// 			for (int i = 0; i < contactCount; i++) {
// 				Contact[i].displayContact();
// 			}
// 		}
// };


// class Person
// {
// 	private:
// 		std::string _name;
// 		int 		_age;

// 	public:
// 		void setName(std::string name) {
// 			_name = name;
// 		}

// 		void setage(int age) {
// 			_age = age;
// 		}

// 		void displayInfo() {
// 			std::cout << "Name: " << _name << std::endl;
// 			std::cout << "Birth Year: " << _age << std::endl;
// 		}

// 		void displayInfo(std::string message) {
// 			std::cout << message << std::endl;
// 			displayInfo();
// 		}
// }

// int	main(void)
// {
// 	Person person1;

// 	person1.setName("Jackie Chan");

// 	person1.setage(1954);

// 	person1.displayInfo("Person 1 Info: ");
// }
