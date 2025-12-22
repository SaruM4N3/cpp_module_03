/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/23 00:21:16 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "iostream"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDmg = 20;
    std::cout << CYAN << "ScavTrap default constructor called"
              << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDmg = 20;
    std::cout << BLUE << "ScavTrap " << GREEN << this->_name
              << CYAN << " parameterized constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << BLUE << "ScavTrap " << GREEN << this->_name
              << CYAN << " copy constructor called" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    ClapTrap::operator=(copy);
    std::cout << BLUE << "ScavTrap " << GREEN << this->_name
              << CYAN << " copy assignment operator called" << RESET << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << RED << "Destructor called on "<< BLUE << "ScavTrap "
              << GREEN << this->_name << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_hitPoint == 0)
    {
        std::cout << BLUE << "ScavTrap " << GREEN << this->_name
                  << YELLOW << " is dead!" << RESET << std::endl;
        return;
    }
    if (this->_energyPoint == 0)
    {
        std::cout << BLUE << "ScavTrap " << GREEN << this->_name
                  << YELLOW << " has no energy!" << RESET << std::endl;
        return;
    }
    this->_energyPoint--;
    std::cout << BLUE << "ScavTrap " << GREEN << this->_name
              << YELLOW << " attacks " << GREEN << target
              << YELLOW << ", causing " << CYAN << this->_attackDmg
              << YELLOW << " points of damage!" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << BLUE << "ScavTrap " << GREEN << this->_name 
              << CYAN << " is now in Gate keeper mode!" << RESET << std::endl;
}
