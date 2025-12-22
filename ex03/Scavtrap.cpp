/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 23:07:14 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Scavtrap.hpp"
#include "iostream"

ScavTrap::ScavTrap() : Claptrap()
{
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDmg = 20;
    std::cout << CYAN << "ScavTrap default constructor called"
              << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : Claptrap(name)
{
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDmg = 20;
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
