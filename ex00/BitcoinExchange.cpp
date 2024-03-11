/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:17:21 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/11 12:29:10 by jkollner         ###   ########.fr       */
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
	date = date.substr(0, 10);
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	try {
		int year = this->stot<int>(date.substr(0, 4));
		int month = this->stot<int>(date.substr(5, 2));
		int day = this->stot<int>(date.substr(8, 2));

		const int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		if (year < 1 || month < 1 || month > 12 || day < 1 || day > month_days[month - 1]) {
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
		throw std::runtime_error("Error: bad input => " + date);

	}

	// check if value is number
	double value_num;
	try {
		value_num = this->stot<double>(value);
	} catch (std::exception &e) {
		throw NoNumber();
	}
	if (value_num < 0) {
		throw NegativeNumber();
	}
	return std::make_pair(date, value_num);
}

std::map<std::string, double> BitcoinExchange::readDatabase(std::string database_file) {
	std::map<std::string, double> db_content;

	// open file and thorw exception if it fails
	std::fstream file;
	file.open(database_file.c_str());
	if (file.fail()) {
		throw std::runtime_error("Error: could not open file");
	}

	// read the file and thorw exception if it fails
	// use isValidData to get the exchange rate and currency and store in map
	std::string line;
	while (std::getline(file, line)) {
		try
		{
			std::pair<std::string, double> value = isValidData(line, ',');
			db_content[value.first] = value.second;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
	// return the exchange rate map
	return (db_content);
}

double BitcoinExchange::getExchangeRate(std::string data_line) {
	// use isValidData to check the line and get the values
	std::pair<std::string, double> value = isValidData(data_line, '|');

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

std::pair<double, double> BitcoinExchange::getExchangeValue(std::string data_line) {
	// use getExchangeRate to get the exchange rate
	double rate = getExchangeRate(data_line);


	// use isValidData to check the line and get the values
	std::pair<std::string, double> value = isValidData(data_line, '|');

	if (value.second > 2147483647)
		throw NoNumber();

	// return the amount and the value
	return std::make_pair(value.second, rate);
}

template< typename T >
T BitcoinExchange::stot(const std::string & str) {
	std::stringstream ss(str);
	T f;
	ss >> f;
	// Check if the entire string was consumed and if there's no error
	return (f);
}

const char *BitcoinExchange::NegativeNumber::what() const throw() {
	return ("Error: Negative number");
}

const char *BitcoinExchange::NoNumber::what() const throw() {
	return ("Error: Not a number");
}

BitcoinExchange::~BitcoinExchange() {}
