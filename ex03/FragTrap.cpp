/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2026/01/05 20:07:50 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "iostream"

FragTrap::FragTrap() : ClapTrap()
{
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDmg = 30;
    std::cout << CYAN << "FragTrap default constructor called"
              << RESET << std::endl;
};

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDmg = 30;
    std::cout << CYAN << "FragTrap " << GREEN << this->_name
              << CYAN << " parameterized constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << CYAN << "FragTrap " << GREEN << this->_name
              << CYAN << " copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    ClapTrap::operator=(copy);
    std::cout << CYAN << "FragTrap " << GREEN << this->_name
              << CYAN << " copy assignment operator called" << RESET << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << RED << " Destructor called on FragTrap "
              << GREEN << this->_name << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
      std::cout << BLUE << "FragTrap " << GREEN << this->_name
              << BLUE << " is asking for a highfives" << RESET << std::endl;
    return;
}

unsigned int FragTrap::getFragHitPoints() const
{
    return this->_hitPoint;
}

unsigned int FragTrap::getFragAttackDmg() const
{
    return this->_attackDmg;
}
