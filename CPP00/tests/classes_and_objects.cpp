/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes_and_objects.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:23:31 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/18 18:01:31 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Exercise:
 * 	Create a Car class with attributes make, model, and year.
 * 	Create a method displayCarInfo() that prints out the car's information.
 * 	Instantiate an object of the Car class in main()
 * 		set its attributes
 * 		then call displayCarInfo().
 * 	Expected Output:
 * 		Car Make : make_name	Model : model_name	Year : year
 */

#include <iostream>

class	Car
{
	public:
		std::string	make;
		std::string	model;
		std::string	year;

		void	displayCarInfo()
		{
			std::cout << "Car Make : " << make << "\t  Model : " << model << "\t Year : " << year << std::endl;
		};
};

int main(void)
{
	Car myCar;

	myCar.make = "Maruti";
	myCar.model = "Wagon R";
	myCar.year = "2017";
	
	myCar.displayCarInfo();
	return (0);
}
