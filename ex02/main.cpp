/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:20:54 by jkollner          #+#    #+#             */
/*   Updated: 2024/03/11 12:55:56 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
template <typename Container>
bool is_sorted(Container data) {
	for (std::size_t i = 0; i < data.size() - 1; i++) {
		if (data[i] > data[i + 1])
			return false;
	}
	return true;
}

template<typename T>
T stot(const std::string & str) {
	std::stringstream ss(str);
	T num;
	ss >> num;
	return num;
}

int test_vector(int argc, char **argv) {
	clock_t start, end;

    /* Recording the starting clock tick.*/
    start = clock();

	std::vector<int> data;
	for (int i = 1; i < argc; i++) {
		int number;
		try {
			number = stot<int>(argv[i]);
		} catch (std::exception &e){
			std::cout <<"Error: " <<  e.what() << std::endl;
			return (1);
		}
		if (std::find(data.begin(), data.end(), number) != data.end()) {
			std::cerr << "Error: Duplicate number " << number << std::endl;
			return 1;
		}
		data.push_back(number);
	}
	PmergeMe p;
	std::vector<int> sorted = p.sort(data);
		// Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Before: ";
	for (long unsigned int i = 0; i < data.size(); i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	for (long unsigned int i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;
    std::cout << "Time taken by program is : " << time_taken << " sec" << std::endl;
	return (0);
}

int test_queue(int argc, char **argv) {

	clock_t start, end;

    /* Recording the starting clock tick.*/
    start = clock();

	std::deque<int> data;
	for (int i = 1; i < argc; i++) {
		int number;
		try {
			number = stot<int>(argv[i]);
		} catch (std::exception &e){
			std::cout <<"Error: " <<  e.what() << std::endl;
			return (1);
		}
		if (std::find(data.begin(), data.end(), number) != data.end()) {
			std::cerr << "Error: Duplicate number " << number << std::endl;
			return 1;
		}
		data.push_back(number);
	}
	PmergeMe p;
	std::deque<int> sorted = p.sort(data);
	// Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::cout << "Before: ";
	for (long unsigned int i = 0; i < data.size(); i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	for (long unsigned int i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;
    std::cout << "Time taken by program is : " << time_taken << " sec" << std::endl;
	return (0);
}

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "Usage: ./PmergeMe <number> <number> ... " << std::endl;
		return 1;
	}

	std::cout << "Testing Vector: " << std::endl;
	if (test_vector(argc, argv))
		std::cout << "Error: Vector test Failed " << std::endl;

	std::cout << "Testing Deque: " << std::endl;
	if (test_queue(argc, argv))
		std::cout << "Error: Deque test Failed " << std::endl;
	return 0;
}
