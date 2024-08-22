/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays_in_classes_2.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:31:51 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/19 17:56:42 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// Car class (without the '_' prefix)
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

// Garage class (with the '_' prefix)
class	Garage
{

	private:
		Car	_cars[5];	// array of Car objects (stores max of 5 car objects)
		int	_carCount;	// to keep track of number of cars in the garage
		void	display_car_info(Car	car)
		{
			std::cout << "Car Make : " << car.getMake();
			std::cout << "\t Model : " << car.getModel();
			std::cout << "\t Year : " << car.getYear();
			std::cout << std::endl;
		}

	public:

		// Constructor: Initialized _carCount to 0
		// Garage() : _carCount(0) {}
		Garage() : _carCount(0)
		{
			std::cout << "Garage opened" << std::endl;
		}

		// Destructor class : Display message when garage is closed
		~Garage()
		{
			std::cout << "Garage closed" << std::endl;
		}
		
		void	addCar(Car car)
		{
			if (_carCount < 5)
				_cars[_carCount++] = car;
			else
				std::cout << "Garage full!!, Find anothe Garage." << std::endl;
		}

		void	garageStatus()
		{
			if (_carCount >= 5)
				std::cout << "Garage full!!" << std::endl;
			else
				std::cout << "space left for " << (5 - _carCount) << " cars." << std::endl;
		}
		
		void	displayCar(int index)
		{
			if (index < _carCount)
				display_car_info(_cars[index]);
			else if (index < 5 && index >= _carCount)
				std::cout << "No car parked here." << index << std::endl;
			else
				std::cout << "Invalid index " << index << std::endl;
		}

		void	displayAllCars()
		{
			for (int i = 0; i < _carCount; i++)
				display_car_info(_cars[i]);
		}
};

int	main(void)
{
	Car	wagonR;
	Car	innova;
	Car	i20;

	wagonR.setMake("Maruti");
	wagonR.setModel("Wagon R");
	wagonR.setYear("2017");

	innova.setMake("Toyota");
	innova.setModel("Innova");
	innova.setYear("2018");

	i20.setMake("Hyundai");
	i20.setModel("i20");
	i20.setYear("2019");

	Garage	garage;
	garage.addCar(wagonR);
	garage.addCar(innova);
	garage.addCar(i20);

	std::cout << std::endl;
	std::cout << "Displaying each car seperately" << std::endl;

	garage.displayCar(0);
	garage.displayCar(1);
	garage.displayCar(2);

	std::cout << std::endl;
	std::cout << "displaying 4th car, while 3 cars parked in garage for 5 cars" << std::endl;
	garage.displayCar(3);

	std::cout << std::endl;
	std::cout << "displaying a car out of garage capacity" << std::endl;

	garage.displayCar(5);
	garage.displayCar(10);

	std::cout << std::endl;
	std::cout << "Displaying info of all cars at once" << std::endl;

	garage.displayAllCars();

	std::cout << std::endl;
	// destructor function execute here when main function ends
		// and just before program exits
	return (0);
}
