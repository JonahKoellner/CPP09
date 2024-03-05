/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:10:08 by jkollner          #+#    #+#             */
/*   Updated: 2024/03/05 14:55:07 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <string>
#include <fstream>

class BitcoinExchange {
	private:
		std::map<std::string, double>	_exchangeRate;
		bool isValidDate(std::string date);
		// Read the database
		std::pair<std::string, double> isValidData(std::string data_line, char delimiter); // returns a pair of the currency and the exchange rate or throws exception
		std::map<std::string, double> readDatabase(std::string database_file);

	public:
		BitcoinExchange();
		BitcoinExchange(std::string database_file);
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &copy);

		double getExchangeRate(std::string data_line);
		std::pair<double, double> getExchangeValue(std::string data_line);
		~BitcoinExchange();

		class InvalidDateException : public std::exception {
			private:
				std::string date;
			public:
				InvalidDateException(std::string date);
				virtual const char *what() const throw();
		};

		class NegativeNumber : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NoNumber : public std::exception {
			public:
				virtual const char *what() const throw();
		};

};
