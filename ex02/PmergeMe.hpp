/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:43:45 by jkollner          #+#    #+#             */
/*   Updated: 2024/03/06 13:23:43 by jkollner         ###   ########.fr       */
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
		T split_data(T &data); // returns the second data pair set. also changes the first data pair set
		void merge_data(T &data1, T &data2); // merges the two data pair sets into data1
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &rhs);
		std::chrono::duration<double, std::nano> sort(T &data); // returns the time taken for the sort
		//T getData();
};
