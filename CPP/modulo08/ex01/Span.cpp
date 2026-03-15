/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:05:02 by vloddo            #+#    #+#             */
/*   Updated: 2026/02/02 19:39:07 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : max(0) {}

Span::Span(unsigned int n) : max(n) {}

Span::Span(const Span& o) : store(o.store), max(o.max){}

Span& Span::operator=(const Span& o)
{
	if(this != &o)
	{
		store = o.store;
		max = o.max;
	}
	return(*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (store.size() >= max)
        throw std::out_of_range("Span pieno");  // lancia eccezione se non puoi aggiungere
    store.push_back(n);  // aggiungi l’elemento al vector
}

int Span::shortestSpan() const
{
	if(store.size() <= 2)
		throw std::out_of_range("Span less than 3 numbers");
    std::vector<int> tmp(store);       // copia del vector
    std::sort(tmp.begin(), tmp.end()); // ordina - funzione membro di algorithm

    int shortSpan = tmp[1] - tmp[0];

    for (size_t i = 1; i < tmp.size(); ++i)
	{
        int span = tmp[i] - tmp[i-1];
        if (span < shortSpan)
            shortSpan = span;
    }
    return (shortSpan);
}

int Span::longestSpan() const
{
	if(store.size() <= 2)
		throw std::out_of_range("Span less than 3 numbers");
    std::vector<int> tmp(store);       // copia del vector
    std::sort(tmp.begin(), tmp.end()); // ordina - funzione membro di algorithm

    int minSpan = tmp[0];
    int maxSpan = tmp[1];

    for (size_t i = 1; i < tmp.size(); ++i)
	{
        if (tmp[i] < minSpan)
            minSpan = tmp[i];
        else if (tmp[i] > maxSpan)
            maxSpan = tmp[i];
    }
    int longSpan = maxSpan - minSpan;
    return (longSpan);
}

