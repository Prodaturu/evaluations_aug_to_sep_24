/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:54:44 by adhaka            #+#    #+#             */
/*   Updated: 2024/07/08 15:11:54 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//Constructor, Destructor, Copy constructor and Copy assignment operator
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	(void)src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortAndMeasure(const std::vector<int> &input)
{
	std::vector<int> dataVector(input);
	std::deque<int> dataDeque(input.begin(), input.end());
	std::cout << "Before: ";
	for (size_t i = 0; i < input.size(); ++i)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
	double timeVector = measureTV(dataVector);
	double timeDeque = measureTD(dataDeque);
	std::cout << "Time to process a range of " << input.size() << " elements with std::vector: " << timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << input.size() << " elements with std::deque: " << timeDeque << " us" << std::endl;
}

double PmergeMe::measureTV(const std::vector<int> &data)
{
	std::clock_t start = std::clock();
	std::vector<int> sortedData = fjsVector(data);
	std::clock_t end = std::clock();

	double timeTaken = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

	std::cout << "After (std::vector): ";
	for (size_t a = 0; a < sortedData.size(); ++a)
	{
		std::cout << sortedData[a] << " ";
	}
	std::cout << std::endl;
	return timeTaken;
}

double PmergeMe::measureTD(const std::deque<int> &data)
{
	std::clock_t start = std::clock();
	std::deque<int> sortedData = fjsDeque(data);
	std::clock_t end = std::clock();
	double timeTaken = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
	std::cout << "After (std::deque): ";
	for (size_t b = 0; b < sortedData.size(); ++b)
	{
		std::cout << sortedData[b] << " ";
	}
	std::cout << std::endl;

	return timeTaken;
}

/* 1. Split the vector into halves
   2. Recursively sort both halves
   3. Merge the sorted halves */
std::vector<int> PmergeMe::fjsVector(const std::vector<int> &data)
{
	if (data.size() <= 1)
	{
		return data;
	}
	std::vector<int> left, right;
	size_t const halfSize = data.size() / 2;
	std::copy(data.begin(), data.begin() + halfSize, std::back_inserter(left));
	std::copy(data.begin() + halfSize, data.end(), std::back_inserter(right));
	left = fjsVector(left);
	right = fjsVector(right);
	return mergeV(left, right);
}

std::vector<int> PmergeMe::mergeV(const std::vector<int> &left, const std::vector<int> &right)
{
	std::vector<int> result;
	size_t leftIndex = 0, rightIndex = 0;
	while (leftIndex < left.size() && rightIndex < right.size())
	{
		if (left[leftIndex] < right[rightIndex])
		{
			result.push_back(left[leftIndex++]);
		}
		else
		{
			result.push_back(right[rightIndex++]);
		}
	}
	while (leftIndex < left.size())
	{
		result.push_back(left[leftIndex++]);
	}
	while (rightIndex < right.size())
	{
		result.push_back(right[rightIndex++]);
	}
	return result;
}

/* 1. Split the deque into halves
   2. Recursively sort both halves
   3. Merge the sorted halves */
std::deque<int> PmergeMe::fjsDeque(const std::deque<int> &data)
{
	if (data.size() <= 1)
	{
		return data;
	}
	std::deque<int> left, right;
	size_t const halfSize = data.size() / 2;
	std::copy(data.begin(), data.begin() + halfSize, std::back_inserter(left));
	std::copy(data.begin() + halfSize, data.end(), std::back_inserter(right));
	left = fjsDeque(left);
	right = fjsDeque(right);
	return mergeD(left, right);
}

std::deque<int> PmergeMe::mergeD(const std::deque<int> &left, const std::deque<int> &right)
{
	std::deque<int> result;
	std::deque<int>::const_iterator itLeft = left.begin(), itRight = right.begin();
	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft < *itRight)
		{
			result.push_back(*itLeft++);
		}
		else
		{
			result.push_back(*itRight++);
		}
	}
	result.insert(result.end(), itLeft, left.end());
	result.insert(result.end(), itRight, right.end());
	return result;
}
