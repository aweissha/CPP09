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

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& fileName)
{
	createDataMap(fileName);
}

void BitcoinExchange::createDataMap(const std::string& inputFile)
{
	std::ifstream file(inputFile);
	if (!file.is_open())
		throw std::runtime_error("Error: could not open data file.");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		std::string date = line.substr(0, pos);
		std::string priceStr = line.substr(pos + 1);
		double price = std::stod(priceStr);
		_priceData[date] = price;
	}
	file.close();
}

double BitcoinExchange::getPrice(const std::string &date) const
{
	auto it = _priceData.lower_bound(date);
	if (it == _priceData.end() || it->first != date)
		--it;
	return it->second;
}
