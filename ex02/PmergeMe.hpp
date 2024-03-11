/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:16:17 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/11 12:57:18 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe {
	private:

		template <typename T, template <typename, typename> class Container>
		Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > _make_pairs(Container<int, std::allocator<int> > data);

		template <typename Container>
		void _sort_pairs(Container& data);

		template <typename T, template <typename, typename> class Container>
		std::pair<Container<int, std::allocator<int> >, Container<int, std::allocator<int> > > _split_chain(Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > data);

		std::vector<int> _merge(std::vector<int> main, std::vector<int> pend);
		std::deque<int> _merge(std::deque<int> main, std::deque<int> pend);

		template<typename Container>
		Container _index_sequence(std::size_t size);

		template <typename Container>
		void _insert_binary_search(Container& data, int value);

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		std::vector<int> sort(std::vector<int> data);
		std::deque<int> sort(std::deque<int> data);
		~PmergeMe();
};
