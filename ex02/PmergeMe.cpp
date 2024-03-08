/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:30:29 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/08 10:12:57 by jonahkollne      ###   ########.fr       */
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
	return (data);
}

std::deque<int> PmergeMe::sort(std::deque<int> data) {
	//if (safeguard_catch(data)) // if its an "error" where i just dont have anything to sort return 1; if its a real error throw an exception
	//	return (data);
	int struggler = -1;
	if (data.size() % 2 != 0){
		struggler = data.back();
		data.pop_back();
	}
	std::deque<std::pair<int, int> > halves = this->_make_pairs<std::deque<int, std::allocator<int> > >(data);
	this->_sort_pairs(halves);
	std::pair<std::deque<int, std::allocator<int> >, std::deque<int, std::allocator<int> > > splitted = this->_split_chain<std::deque<int, std::allocator<int> > >(halves);

	// DEBUGGING LOGGING

	std::cout << "struggler: " << struggler << std::endl;
	for (size_t i = 0; i < splitted.first.size(); i++)
		std::cout << "splitted.first[" << i << "]: " << splitted.first[i] << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < splitted.second.size(); i++)
		std::cout << "splitted.second[" << i << "]: " << splitted.second[i] << std::endl;

	/// END

	//data = this->merge(splitted);
	//// if there was a struggler, put it back in
	//if (struggler != -1)
		//insert_struggler(data, struggler);
	return (data);
}

double PmergeMe::getLastBenchmark() {
	return _benchmark;
}

template <typename T, template <typename, typename> class Container>
Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > PmergeMe::_make_pairs(Container<int, std::allocator<int> > data) {
	Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > pairs;
	int greater, less;
	for (size_t i = 0; i < data.size(); i += 2) {
		less = (data[i] > data[i + 1]) ? data[i + 1] : data[i];
		greater = (data[i] > data[i + 1]) ? data[i] : data[i + 1];
		pairs.push_back(std::make_pair(greater, less));
	}
	return (pairs);
}

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
}

template <typename Container>
void PmergeMe::_sort_pairs(Container& data) {
	std::sort(data.begin(), data.end(), comparePairs);
}

template <typename T, template <typename, typename> class Container>
std::pair<Container<int, std::allocator<int> >, Container<int, std::allocator<int> > > PmergeMe::_split_chain(Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > data) {
	Container<int, std::allocator<int> > main;
	Container<int, std::allocator<int> > pend;
	size_t count = 0;
	if (data[0].first > data[0].second) {
		main.push_back(data[0].second);
		main.push_back(data[0].first);
		count++;
	}
	for (; count < data.size(); count++) {
		main.push_back(data[count].first);
		pend.push_back(data[count].second);
	}
	return (std::make_pair(main, pend));
}



template <typename Container>
void PmergeMe::_insert_binary_search(Container& data, int value) {
	(void)data;
	(void)value;
	//typename Container::iterator it = std::lower_bound(data.begin(), data.end(), value);
	//data.insert(it, value);
// OR
	// custom, selfmade binary search
}

int PmergeMe::_generate_jakobstahl(int nth) {
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
