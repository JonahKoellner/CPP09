/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:20:54 by jkollner          #+#    #+#             */
/*   Updated: 2024/03/08 15:18:45 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "Usage: ./PmergeMe <number> <number> ... " << std::endl;
		return 1;
	}
	std::vector<int> data;
	std::deque<int> data2;
	for (int i = 1; i < argc; i++) {
		data.push_back(atoi(argv[i]));
		data2.push_back(atoi(argv[i]));
	}
	PmergeMe p;
	std::deque<int> sorted2 = p.sort(data2);
	std::vector<int> sorted = p.sort(data);
	for (size_t i = 0; i < sorted2.size(); i++)
		std::cout << sorted2[i] << " ";
	std::cout << std::endl;
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;
	return 0;
}
