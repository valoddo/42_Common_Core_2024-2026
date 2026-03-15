/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:10:34 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/04 19:19:59 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	const Animal* j = new Dog();
	const Animal* y = new Cat();
	int x = 5;
	
	const Animal* array[x];
	for (int i = 0; i < x; i++)
	{
		if (i % 2 == 0)
			array[i] = new Cat();
		else 
			array[i] = new Dog();
	}
	for (int i = 0; i < x; ++i)
	{
		std::cout << array[i]->getType() << " ";
		array[i]->makeSound();
	}
	for (int i = 0; i < x; i++)
	{ 
		if (array[i]->getType() == "🐱 Cat") {
			const Cat* cat = static_cast<const Cat*>(array[i]);
			for (int a = 0; a < 3; a++)
				cat->printIdea(a);
		} else if (array[i]->getType() == "🐶 Dog")
		{
			const Dog* dog = static_cast<const Dog*>(array[i]);
			for (int a = 0; a < 3; a++)
				dog->printIdea(a);
		}
	}
	delete j;
	delete y;
	for (int i = 0; i < x; i++)
		delete array[i];
}
