/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 00:15:25 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include "iostream"

Claptrap::Claptrap()
    : _name("DefaultClaptrap"), _hitpoint(10), _energypoint(10), _attackdmg(0)
{
    std::cout << CYAN << "Default constructor called on " << this->_name << RESET << std::endl;
}

Claptrap::Claptrap(std::string name)
    : _name(name), _hitpoint(10), _energypoint(10), _attackdmg(0)
{
    std::cout << CYAN << "Paramaterized constructor called on " << this->_name << RESET << std::endl;
}

Claptrap::Claptrap(const Claptrap &copy)
    : _name(copy._name), _hitpoint(copy._hitpoint), _energypoint(copy._energypoint), _attackdmg(copy._attackdmg)
{
    std::cout << CYAN << "Copy constructor called on " << this->_name << RESET << std::endl;
}

Claptrap &Claptrap::operator=(const Claptrap &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitpoint = copy._hitpoint;
        this->_energypoint = copy._energypoint;
        this->_attackdmg = copy._attackdmg;
    }
    std::cout << CYAN << "Copy assignment operator called on " << this->_name << RESET << std::endl;
    return *this;
}

Claptrap::~Claptrap()
{
    std::cout << RED << "Destructor called on " << this->_name << RESET << std::endl;
}

void Claptrap::attack(const std::string &target)
{
    if (this->_hitpoint == 0)
    {
        std::cout << YELLOW << "Claptrap " << this->_name
                  << " is already dead! (currently 0hp)" << RESET << std::endl;
        return;
    }
    if (this->_energypoint == 0)
    {
        std::cout << YELLOW << "Claptrap " << this->_name
                  << " doesnt have enough energy to attack" << RESET << std::endl;
        return;
    }
    this->_energypoint--;
    std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackdmg << " points of damage!"
              << RESET << std::endl;
}

void Claptrap::takeDamage(unsigned int amount)
{
    if (this->_hitpoint == 0)
    {
        std::cout << YELLOW << "Claptrap " << this->_name
                  << " is already dead! (currently 0hp)" << RESET << std::endl;
        return;
    }
    if (amount >= this->_hitpoint)
        this->_hitpoint = 0;
    else
        this->_hitpoint -= amount;
    std::cout << YELLOW << "Claptrap " << this->_name << " takes " << amount
              << " dmg! Current hit point is " << this->_hitpoint << RESET << std::endl;
}

void Claptrap::beRepaired(unsigned int amount)
{
    if (this->_hitpoint == 0)
    {
        std::cout << YELLOW << "Claptrap " << this->_name
                  << " is already dead! (currently 0hp)" << RESET << std::endl;
        return;
    }
    if (this->_energypoint == 0)
    {
        std::cout << YELLOW << "Claptrap " << this->_name
                  << " doesnt have enough energy to repairs itself!" << RESET << std::endl;
        return;
    }
    this->_energypoint--;
    this->_hitpoint += amount;
    std::cout << YELLOW << "ClapTrap " << this->_name << " repairs itself for " << amount
              << " HP! Total HP: " << this->_hitpoint << RESET << std::endl;
}
