/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:52:12 by marvin            #+#    #+#             */
/*   Updated: 2026/02/21 12:52:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <string>
#include <stack>

class Rpn
{
    private:
        std::stack<double> rpn;
    public:
        Rpn();
        ~Rpn();
        
        double calculate(const std::string &expr);
};

#endif