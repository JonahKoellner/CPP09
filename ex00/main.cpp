/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:18:51 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/04 18:47:43 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./bitcoinExchange <filename>" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	try {
		exchange = BitcoinExchange("data.csv");
	} catch (std::exception e) {
		std::cerr << "Error: " << e.what() << std::endl;
		file.close();
		return (-1);
	}

	std::string line;
	while (std::getline(file, line)) {
		try{
			std::pair<double, double> value = exchange.getExchangeValue(line); // value.first = amount, value.second = rate
			std::cout << line.substr(0, line.find('|')) << "=> " << value.second << " = " << (value.first * value.second) << std::endl;
		} catch (std::exception e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	file.close();
	return (0);
}
