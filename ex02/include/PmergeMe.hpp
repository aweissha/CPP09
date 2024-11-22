/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:07:02 by aweissha          #+#    #+#             */
/*   Updated: 2024/11/21 15:18:57 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cctype>


class PmergeMe
{
	private:
	std::deque<int>		_deq;
	std::vector<int>	_vec;

	public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& original);
	PmergeMe& operator=(const PmergeMe& original);

	void sort(int argc, char **argv);
	void parseInput(int argc, char **argv);
	bool hasOnlyDigits(const std::string& str) const;
	void printDeqNumbers() const;
	void printVecNumbers() const;
	void sortingAlgorithmDeq(std::deque<int>& deq);
	void sortingAlgorithmVec(std::vector<int>& vec);
};

#endif