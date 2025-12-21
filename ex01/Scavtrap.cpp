/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 00:55:15 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Scavtrap.hpp"
#include "iostream"

ScavTrap::ScavTrap() : Claptrap()
{
    this->_hitpoint = 100;
    this->_energypoint = 50;
    this->_attackdmg = 20;
    std::cout << CYAN << "ScavTrap default constructor called"
              << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : Claptrap(name)
{
    this->_hitpoint = 100;
    this->_energypoint = 50;
    this->_attackdmg = 20;
    std::cout << CYAN << "ScavTrap " << GREEN << this->_name
              << " parametarized constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : Claptrap(copy)
{
    std::cout << CYAN << "ScavTrap " << GREEN << this->_name
              << " copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
    Claptrap::operator=(copy);
    std::cout << CYAN << "ScavTrap " << GREEN << this->_name
              << " copy assignment operator called" << RESET << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << RED << " Destructor called on ScavTrap "
              << GREEN << this->_name << RESET << std::endl;
}
