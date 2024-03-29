/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:30:29 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/11 12:56:48 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(PmergeMe const &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
	(void)other;
	return *this;
}

std::vector<int> PmergeMe::sort(std::vector<int> data) {

	if (data.size() < 2)
		return (data);
	int struggler = -1;
	if (data.size() % 2 != 0){
		struggler = data.back();
		data.pop_back();
	}
	std::vector<std::pair<int, int> > halves = this->_make_pairs<std::vector<int, std::allocator<int> > >(data);
	this->_sort_pairs(halves);
	std::pair<std::vector<int, std::allocator<int> >, std::vector<int, std::allocator<int> > > splitted = this->_split_chain<std::vector<int, std::allocator<int> > >(halves);


	data = this->_merge(splitted.first, splitted.second);
	//// if there was a struggler, put it back in
	if (struggler != -1)
		this->_insert_binary_search(data, struggler);

	return (data);
}

std::deque<int> PmergeMe::sort(std::deque<int> data) {

	if (data.size() < 2)
		return (data);
	int struggler = -1;
	if (data.size() % 2 != 0){
		struggler = data.back();
		data.pop_back();
	}
	std::deque<std::pair<int, int> > halves = this->_make_pairs<std::deque<int, std::allocator<int> > >(data);
	this->_sort_pairs(halves);
	std::pair<std::deque<int, std::allocator<int> >, std::deque<int, std::allocator<int> > > splitted = this->_split_chain<std::deque<int, std::allocator<int> > >(halves);

	data = this->_merge(splitted.first, splitted.second);
	//// if there was a struggler, put it back in
	if (struggler != -1)
		this->_insert_binary_search(data, struggler);

	return (data);
}

template <typename T, template <typename, typename> class Container>
Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > PmergeMe::_make_pairs(Container<int, std::allocator<int> > data) {
	Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > pairs;
	int greater, less;
	for (std::size_t i = 0; i < data.size(); i += 2) {
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
	std::size_t count = 0;
	if (data[0].first > data[0].second) {
		main.push_back(data[0].second);
		main.push_back(data[0].first);
		pend.push_back(data[0].second);
		count++;
	}
	for (; count < data.size(); count++) {
		main.push_back(data[count].first);
		pend.push_back(data[count].second);
	}
	return (std::make_pair(main, pend));
}

std::vector<int> PmergeMe::_merge(std::vector<int> main, std::vector<int> pend) {
	const std::vector<int> _index_sequence = this->_index_sequence<std::vector<int> >(pend.size() + main.size());

	for (std::size_t i = 0; i < _index_sequence.size(); i++) {
		if (_index_sequence[i] < (int)pend.size())
			this->_insert_binary_search(main, pend[_index_sequence[i]]);
	}
	return (main);
}

std::deque<int> PmergeMe::_merge(std::deque<int> main, std::deque<int> pend) {
	const std::deque<int> _index_sequence = this->_index_sequence<std::deque<int> >(pend.size() + main.size());

	for (std::size_t i = 0; i < _index_sequence.size(); i++) {
		if (_index_sequence[i] < (int)pend.size())
			this->_insert_binary_search(main, pend[_index_sequence[i]]);
	}
	return (main);
}

template <typename Container>
Container PmergeMe::_index_sequence(std::size_t size) {
	Container sequence;
	Container jacob(size);
	 if (size > 0) {
        jacob[0] = 0;
    }
    if (size > 1) {
        jacob[1] = 1;
    }
	int lastJacob = 2;
    for (std::size_t i = 2; i < size; i++) {
        jacob[i] = jacob[i - 1] + 2 * jacob[i - 2];
		sequence.push_back(jacob[i]);
		for (int number = jacob[i] - 1; number > lastJacob; number--) {
			sequence.push_back(number);
		}
		if (sequence.size() >= size)
			break;
		lastJacob = jacob[i];
    }

	return (sequence);
}
template <typename Container>
void PmergeMe::_insert_binary_search(Container& data, int value) {
	typename Container::iterator it = std::lower_bound(data.begin(), data.end(), value);
	data.insert(it, value);
}

PmergeMe::~PmergeMe() {}
