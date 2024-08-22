/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:09:56 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/18 14:21:25 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Teacher
{
	private :
		int index;
	public :
		int health;
		Teacher(int index) : health(10)
		{
			this->index = index;
		}
		
};

int	main(void)
{
	Teacher teacher1(1);

	std::cout << teacher1.health << std::endl;

}