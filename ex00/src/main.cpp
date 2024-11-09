/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aweissha <aweissha@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/09 15:02:57 by aweissha		  #+#	#+#			 */
/*   Updated: 2024/11/09 17:08:04 by aweissha		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange exchange("data.csv");
		std::ifstream inputFile(argv[1]);
		if (!inputFile.is_open())
			throw std::runtime_error("Error: could not open input file.");
		std::string line;
		std::getline(inputFile, line);
		while (std::getline(inputFile, line))
		{
			size_t pos = line.find('|');
			std::string date = line.substr(0, pos - 1);
			std::string amountStr = line.substr(pos + 2);
			if (!isValidDate(date))
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
			double amount = std::stod(amountStr);
			if (!isValidValue(amount))
			{
				std::cerr << (amount < 0 ? "Error: not a positive number.\n" : "Error: too large a number.\n");
				continue;
			}
			double price = exchange.getPrice(date);
			double result = amount * price;
			std::cout << date << " => " << amount << " = " << result << std::endl;
		}
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
