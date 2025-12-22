/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/23 00:27:44 by zsonie           ###   ########lyon.fr   */
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
    std::cout << BLUE << "FragTrap " << GREEN << this->_name
              << CYAN << " parameterized constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << BLUE << "FragTrap " << GREEN << this->_name
              << CYAN << " copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    ClapTrap::operator=(copy);
    std::cout << BLUE << "FragTrap " << GREEN << this->_name
              << CYAN << " copy assignment operator called" << RESET << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << RED << "Destructor called on " << BLUE << "FragTrap "
              << GREEN << this->_name << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (this->_hitPoint == 0)
    {
        std::cout << BLUE << "FragTrap " << GREEN << this->_name
                  << BLUE << " can highfives even dead!" << RESET << std::endl;
        return;
    }
    std::cout << BLUE << "FragTrap " << GREEN << this->_name
              << BLUE << " is asking for a highfives" << RESET << std::endl;
    return;
}