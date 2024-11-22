/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:18:03 by aweissha          #+#    #+#             */
/*   Updated: 2024/11/21 15:55:33 by aweissha         ###   ########.fr       */
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
	std::cout << "Deque before: ";
	printDeqNumbers();
	std::cout << "Vector before: ";
	printVecNumbers();

	// Run algorithm for deque and track time
	auto start = std::chrono::high_resolution_clock::now();
	sortingAlgorithmDeq(_deq);
	auto end = std::chrono::high_resolution_clock::now();
	auto durationDeq = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	// Run algorithm for vector and track time
	start = std::chrono::high_resolution_clock::now();
	sortingAlgorithmVec(_vec);
	end = std::chrono::high_resolution_clock::now();
	auto durationVec = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	
	// Print the results
	std::cout << "Deque after: ";
	printDeqNumbers();
	std::cout << "Vector after: ";
	printVecNumbers();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque<int>: " << durationDeq.count() << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vec<int>: " << durationVec.count() << " us" << std::endl;
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
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void PmergeMe::printDeqNumbers() const
{
	for (std::deque<int>::const_iterator it = _deq.begin(); it != _deq.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::printVecNumbers() const
{
	for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::sortingAlgorithmDeq(std::deque<int>& deq)
{
	if (deq.size() <= 1)
		return;

	std::deque<int> bigger;
	std::deque<int> smaller;

	for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++)
	{
		// std::cout << "hello" << std::endl;
		std::deque<int>::const_iterator first = it++;
		if (it == deq.end())
		{
			bigger.push_back(*first);
			break ;
		}
		else if (*first < *it)
		{
			bigger.push_back(*it);
			smaller.push_back(*first);
		}
		else
		{
			bigger.push_back(*first);
			smaller.push_back(*it);
		}
	}
	sortingAlgorithmDeq(bigger);
	for (std::deque<int>::const_iterator it = smaller.begin(); it != smaller.end(); it++)
	{
		std::deque<int>::const_iterator pos = std::lower_bound(bigger.begin(), bigger.end(), *it);
		bigger.insert(pos, *it);
	}
	deq = bigger;
}

void PmergeMe::sortingAlgorithmVec(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<int> bigger;
	std::vector<int> smaller;

	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		// std::cout << "hello" << std::endl;
		std::vector<int>::const_iterator first = it++;
		if (it == vec.end())
		{
			bigger.push_back(*first);
			break ;
		}
		else if (*first < *it)
		{
			bigger.push_back(*it);
			smaller.push_back(*first);
		}
		else
		{
			bigger.push_back(*first);
			smaller.push_back(*it);
		}
	}
	sortingAlgorithmVec(bigger);
	for (std::vector<int>::const_iterator it = smaller.begin(); it != smaller.end(); it++)
	{
		std::vector<int>::const_iterator pos = std::lower_bound(bigger.begin(), bigger.end(), *it);
		bigger.insert(pos, *it);
	}
	vec = bigger;
}
