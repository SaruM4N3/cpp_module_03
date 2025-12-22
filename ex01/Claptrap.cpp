/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 23:07:14 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include "iostream"

Claptrap::Claptrap()
    : _name("DefaultClaptrap"), _hitPoint(10), _energyPoint(10), _attackDmg(0)
{
    std::cout << CYAN << "Default constructor called on " << GREEN << this->_name << RESET << std::endl;
}

Claptrap::Claptrap(std::string name)
    : _name(name), _hitPoint(10), _energyPoint(10), _attackDmg(0)
{
    std::cout << CYAN << "Paramaterized constructor called on " << GREEN << this->_name << RESET << std::endl;
}

Claptrap::Claptrap(const Claptrap &copy)
    : _name(copy._name), _hitPoint(copy._hitPoint), _energyPoint(copy._energyPoint), _attackDmg(copy._attackDmg)
{
    std::cout << CYAN << "Copy constructor called on " << GREEN << this->_name << RESET << std::endl;
}

Claptrap &Claptrap::operator=(const Claptrap &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoint = copy._hitPoint;
        this->_energyPoint = copy._energyPoint;
        this->_attackDmg = copy._attackDmg;
    }
    std::cout << CYAN << "Copy assignment operator called on " << GREEN << this->_name << RESET << std::endl;
    return *this;
}

Claptrap::~Claptrap()
{
    std::cout << RED << "Destructor called on " << GREEN << this->_name << RESET << std::endl;
}

void Claptrap::attack(const std::string &target)
{
    if (this->_hitPoint == 0)
    {
        std::cout << YELLOW << "Claptrap " << GREEN << this->_name
                  << YELLOW << " is already dead! (currently 0hp)" << RESET << std::endl;
        return;
    }
    if (this->_energyPoint == 0)
    {
        std::cout << YELLOW << "Claptrap " << GREEN << this->_name
                  << YELLOW << " doesnt have enough energy to attack" << RESET << std::endl;
        return;
    }
    this->_energyPoint--;
    std::cout << YELLOW << "ClapTrap " << GREEN << this->_name
              << YELLOW << " attacks " << GREEN << target
              << YELLOW << ", causing " << CYAN << this->_attackDmg 
              << YELLOW << " points of damage!"
              << RESET << std::endl;
}

void Claptrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoint == 0)
    {
        std::cout << YELLOW << "Claptrap " << GREEN << this->_name
                  << YELLOW << " is already dead! (currently 0hp)" << RESET << std::endl;
        return;
    }
    if (amount >= this->_hitPoint)
        this->_hitPoint = 0;
    else
        this->_hitPoint -= amount;
    std::cout << YELLOW << "Claptrap " << GREEN << this->_name << " takes " << CYAN << amount
              << YELLOW << " dmg! Current hit point is " << CYAN << this->_hitPoint << RESET << std::endl;
}

void Claptrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoint == 0)
    {
        std::cout << YELLOW << "Claptrap " << GREEN << this->_name
                  << YELLOW << " is already dead! (currently 0hp)" << RESET << std::endl;
        return;
    }
    if (this->_energyPoint == 0)
    {
        std::cout << YELLOW << "Claptrap " << GREEN << this->_name
                  << YELLOW << " doesnt have enough energy to repairs itself!" << RESET << std::endl;
        return;
    }
    this->_energyPoint--;
    this->_hitPoint += amount;
    std::cout << YELLOW << "ClapTrap " << GREEN << this->_name
              << YELLOW << " repairs itself for " << CYAN << amount
              << YELLOW << " HP! Total HP: " << CYAN << this->_hitPoint << RESET << std::endl;
}
