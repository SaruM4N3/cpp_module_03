/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2026/01/24 19:43:23 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "iostream"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDmg = 20;
    if (DEBUG_MODE)
        std::cout << CYAN << "ScavTrap default constructor called"
                  << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDmg = 20;
    if (DEBUG_MODE)
        std::cout << CYAN << "ScavTrap " << GREEN << this->_name
                  << CYAN << " parameterized constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    if (DEBUG_MODE)
        std::cout << CYAN << "ScavTrap " << GREEN << this->_name
                  << CYAN << " copy constructor called" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    ClapTrap::operator=(copy);
    if (DEBUG_MODE)
        std::cout << CYAN << "ScavTrap " << GREEN << this->_name
                  << CYAN << " copy assignment operator called" << RESET << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    if (DEBUG_MODE)
        std::cout << RED << " Destructor called on ScavTrap "
                  << GREEN << this->_name << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_hitPoint == 0)
    {
        std::cout << YELLOW << "ScavTrap " << GREEN << this->_name
                  << YELLOW << " is dead!" << RESET << std::endl;
        return;
    }
    if (this->_energyPoint == 0)
    {
        std::cout << YELLOW << "ScavTrap " << GREEN << this->_name
                  << YELLOW << " has no energy!" << RESET << std::endl;
        return;
    }
    this->_energyPoint--;
    std::cout << YELLOW << "ScavTrap " << GREEN << this->_name
              << YELLOW << " attacks " << GREEN << target
              << YELLOW << ", causing " << CYAN << this->_attackDmg
              << YELLOW << " points of damage!" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << CYAN << "ScavTrap " << GREEN << this->_name
              << CYAN << " is now in Gate keeper mode!" << RESET << std::endl;
}

unsigned int ScavTrap::getScavEnergyPoints() const
{
    return this->_energyPoint;
}
