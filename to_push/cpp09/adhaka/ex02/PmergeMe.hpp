/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:54:47 by adhaka            #+#    #+#             */
/*   Updated: 2024/07/08 14:17:38 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cstdlib>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	~PmergeMe();
	void sortAndMeasure(const std::vector<int> &input);

private:
	std::vector<int> fjsVector(const std::vector<int> &data);
	std::deque<int> fjsDeque(const std::deque<int> &data);

	double measureTV(const std::vector<int> &data);
	double measureTD(const std::deque<int> &data);

	std::vector<int> mergeV(const std::vector<int> &left, const std::vector<int> &right);
	std::deque<int> mergeD(const std::deque<int> &left, const std::deque<int> &right);
};

#endif
