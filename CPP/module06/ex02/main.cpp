/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:20:33 by marvin            #+#    #+#             */
/*   Updated: 2026/01/26 15:14:58 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Classes.hpp"

int main()
{
    Base* obj;

    obj = generate();
    std::cout << "identify(Base*): ";
    identify(obj);
    std::cout << "identify(Base&): ";
    identify(*obj);

    delete (obj);
    return (0);
}
