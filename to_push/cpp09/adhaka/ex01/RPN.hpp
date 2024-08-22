/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:54:29 by adhaka            #+#    #+#             */
/*   Updated: 2024/07/08 12:22:07 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <string>

class RPN
{
	private:
		std::stack<int> _operands;
		bool isOperator(const std::string &str) const;
		bool isValid(const std::string &str) const;
		int  operate(int a, int b, const std::string &op) const;

	public:
		RPN();
		RPN(const RPN &src);
		~RPN();
		RPN &operator=(const RPN &src);
		int calculate(const std::string &expr);
};

#endif

