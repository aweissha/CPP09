/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:18:03 by aweissha          #+#    #+#             */
/*   Updated: 2024/11/20 18:52:47 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& original)
{
	*this = original;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& original)
{
	if (this != &original)
	{
		this->_deq = original._deq;
		this->_vec = original._vec;
	}
	return *this;
}

void PmergeMe::sort(int argc, char **argv)
{
	parseInput(argc, argv);
	
}

void PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		if (!hasOnlyDigits(str))
			throw std::runtime_error("Invalid input.");
		int nbr = std::stoi(str);
		if (nbr <= 0)
			throw std::runtime_error("Invalid input.");
		_deq.push_back(nbr);
		_vec.push_back(nbr);
	}
}

bool PmergeMe::hasOnlyDigits(const std::string& str) const
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}
