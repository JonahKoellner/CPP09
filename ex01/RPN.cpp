/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:07:43 by jonahkollne       #+#    #+#             */
/*   Updated: 2024/03/05 21:21:19 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(RPN const & src) {
	*this = src;
}

RPN & RPN::operator=(RPN const & rhs) {
	if (this != &rhs) {
		_stack = rhs._stack;
	}
	return *this;
}

bool isNumber(const std::string& str) {
	std::stringstream ss(str);
	float f;
	ss >> f;
	// Check if the entire string was consumed and if there's no error
	return (ss.eof() && !ss.fail());
}

void RPN::calculate(std::string str) {
	// take string and iterate
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, ' ')) {
		if (isNumber(token)) {
			_stack.push(std::stoi(token));
		} else {
			// If the token is an operator, pop two numbers from the stack,
			// perform the operation, and push the result back onto the stack
			if (token.size() != 1 || (token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/'))
				throw std::runtime_error("Token not recognized");
			if (_stack.size() < 2)
				throw std::runtime_error("operands amount for operator error");

			int num2 = _stack.top(); _stack.pop();
			int num1 = _stack.top(); _stack.pop();
			if (token == "+") _stack.push(num1 + num2);
			else if (token == "-") _stack.push(num1 - num2);
			else if (token == "*") _stack.push(num1 * num2);
			else if (token == "/") _stack.push(num1 / (num2 == 0 ? throw std::runtime_error("zero div") : num2));
			else throw std::runtime_error("Token not recognized");
			//std::cout << num1 << " " << token << " " << num2 << " = " << _stack.top() << std::endl;
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Counting Error");
	// The last item on the stack is the result
	int result = _stack.top(); _stack.pop();
	std::cout << result << std::endl;
}



RPN::~RPN() {}
