/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_destructor.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:46:35 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/18 18:10:38 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Car
{
	private:
		std::string _make;
		std::string _model;
		std::string _year;

	public:
		// constructor
		Car(std::string make, std::string model, std::string year)
		{
			_make = make;
			_model = model;
			_year = year;
			std::cout << "Car object is created as : " << make << ", "<< model << ", " << year << "." << std::endl;
		};

		Car()
		{
			_make = "Royal Enfield";
			_model = "Bullet";
			_year = "2017";
			std::cout << "Car object is created as : " << _make << ", "<< _model << ", " << _year << "." << std::endl;
		};
		
		// destructor
		~Car()
		{
			std::cout << "Car object is destroyed" << std::endl;
		};

		// member function
		void	displayCarInfo()
		{
			std::cout << "Car Make : " << _make << "\t Model : " << _model << "\t Year : " << _year << std::endl;
		};
};

int	main(void)
{
	Car myCar("Maruti", "Wagon R", "2015");
	Car myCar2;
}