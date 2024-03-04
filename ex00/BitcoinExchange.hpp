/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:10:08 by jkollner          #+#    #+#             */
/*   Updated: 2024/03/04 12:22:57 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <unordered_map>


class BitcoinExchange {
	private:
		std::unordered_map<std::string, double> _exchangeRate;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &copy);

		void readExchangeRate(std::string filename);
		bool isValidDate(std::string date);
		std::pair<std::string, double> isValidData(std::string data_line); // returns a pair of the currency and the exchange rate or throws exception
		double getExchangeRate(std::string date);

		~BitcoinExchange();
};
