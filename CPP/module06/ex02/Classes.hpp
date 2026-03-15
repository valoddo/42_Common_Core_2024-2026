/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:17:39 by marvin            #+#    #+#             */
/*   Updated: 2026/01/17 18:17:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP
#include "Base.hpp"
#include <cstdlib> // per rand(), srand()
#include <ctime>   // per time
#include <typeinfo>  // serve per std::bad_cast

class	A : public Base{};
class	B : public Base{};
class	C : public Base{};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif