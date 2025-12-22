/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 23:34:20 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "iostream"

DiamondTrap::DiamondTrap() : ClapTrap()
{
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDmg = 30;
    std::cout << CYAN << "DiamondTrap default constructor called"
              << RESET << std::endl;
};

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDmg = 30;
    std::cout << CYAN << "DiamondTrap " << GREEN << this->_name
              << CYAN << " parameterized constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy)
{
    std::cout << CYAN << "DiamondTrap " << GREEN << this->_name
              << CYAN << " copy constructor called" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    ClapTrap::operator=(copy);
    std::cout << CYAN << "DiamondTrap " << GREEN << this->_name
              << CYAN << " copy assignment operator called" << RESET << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED << " Destructor called on DiamondTrap "
              << GREEN << this->_name << RESET << std::endl;
}
