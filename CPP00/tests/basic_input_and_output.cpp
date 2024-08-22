/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_input_and_output.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:48:06 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/19 21:10:47 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class	Car
{

	private:
		std::string	make;
		std::string	model;
		std::string	year;

		void	requestInfo()
		{
			std::cout << "Enter the make of the car : ";
			std::cin >> make;
			std::cout << "Enter the model of the car : ";
			std::cin >> model;
			std::cout << "Enter the year of the car : ";
			std::cin >> year;
		}

	public:
		void	displayCarInfoOld()
		{
			std::cout << "Car Make : " << make << "\t Model : " << model << "\t Year : " << year << std::endl;
		};

		void	displayCarInfo()
		{
			requestInfo();
			// std::cout << "Car Make : " << make << "\t Model : " << model << "\t Year : " << year << std::endl;
			displayCarInfoOld();
		};

		// --- --- --- Setters / setter methods --- --- --- //

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

		// --- --- --- Getters / getter methods --- --- --- //
		
		//* const signifies 'object is not modified'
		//* good practice to use const keyword with getter methods to avoid accidental changes
		std::string	getMake()
		const
		{
			return (this->make);
		};

		std::string	getModel()
		const
		{
			return (model);
		};

		std::string	getYear()
		const
		{
			return (year);
		};
};

int main(void)
{
	Car myCar;

	myCar.displayCarInfo();
	return (0);
}

// Output:

// Enter the make of the car : Maruthi
// Enter the model of the car : WagonR
// Enter the year of the car : 2014
// Car Make : Maruthi       Model : WagonR  Year : 2014