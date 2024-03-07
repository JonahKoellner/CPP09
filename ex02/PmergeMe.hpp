/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:16:17 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/07 21:08:18 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
class PmergeMe {
	private:
		double _benchmark;

		template <typename T, template <typename, typename> class Container>
		Container<std::pair<int, int>, std::allocator<std::pair<int, int>>> make_pairs(Container<int, std::allocator<int> > data);


		template <typename T, template <typename, typename> class Container>
		std::pair<Container<int, std::allocator<int>>, Container<int, std::allocator<int>>> split_chain(Container<std::pair<int, int>, std::allocator<std::pair<int, int>>> data);

		std::vector<int> merge(std::pair<std::vector<int>, std::vector<int>> data);
		std::deque<int> merge(std::pair<std::deque<int>, std::deque<int>> data);

		template <typename Container>
		void insert_binary_search(Container& data, int value);

		int generate_jakobstahl(int nth);

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		std::vector<int> sort(std::vector<int> data);
		std::deque<int> sort(std::deque<int> data);
		double getLastBenchmark();
		~PmergeMe();
};
