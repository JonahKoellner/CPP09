/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:17:21 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/04 18:24:53 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	this->_exchangeRate = readDatabase("bitcoin_data.csv");
}

BitcoinExchange::BitcoinExchange(std::string database_file) {
	this->_exchangeRate = readDatabase(database_file);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) {
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy) {
	_exchangeRate = copy._exchangeRate;
	return *this;
}

bool BitcoinExchange::isValidDate(std::string date) {
	// check if the date is valid and throw exception if it fails
}

std::pair<std::string, double> BitcoinExchange::isValidData(std::string data_line, char delimiter) {
	// take apart the data_line and throw exception if it fails

	// use isValidDate to check the date
}

std::unordered_map<std::string, double> BitcoinExchange::readDatabase(std::string database_file) {
	// open file and thorw exception if it fails

	// read the file and thorw exception if it fails
	// use isValidData to get the exchange rate and currency and store in map

	// return the exchange rate map
}

double BitcoinExchange::getExchangeRate(std::string data_line) {
	// use isValidData to check the line and get the values
}

BitcoinExchange::~BitcoinExchange() {}
