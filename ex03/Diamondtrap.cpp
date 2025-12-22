/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diamondtrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 23:07:14 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fragtrap.hpp"
#include "iostream"

DiamondTrap::DiamondTrap() : Claptrap()
{
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDmg = 30;
    std::cout << CYAN << "DiamondTrap default constructor called"
              << RESET << std::endl;
};

DiamondTrap::DiamondTrap(std::string name) : Claptrap(name)
{
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDmg = 30;
    std::cout << CYAN << "DiamondTrap " << GREEN << this->_name
              << CYAN << " parameterized constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : Claptrap(copy)
{
    std::cout << CYAN << "DiamondTrap " << GREEN << this->_name
              << CYAN << " copy constructor called" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    Claptrap::operator=(copy);
    std::cout << CYAN << "DiamondTrap " << GREEN << this->_name
              << CYAN << " copy assignment operator called" << RESET << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED << " Destructor called on DiamondTrap "
              << GREEN << this->_name << RESET << std::endl;
}
