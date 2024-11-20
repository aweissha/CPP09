/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   BitcoinExchange.cpp								:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aweissha <aweissha@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/09 15:06:05 by aweissha		  #+#	#+#			 */
/*   Updated: 2024/11/09 16:09:04 by aweissha		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPNCalculator::RPNCalculator(){}

RPNCalculator::~RPNCalculator(){}

RPNCalculator::RPNCalculator(const RPNCalculator& original)
{
	*this = original;
}

RPNCalculator& RPNCalculator::operator=(const RPNCalculator& original)
{
	if (this != &original)
		this->_operands = original._operands;
	return *this;
}

void RPNCalculator::runCalculation(const std::string& input)
{
	std::istringstream stream(input);
	std::string element;

	while (stream >> element)
	{
		if (isOperand(element))
			this->_operands.push(std::stoi(element));
		else if (isOperator(element))
			this->execOperator(element[0]);
		else
			throw std::runtime_error("Invalid input.");
	}
	if (this->_operands.size() == 1)
		std::cout << this->_operands.top() << std::endl;
	else
		throw std::runtime_error("Invalid syntax.");
}

void RPNCalculator::execOperator(char c)
{
	if (_operands.size() < 2)
    	throw std::runtime_error("Not enough operands for operation.");
	int operand2 = _operands.top();
	_operands.pop();
	int operand1 = _operands.top();
	_operands.pop();
	switch (c)
	{
	case '+':
		_operands.push(operand1 + operand2);
		break;
	case '-':
		_operands.push(operand1 - operand2);
		break;
	case '*':
		_operands.push(operand1 * operand2);
		break;
	case '/':
		if (operand2 == 0)
			throw std::runtime_error("Division by 0 is invalid.");
		_operands.push(operand1 / operand2);
		break;
	default:
		throw std::runtime_error("Invalid input.");
		break;
	}
}

bool RPNCalculator::isOperand(const std::string& element)
{
	int start = 0;
	if (element[0] == '-' && element.size() > 1)
		start = 1;
	for (size_t i = start; i < element.size(); i++)
		if (!isdigit(element[i]))
			return false;
	return true;
}

bool RPNCalculator::isOperator(const std::string& element)
{
	if (element.size() > 1)
		return false;
	else
		return (element[0] == '+' || element[0] == '-' || element[0] == '*' || element[0] == '/');
}
