#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe const &src) {
	this->_last_bench = src._last_bench;
}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(PmergeMe const &rhs) {
	if (this != &rhs) {
		this->_last_bench = rhs._last_bench;
	}
	return *this;
}

template <typename T>
int PmergeMe<T>::nth_jacob(int n) {
	int prev1 = 0;
	int prev2 = 1;

	if (n == 0)
		return prev1;
	else if (n == 1)
		return prev2;
	for (int i = 2; i <= n; i++) {
		int current = prev2 + 2 * prev1;
		prev1 = prev2;
		prev2 = current;
	}
	return (prev2);
}

template <typename T>
T PmergeMe<T>::sort(T data) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	if (safeguard_catch(data)) // if its an "error" where i just dont have anything to sort return 1; if its a real error throw an exception
		return (data);
	int struggler;
	if (data.size() % 2 != 0) {
		struggler = data.back();
		data.pop_back();
	}
	else
		struggler = -1;
	T<std::pair<int, int> > halves = this->split(data);
	sort_pairs(halves);
	std::pair<T, T> splitted = this->split_chain(halves);
	data = this->merge(splitted);
	// if there was a struggler, put it back in
	if (struggler != -1)
		insert_struggler(data, struggler);

	end = std::chrono::system_clock::now();
	this->_last_bench = end - start;
	return (data);
}

template <typename T>
std::chrono::duration<double, std::nano> PmergeMe<T>::get_last_bench() {
	return this->_last_bench;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {
	// Destructor implementation...
}

// Explicit template instantiation
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;
