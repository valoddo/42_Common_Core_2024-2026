/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:51:43 by marvin            #+#    #+#             */
/*   Updated: 2026/01/17 17:51:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data d;
    d.numb = 42;
    d.unsignNumb = 100;

    Data* ptrOriginale = &d;
    uintptr_t raw = Serializer::serialize(ptrOriginale);
    Data* ptrRecuperato = Serializer::deserialize(raw);

    if (ptrRecuperato == ptrOriginale)
        std::cout << "Funziona! I puntatori sono uguali." << std::endl;
    else
        std::cout << "Errore: puntatori diversi!" << std::endl;

    std::cout << "Valore originale: numb = " << ptrOriginale->numb << ", unsignnumb = " << ptrOriginale->unsignNumb << std::endl;
    std::cout << "Valore recuperato: numb = " << ptrRecuperato->numb << ", unsignnumb = " << ptrRecuperato->unsignNumb << std::endl;

    return (0);
}
