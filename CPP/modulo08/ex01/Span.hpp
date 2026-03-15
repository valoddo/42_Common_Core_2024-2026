/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:41:24 by vloddo            #+#    #+#             */
/*   Updated: 2026/02/02 19:39:15 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> 
#include <algorithm> 


class Span
{
	private:
		std::vector<int> store;
		unsigned int max;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& o);
		Span& operator=(const Span& o);
		~Span();
		
		void addNumber(int n);
		template<typename It>
		void addMultiNumber(It begin, It end)
		{
			for(It it = begin; it != end; ++it)
			{
				if (store.size() >= max)
					throw std::out_of_range("Span pieno");  // lancia eccezione se non puoi aggiungere
			store.push_back(*it);  // aggiungi l’elemento al vector
			}
		}
		int shortestSpan() const;
		int longestSpan() const;
};

#endif