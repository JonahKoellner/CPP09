/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:20:54 by jkollner          #+#    #+#             */
/*   Updated: 2024/03/09 20:13:45 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
template <typename Container>
bool is_sorted(Container data) {
	for (size_t i = 0; i < data.size() - 1; i++) {
		if (data[i] > data[i + 1])
			return false;
	}
	return true;
}

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "Usage: ./PmergeMe <number> <number> ... " << std::endl;
		return 1;
	}
	std::vector<int> data;
	std::deque<int> data2;
	for (int i = 1; i < argc; i++) {
		//std::cout << "pushing item nr." << i << " : " << argv[i] << std::endl;
		data.push_back(atoi(argv[i]));
		data2.push_back(atoi(argv[i]));
	}
	PmergeMe p;
	std::vector<int> sorted = p.sort(data);
	std::cout << "time taken: " << p.getLastBenchmark() << "microseconds vector" << std::endl;
	std::deque<int> sorted2 = p.sort(data2);
	std::cout << "time taken: " << p.getLastBenchmark() << "microseconds deque" << std::endl;
	//std::cout << "data.size(): " << data.size() << std::endl;
	//std::cout << "data2.size(): " << data2.size() << std::endl;
	std::cout << "is_sorted(sorted): " << (is_sorted(sorted) ? "\033[1;32mIs sorted\033[0m" : "\033[1;31mNot sorted\033[0m" ) << std::endl;
	std::cout << "is_sorted(sorted2): " << (is_sorted(sorted2) ? "\033[1;32mIs sorted\033[0m" : "\033[1;31mNot sorted\033[0m" ) << std::endl;
	//for (size_t i = 0; i < sorted.size(); i++)
	//	std::cout << sorted[i] << " ";
	//std::cout << std::endl;
	//for (size_t i = 0; i < sorted2.size(); i++)
	//	std::cout << sorted2[i] << " ";
	//std::cout << std::endl;
	return 0;
}
