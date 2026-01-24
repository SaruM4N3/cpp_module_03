/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2026/01/24 20:33:17 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "iostream"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), _name("default")
{
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDmg = 30;
    if (DEBUG_MODE)
        std::cout << CYAN << "DiamondTrap default constructor called"
                  << RESET << std::endl;
};

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDmg = 30;
    if (DEBUG_MODE)
        std::cout << CYAN << "DiamondTrap " << GREEN << this->_name
                  << CYAN << " parameterized constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy), _name(copy._name)
{
    if (DEBUG_MODE)
        std::cout << CYAN << "DiamondTrap " << GREEN << this->_name
                  << CYAN << " copy constructor called" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    if (DEBUG_MODE)
        std::cout << CYAN << "DiamondTrap assignment operator called"
                  << RESET << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    if (DEBUG_MODE)
        std::cout << RED << " Destructor called on DiamondTrap "
                  << GREEN << this->_name << RESET << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << CYAN << "I am " << GREEN << this->_name
              << CYAN << " and my ClapTrap name is " << GREEN << ClapTrap::_name << RESET << std::endl;
}