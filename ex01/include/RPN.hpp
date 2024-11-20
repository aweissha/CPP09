/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:07:02 by aweissha          #+#    #+#             */
/*   Updated: 2024/11/19 17:28:59 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>

class RPNCalculator
{
	private:
	std::stack<int> _operands;

	public:
	RPNCalculator();
	~RPNCalculator();
	RPNCalculator(const RPNCalculator& original);
	RPNCalculator& operator=(const RPNCalculator& original);
	
	void runCalculation(const std::string& input);
	void execOperator(char c);
	bool isOperand(const std::string& element);
	bool isOperator(const std::string& element);
};

#endif