/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:20:54 by jkollner          #+#    #+#             */
/*   Updated: 2024/03/11 08:30:46 by jkollner         ###   ########.fr       */
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
		double number = atof(argv[i]);
		if (number > INT_MAX || number < INT_MIN) {
			std::cerr << "Error: Number " << number << " is out of range" << std::endl;
			return 1;
		}
		if (std::find(data.begin(), data.end(), number) != data.end()) {
			std::cerr << "Error: Duplicate number " << number << std::endl;
			return 1;
		}
		data.push_back((int)number);
		data2.push_back((int)number);
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < data.size(); i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
	PmergeMe p;
	std::vector<int> sorted = p.sort(data);
	double vec_bench = p.getLastBenchmark();
	std::deque<int> sorted2 = p.sort(data2);
	double deq_bench = p.getLastBenchmark();
	std::cout << "After: ";
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;
	std::cout << "TIme to process a range of " << data.size() << " elements with std::vector:\t" << vec_bench << " microseconds" << std::endl;

	std::cout << "TIme to process a range of " << data.size() << " elements with std::deque:\t" << deq_bench << " microseconds" << std::endl;

	std::cout << "is_sorted(sorted): " << (is_sorted(sorted) ? "\033[1;32mIs sorted\033[0m" : "\033[1;31mNot sorted\033[0m" ) << std::endl;
	std::cout << "is_sorted(sorted2): " << (is_sorted(sorted2) ? "\033[1;32mIs sorted\033[0m" : "\033[1;31mNot sorted\033[0m" ) << std::endl;
	return 0;
}
