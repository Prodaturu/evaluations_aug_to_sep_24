/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_modifiers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:57:14 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/18 11:48:49 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Exercise:
 * 
 * Modify your Car class so that the attributes make, model, and year are private.
 * Add public setter and getter methods to modify and access these attributes.
 * Test the setters and getters in main().
 */

#include <iostream>

// class definition

class	Car
{

	private:
		std::string	make;
		std::string	model;
		std::string	year;

	public:
		void	displayCarInfo()
		{
			std::cout << "Car Make : " << make << "\t Model : " << model << "\t Year : " << year << std::endl;
		};

		// --- --- --- Setters / setter methods --- --- ---

		//* 'this' is a constant pointer holding memory address of current object.
		//* So, it is optional to use 'this'pointer to access class members.
		//* The advantage is it can be used to resolve variable ambiguity.
		//* For ex:
			//* If we have a local var with same name as a class member var,
				//* then we can use 'this' pointer to access class member var.
			//* So it is not mandatory to use 'this' pointer for accessing class members
				//* but a precautionary measure to avoid ambiguity
				//* and hence make code more readable.
		
		void 	setMakeTwo(std::string str)
		{
			make = str;
		};
		
		void	setMake(std::string make)
		{
			this->make = make;
		};

		void	setModel(std::string model)
		{
			this->model = model;
		};

		void	setYear(std::string year)
		{
			this->year = year;
		};

		// --- --- --- Getters / getter methods --- --- ---
		
		std::string	getMake()
		{
			return (this->make);
		};

		std::string	getModel()
		{
			return (model);
		};

		std::string	getYear()
		{
			return (year);
		};
};

int	main(void)
{
	Car myCar;

	myCar.setMake("Maruti");
	myCar.setModel("Wagon R");
	myCar.setYear("2017");

	myCar.displayCarInfo();
}
