/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:07:02 by aweissha          #+#    #+#             */
/*   Updated: 2024/11/13 15:48:44 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
	std::map<std::string, double>	_priceData;
	void	createDataMap(const std::string& fileName);

	public:
	BitcoinExchange();
	BitcoinExchange(const std::string& fileName);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& original);
	BitcoinExchange& operator=(const BitcoinExchange& original);
	
	double getPrice(const std::string& date) const;
};

#endif