/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:20:54 by jkollner          #+#    #+#             */
/*   Updated: 2024/03/06 15:53:50 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	std::vector<int> data;
	data.push_back(3);
	data.push_back(2);
	data.push_back(1);
	data.push_back(4);
	data.push_back(5);
	data.push_back(6);
	data.push_back(7);
	PmergeMe<std::vector<int> > pmerge;
	std::chrono::duration<double, std::nano> time = pmerge.sort(data);
	std::cout << "Time taken to sort: " << time.count() << " nanoseconds" << std::endl;
	
	return 0;
}
