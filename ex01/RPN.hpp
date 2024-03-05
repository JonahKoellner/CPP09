/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:22 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/05 20:52:09 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <string>
#include <sstream>
#include <iostream>

class RPN {
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(RPN const & src);
		RPN & operator=(RPN const & rhs);

		void calculate(std::string str); // main function for user

		~RPN();
};
