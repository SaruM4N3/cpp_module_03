/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:42 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 23:07:14 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class Claptrap
{
protected:
	std::string _name;
	unsigned int _hitPoint;
	unsigned int _energyPoint;
	unsigned int _attackDmg;

public:
	Claptrap();
	Claptrap(std::string name);
	Claptrap(const Claptrap &copy);
	Claptrap &operator=(const Claptrap &copy);
	~Claptrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
