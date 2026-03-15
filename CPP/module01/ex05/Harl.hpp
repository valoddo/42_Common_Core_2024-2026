/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:12:16 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/18 18:11:53 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#include <string>

class	Harl
{
	private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	public:
	void	complain(std::string level);
};

#endif