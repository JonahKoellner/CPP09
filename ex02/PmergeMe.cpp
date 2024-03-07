/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:30:29 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/07 21:30:24 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {
	_benchmark = 0;
}

PmergeMe::PmergeMe(PmergeMe const &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
	_benchmark = other._benchmark;
	return *this;
}

std::vector<int> PmergeMe::sort(std::vector<int> data) {

}

std::deque<int> PmergeMe::sort(std::deque<int> data) {
	//if (safeguard_catch(data)) // if its an "error" where i just dont have anything to sort return 1; if its a real error throw an exception
	//	return (data);
	//int struggler;
	//if (data.size() % 2 != 0) {
	//	struggler = data.back();
	//	data.pop_back();
	//}
	//else
	//	struggler = -1;
	//T<std::pair<int, int> > halves = this->split(data);
	//sort_pairs(halves);
	//std::pair<T, T> splitted = this->split_chain(halves);
	//data = this->merge(splitted);
	//// if there was a struggler, put it back in
	//if (struggler != -1)
	//	insert_struggler(data, struggler);

}

double PmergeMe::getLastBenchmark() {
	return _benchmark;
}

template <typename T, template <typename, typename> class Container>
Container<std::pair<int, int>, std::allocator<std::pair<int, int>>> make_pairs(Container<int, std::allocator<int> > data) {
	Container<std::pair<int, int>, std::allocator<std::pair<int, int>>> pairs;
	int greater, less;
	for (int i = 0; i < data.size(); i += 2) {
		less = (data[i] > data[i + 1]) ? data[i + 1] : data[i];
		greater = (data[i] > data[i + 1]) ? data[i] : data[i + 1];
		pairs.push_back(std::make_pair(greater, less));
	}
	return (pairs);
}

template <typename T, template <typename, typename> class Container>
std::pair<Container<int, std::allocator<int>>, Container<int, std::allocator<int>>> split_chain(Container<std::pair<int, int>, std::allocator<std::pair<int, int>>> data) {
	Container<int, std::allocator<int>> main;
	Container<int, std::allocator<int>> pend;
	int count = 0;
	if (data[0].first > data[0].second) {
		main.push_back(data[0].first);
		main.push_back(data[0].second);
		count++;
	}
	for (; count < data.size(); count++) {
		main.push_back(data[count].first);
		pend.push_back(data[count].second);
	}
	return (std::make_pair(main, pend));
}



template <typename Container>
void insert_binary_search(Container& data, int value) {
	//typename Container::iterator it = std::lower_bound(data.begin(), data.end(), value);
	//data.insert(it, value);
// OR
	// custom, selfmade binary search
}

int PmergeMe::generate_jakobstahl(int nth) {
	int prev1 = 0;
	int prev2 = 1;

	if (nth == 0)
		return prev1;
	else if (nth == 1)
		return prev2;
	for (int i = 2; i <= nth; i++) {
		int current = prev2 + 2 * prev1;
		prev1 = prev2;
		prev2 = current;
	}
	return (prev2);

}

PmergeMe::~PmergeMe() {}
