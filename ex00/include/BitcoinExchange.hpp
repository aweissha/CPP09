/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:07:02 by aweissha          #+#    #+#             */
/*   Updated: 2024/11/12 16:55:02 by aweissha         ###   ########.fr       */
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
	BitcoinExchange(const std::string& fileName);
	double getPrice(const std::string& date) const;
};

#endif