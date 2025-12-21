/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 00:03:40 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include "iostream"

Claptrap::Claptrap()
    : _name("DefaultClaptrap"), _health(10), _energy(10), _dmg(0)
{
    std::cout << CYAN << "Default constructor called on " << this->_name << RESET << std::endl;
}

Claptrap::Claptrap(std::string name)
    : _name(name), _health(10), _energy(10), _dmg(0)
{
    std::cout << CYAN << "Paramaterized constructor called on " << this->_name << RESET << std::endl;
}

Claptrap::Claptrap(const Claptrap &copy)
    : _name(copy._name), _health(copy._health), _energy(copy._energy), _dmg(copy._dmg)
{
    std::cout << CYAN << "Copy constructor called on " << this->_name << RESET << std::endl;
}

Claptrap &Claptrap::operator=(const Claptrap &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_health = copy._health;
        this->_energy = copy._energy;
        this->_dmg = copy._dmg;
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
    if (this->_health == 0)
    {
        std::cout << YELLOW << "Claptrap " << this->_name
                  << " is already dead! (currently 0hp)" << RESET << std::endl;
        return;
    }
    if (this->_energy == 0)
    {
        std::cout << YELLOW << "Claptrap " << this->_name
                  << " doesnt have enough energy to attack" << RESET << std::endl;
        return;
    }
    this->_energy--;
    std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << target
              << ", causing " << this->_dmg << " points of damage!"
              << RESET << std::endl;
}

void Claptrap::takeDamage(unsigned int amount)
{
    if (this->_health == 0)
    {
        std::cout << YELLOW << "Claptrap " << this->_name
                  << " is already dead! (currently 0hp)" << RESET << std::endl;
        return;
    }
    if (amount >= this->_health)
        this->_health = 0;
    else
        this->_health -= amount;
    std::cout << YELLOW << "Claptrap " << this->_name << " takes " << amount
              << " dmg! Current hit point is " << this->_health << RESET << std::endl;
}

void Claptrap::beRepaired(unsigned int amount)
{
    if (this->_health == 0)
    {
        std::cout << YELLOW << "Claptrap " << this->_name
                  << " is already dead! (currently 0hp)" << RESET << std::endl;
        return;
    }
    if (this->_energy == 0)
    {
        std::cout << YELLOW << "Claptrap " << this->_name
                  << " doesnt have enough energy to repairs itself!" << RESET << std::endl;
        return;
    }
    this->_energy--;
    this->_health += amount;
    std::cout << YELLOW << "ClapTrap " << this->_name << " repairs itself for " << amount
              << " HP! Total HP: " << this->_health << RESET << std::endl;
}
