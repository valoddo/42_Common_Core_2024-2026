/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:50:56 by vloddo            #+#    #+#             */
/*   Updated: 2026/02/05 10:47:25 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <string>
#include <stack>

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // alias per l'iteratore del container interno
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }
};


#endif
