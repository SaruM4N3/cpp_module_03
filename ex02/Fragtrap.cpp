/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 22:55:23 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fragtrap.hpp"
#include "iostream"

FragTrap::FragTrap() : Claptrap()
{
    this->_hitpoint = 100;
    this->_energypoint = 100;
    this->_attackdmg = 30;
    std::cout << CYAN << "FragTrap default constructor called"
              << RESET << std::endl;
};

FragTrap::FragTrap(std::string name) : Claptrap(name)
{
    this->_hitpoint = 100;
    this->_energypoint = 100;
    this->_attackdmg = 30;
    std::cout << CYAN << "FragTrap " << GREEN << this->_name
              << CYAN << " parameterized constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : Claptrap(copy)
{
    std::cout << CYAN << "FragTrap " << GREEN << this->_name
              << CYAN << " copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    Claptrap::operator=(copy);
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