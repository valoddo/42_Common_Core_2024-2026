/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:20:33 by marvin            #+#    #+#             */
/*   Updated: 2026/01/17 18:20:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"

Base* generate(void)
{
	int x;

	std::srand(std::time(0));
	x = std::rand() % 3;
	switch(x)
	{
		case 0 : return new A();
		case 1 : return new B();
		case 2 : return new C();
		default: return NULL;
	}

}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "A\n" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "B\n" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "C\n" << std::endl;
	
}

void identify(Base& p)
{
	try
	{
		p = dynamic_cast<A&>(p);
			std::cout << "A\n";
	}
	catch(std::bad_cast&){}
	try
	{
		p = dynamic_cast<B&>(p);
			std::cout << "B\n";
	}
	catch(std::bad_cast&){}
	try
	{
		p = dynamic_cast<C&>(p);
			std::cout << "C\n";
	}
	catch(std::bad_cast&){}
}

