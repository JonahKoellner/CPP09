// PmergeMe.cpp
#include "PmergeMe.hpp"


template <typename T>
PmergeMe<T>::PmergeMe() {
	// Constructor implementation...
}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe const &src) {
	(void)src;
	// Copy constructor implementation...
}

template <typename T>
PmergeMe<T>::~PmergeMe() {
	// Destructor implementation...
}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(PmergeMe const &rhs) {
	(void)rhs;
	return *this;
}

template <typename T>
std::chrono::duration<double, std::nano> PmergeMe<T>::sort(T &data) {
	T second_data;
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	second_data = split_data(data);
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < second_data.size(); i++) {
		std::cout << second_data[i] << " ";
	}
	std::cout << std::endl;
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
}

template <typename T>
T PmergeMe<T>::split_data(T &data) {
	// split_data method implementation...
	T second_data;
	size_t count = 0;
	typename T::iterator it = data.begin();
	while (it != data.end()) {
		if (count % 2 == 0) {
			second_data.push_back(*it);
			it = data.erase(it);
		}
		else {
			++it;
		}
		++count;
	}

	return second_data;
	(void)data;
}

template <typename T>
void PmergeMe<T>::merge_data(T &data1, T &data2) {
	// merge_data method implementation...
	(void)data1;
	(void)data2;

}

// Explicit template instantiation
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;
