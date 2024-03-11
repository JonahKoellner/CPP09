/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:27:22 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/11 12:34:00 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <string>
#include <sstream>
#include <iostream>

class RPN {
	private:
		std::stack<double> _stack;

		template< typename T >
		T stot(const std::string & str);

	public:
		RPN();
		RPN(RPN const & src);
		RPN & operator=(RPN const & rhs);

		void calculate(std::string str); // main function for user

		~RPN();
};
