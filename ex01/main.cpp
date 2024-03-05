/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:29:42 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/05 20:30:34 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./RPN \"[string]\"" << std::endl;
		return (1);
	}

	RPN rpn;
	try {
		rpn.calculate(argv[1]);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}
