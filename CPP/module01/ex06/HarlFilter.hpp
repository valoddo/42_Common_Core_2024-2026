/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:12:16 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/18 18:12:08 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARLFILTER_HPP
#define HARLFILTER_HPP
#include <iostream>
#include <string>

class	Harl
{
	public:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif