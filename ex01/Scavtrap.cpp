/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 01:04:55 by zsonie           ###   ########lyon.fr   */
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
              << CYAN << " parameterized constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : Claptrap(copy)
{
    std::cout << CYAN << "ScavTrap " << GREEN << this->_name
              << CYAN << " copy constructor called" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    Claptrap::operator=(copy);
    std::cout << CYAN << "ScavTrap " << GREEN << this->_name
              << CYAN << " copy assignment operator called" << RESET << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << RED << " Destructor called on ScavTrap "
              << GREEN << this->_name << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_hitpoint == 0)
    {
        std::cout << YELLOW << "ScavTrap " << GREEN << this->_name
                  << YELLOW << " is dead!" << RESET << std::endl;
        return;
    }
    if (this->_energypoint == 0)
    {
        std::cout << YELLOW << "ScavTrap " << GREEN << this->_name
                  << YELLOW << " has no energy!" << RESET << std::endl;
        return;
    }
    this->_energypoint--;
    std::cout << YELLOW << "ScavTrap " << GREEN << this->_name
              << YELLOW << " attacks " << GREEN << target
              << YELLOW << ", causing " << CYAN << this->_attackdmg
              << YELLOW << " points of damage!" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << CYAN << "ScavTrap " << GREEN << this->_name 
              << CYAN << " is now in Gate keeper mode!" << RESET << std::endl;
}
