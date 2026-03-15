/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:23:08 by marvin            #+#    #+#             */
/*   Updated: 2026/02/21 17:23:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>  // per sort
#include <stdexcept>  // per runtime_error

class PmergeMe
{
	private:
		std::vector<int> vecContainer; // memoria contigua, elementi memorizzati uno dopo l'altro in un unico blocco di memoria
		std::deque<int> deqContainer; // memoria segmentata, blocchi separati di memoria collegati tra loro elementi inseriti all'inizio/fine
   public:
		void sortVector(std::vector<int>& vec);
		void sortDeque(std::deque<int>& deq);
		PmergeMe();
		PmergeMe(char** argv);
		PmergeMe(const PmergeMe& o);
		PmergeMe& operator=(const PmergeMe& o);
		~PmergeMe();
		int  parseNumber(const std::string& str) const;
		template <typename Container>
		bool checkDuplicates(const Container& container) const;
		const std::vector<int>& getVector() const { return vecContainer; }
		const std::deque<int>& getDeque() const { return deqContainer; }
};

#endif
