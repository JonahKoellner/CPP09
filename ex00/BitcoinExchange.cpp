/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:17:21 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/05 15:21:43 by jonahkollne      ###   ########.fr       */
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
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	try {
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		const int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		if (month < 1 || month > 12 || day < 1 || day > month_days[month - 1]) {
			return false;
		}
	} catch (std::exception &e) {
		return false;
	}
	return (true);
}

std::pair<std::string, double> BitcoinExchange::isValidData(std::string data_line, char delimiter) {
	// take apart the data_line and throw exception if it fails
	// find first delimiter
	size_t del_pos = data_line.find(delimiter);
	if (del_pos == std::string::npos) {
		throw std::runtime_error("Error: Format Delimiter Error");
	}
	std::string date = data_line.substr(0, del_pos);
	std::string value = data_line.substr(del_pos + 1);
	if (isValidDate(date) == false) {
		throw InvalidDateException(date);
	}

	// check if value is number
	double value_num;
	try {
		value_num = std::stod(value);
	} catch (std::exception &e) {
		throw NoNumber();
	}
	if (value_num < 0)
		throw NegativeNumber();
	return std::make_pair(date, value_num);
}

std::map<std::string, double> BitcoinExchange::readDatabase(std::string database_file) {
	std::map<std::string, double> db_content;

	// open file and thorw exception if it fails
	std::ifstream file(database_file);
	if (!file) {
		throw std::runtime_error("Error: could not open file");
	}

	// read the file and thorw exception if it fails
	// use isValidData to get the exchange rate and currency and store in map
	std::string line;
	while (std::getline(file, line)) {
		std::pair<std::string, double> value = isValidData(line, ',');
		db_content[value.first] = value.second;
	}

	// return the exchange rate map
	return (db_content);
}

double BitcoinExchange::getExchangeRate(std::string data_line) {
	// use isValidData to check the line and get the values
	std::pair<std::string, double> value = isValidData(data_line, ' ');

	std::map<std::string, double>::iterator upper = _exchangeRate.upper_bound(value.first);
	if (upper != _exchangeRate.begin()) {
		--upper;
	}

	if (upper != _exchangeRate.end()) {
		return upper->second;
	} else {
		throw std::runtime_error("No date found that is less than or equal to the target date");
	}
}

BitcoinExchange::~BitcoinExchange() {}
