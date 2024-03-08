/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:16:17 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/08 14:02:42 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>

#include <iostream> // remove this after debugging

class PmergeMe {
	private:
		double _benchmark;

		template <typename T, template <typename, typename> class Container>
		Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > _make_pairs(Container<int, std::allocator<int> > data);

		template <typename Container>
		void _sort_pairs(Container& data);

		template <typename T, template <typename, typename> class Container>
		std::pair<Container<int, std::allocator<int> >, Container<int, std::allocator<int> > > _split_chain(Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > data);

		std::vector<int> _merge(std::vector<int> main, std::vector<int> pend);
		std::deque<int> _merge(std::deque<int> main, std::deque<int> pend);

		template<typename Container>
		Container _index_sequence(size_t size);

		template <typename Container>
		void _insert_binary_search(Container& data, int value);

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		std::vector<int> sort(std::vector<int> data);
		std::deque<int> sort(std::deque<int> data);
		double getLastBenchmark();
		~PmergeMe();
};
