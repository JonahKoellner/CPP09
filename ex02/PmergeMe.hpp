/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:43:45 by jkollner          #+#    #+#             */
/*   Updated: 2024/03/06 20:35:33 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <chrono>
#include <algorithm> // for std::sort
#include <vector>
#include <deque>
#include <iostream>

template <typename T>
class PmergeMe {
	private:
		std::chrono::duration<double, std::nano> _last_bench;
		int nth_jacob(int n); // returns the nth jacob number
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &rhs);
		T sort(T data); // returns the sorted data
		std::chrono::duration<double, std::nano> get_last_bench(); // returns the time for the last sort
};
