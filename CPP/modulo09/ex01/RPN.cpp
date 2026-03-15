/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:52:09 by marvin            #+#    #+#             */
/*   Updated: 2026/02/21 12:52:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn(){}

Rpn::~Rpn() {}

double Rpn::calculate(const std::string &expr)
{
	double right;
	double left;
	double result;
	char c;
	for (size_t i = 0; i < expr.size(); ++i)
	{
		c = expr[i];
		if (c == ' ')
			continue; // salta gli spazi
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (rpn.size() < 2)
                throw std::runtime_error("Error: Not enough operands");
			right = rpn.top(); // assegna a right il primo numero dello stack
			rpn.pop(); //rimuove il primo numero dello stack
			left = rpn.top(); 
			rpn.pop();
			switch (c)
			{
				case '+':
					result = left + right; break;
				case '-':
					result = left - right; break;
				case '*':
					result = left * right; break;
				case '/':
					if (right == 0)
						throw std::runtime_error("Error: Division by zero");
					result = left / right;
					break;
			}
			rpn.push(result);
		}
		else if (c >= '0' && c <= '9')
			rpn.push(c - '0'); // converte il carattere in numero
		else
			throw std::runtime_error("Error: Invalid character");
	}
	if (rpn.size() != 1)
		throw std::runtime_error("Error: Invalid expression");
	return (rpn.top());
}
