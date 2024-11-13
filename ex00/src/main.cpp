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

bool isValidDate(const std::string& date)
{
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	if (stoi(year) > 2022)
		return false;
	if (stoi(month) > 12)
		return false;
	if (stoi(day) > 31)
		return false;
	return true;
}

bool isValidValue(const double& value)
{
    return value >= 0 && value <= 1000;
}

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
			std::stringstream ss(line);
			std::string date;
			std::string amountStr;
			if (std::getline(ss, date, '|') && std::getline(ss, amountStr))
			{
				date = date.substr(0, date.find_last_not_of(" ") + 1);
				amountStr = amountStr.substr(amountStr.find_first_not_of(" "));
				if (!isValidDate(date))
				{
					std::cerr << "Error: bad input => " << date << std::endl;
					continue;
				}
				double amount = std::stod(amountStr);
				if (!isValidValue(amount))
				{
					std::cerr << (amount < 0 ? "Error: not a positive number." : "Error: too large a number.")<< std::endl;
					continue;
				}
				double price = exchange.getPrice(date);
				double result = amount * price;
				std::cout << date << " => " << amount << " = " << result << "\n";
			}
			else
				std::cerr << "Error: bad input format." << std::endl;
		}
		inputFile.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
