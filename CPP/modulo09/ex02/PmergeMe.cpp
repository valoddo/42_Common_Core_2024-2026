/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:32:02 by marvin            #+#    #+#             */
/*   Updated: 2026/02/24 18:32:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
        
PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(char** argv)
{
	int n;

	for(int i = 1; argv[i] !=NULL; i++)
	{
		n = parseNumber(argv[i]);
		vecContainer.push_back(n);
		deqContainer.push_back(n);
	}

	if(vecContainer.empty())
		throw std::runtime_error("Error: no input");
	if(checkDuplicates(vecContainer))
		throw std::runtime_error("Error: duplicate number");
}
        
PmergeMe::PmergeMe(const PmergeMe& o)
{
	vecContainer = o.vecContainer;
	deqContainer = o.deqContainer;
}
        
PmergeMe& PmergeMe::operator=(const PmergeMe& o)
{
	if(this != &o)
	{
		vecContainer = o.vecContainer;
		deqContainer = o.deqContainer;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

int PmergeMe::parseNumber(const std::string& str) const
{
    if (str.empty())
        throw std::runtime_error("Error: empty string");
    // Controlla che tutti i caratteri siano cifre
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            throw std::runtime_error("Error: non-digit character found");
    }
    // Converti stringa in numero
    long num = std::strtol(str.c_str(), NULL, 10);
    // Controlla intervallo
    if (num <= 0 || num > INT_MAX)
        throw std::runtime_error("Error: number out of range");
    return static_cast<int>(num);
}

template <typename Container>
bool PmergeMe::checkDuplicates(const Container& container) const
{
    std::vector<int> temp(container.begin(), container.end()); // copia in vector
    std::sort(temp.begin(), temp.end()); // ordina

    for (size_t i = 1; i < temp.size(); i++)
    {
        if (temp[i] == temp[i - 1])
            return true; // duplicato trovato
    }
    return false; // nessun duplicato
}

// Ford-Johnsons

void PmergeMe::sortVector(std::vector<int>& vec)
{
	std::vector<int> mainChain;

	if(vec.size() <= 1)
		return;
	// Dividi gli elementi in coppie consecutive dove il primo elemento e il piu piccolo
	for(size_t i = 0; i+1 < vec.size(); i+=2)
	{
		if(vec[i] > vec[i+1])
			std::swap(vec[i], vec[i+1]);
	}
	//Costruisci la main chain con tutti i maggiori della coppia, usando un ordinamento iniziale.
	for(size_t i = 1; i < vec.size(); i +=2) //parti dagli indici dispari perche sono i numeri piu grandi delle coppie
		mainChain.push_back(vec[i]);
	std::sort(mainChain.begin(),mainChain.end());
	//Inserisci i minori nelle posizioni corrette usando binary insertion.
	for (size_t i = 0; i + 1 < vec.size(); i += 2) // i = primi elementi delle coppie
	{
		size_t value = vec[i];
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
		mainChain.insert(it, value);
	}
	if(vec.size() % 2 != 0)
	{
		size_t last = vec.back();
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), last);
		mainChain.insert(it, last);
	}
	vec = mainChain;
}

void PmergeMe::sortDeque(std::deque<int>& deq)
{
	std::deque<int> mainChain;

	if(deq.size() <= 1)
		return;
	// Dividi gli elementi in coppie consecutive dove il primo elemento e il piu piccolo
	for(size_t i = 0; i+1 < deq.size(); i+=2)
	{
		if(deq[i] > deq[i+1])
			std::swap(deq[i], deq[i+1]);
	}
	//Costruisci la main chain con tutti i maggiori della coppia, usando un ordinamento iniziale.
	for(size_t i = 1; i < deq.size(); i +=2) //parrti dagli indici dispari perche sono i numeri piu grandi delle coppie
		mainChain.push_back(deq[i]);
	std::sort(mainChain.begin(),mainChain.end());
	//Inserisci i minori nelle posizioni corrette usando binary insertion.
	for (size_t i = 0; i + 1 < deq.size(); i += 2) // i = primi elementi delle coppie
	{
		size_t value = deq[i];
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
		mainChain.insert(it, value);
	}
	if(deq.size() % 2 != 0)
	{
		size_t last = deq.back();
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), last);
		mainChain.insert(it, last);
	}
	deq = mainChain;
}
