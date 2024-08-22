/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:54:26 by adhaka            #+#    #+#             */
/*   Updated: 2024/07/08 11:50:48 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//Constructor, Destructor, Copy Constructor, Assignment Operator
RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &src) : _operands(src._operands)
{
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		_operands = src._operands;
	}
	return *this;
}

//isOperator, it will check if the string is an operator
bool RPN::isOperator(const std::string &str) const
{
	return (str == "+" || str == "-" || str == "*" || str == "/");
}

//isValid, it will check if the string is a valid number
bool RPN::isValid(const std::string &str) const
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	int num = std::atoi(str.c_str());
	return (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max());
}

//operate, it will perform the operation on the operands
int	RPN::operate(int a, int b, const std::string &op) const
{
	if (op == "+")
		return a + b;
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a * b;
	else if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("ERROR : Division by zero");
		return a / b;
	}
	throw std::runtime_error("ERROR : Invalid operator");
}

//calculate, it will calculate the expression
int RPN::calculate(const std::string &expr)
{
	std::istringstream iss(expr);
	std::string token;
	while (iss >> token)
	{
		if (isOperator(token))
		{
			if (_operands.size() < 2)
				throw std::runtime_error("ERROR : Not enough operands");
			int b = _operands.top();
			_operands.pop();
			int a = _operands.top();
			_operands.pop();
			_operands.push(operate(a, b, token));
		}
		else if (isValid(token))
		{
			_operands.push(std::atoi(token.c_str()));
		}
		else
		{
			throw std::runtime_error("ERROR : Invalid token");
		}
	}
	if (_operands.size() != 1)
		throw std::runtime_error("ERROR : Too many operands");
	return _operands.top();
}
