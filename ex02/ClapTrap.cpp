/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:32 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/23 00:09:23 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "iostream"

ClapTrap::ClapTrap()
    : _name("DefaultClapTrap"), _hitPoint(10), _energyPoint(10), _attackDmg(0)
{
    std::cout << CYAN << "Default constructor called on "
              << GREEN << this->_name
              << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoint(10), _energyPoint(10), _attackDmg(0)
{
    std::cout << CYAN << "Paramaterized constructor called on "
              << GREEN << this->_name
              << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
    : _name(copy._name), _hitPoint(copy._hitPoint), _energyPoint(copy._energyPoint), _attackDmg(copy._attackDmg)
{
    std::cout << CYAN << "Copy constructor called on "
              << GREEN << this->_name
              << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoint = copy._hitPoint;
        this->_energyPoint = copy._energyPoint;
        this->_attackDmg = copy._attackDmg;
    }
    std::cout << CYAN << "Copy assignment operator called on "
              << GREEN << this->_name
              << RESET << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << RED << "Destructor called on "
              << GREEN << this->_name
              << RESET << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_hitPoint == 0)
    {
        std::cout << BLUE << "ClapTrap "
                  << GREEN << this->_name
                  << YELLOW << " try an attack but cannot"
                  << RED << " because already dead!"
                  << RESET << std::endl;
        return;
    }
    if (this->_energyPoint == 0)
    {
        std::cout << BLUE << "ClapTrap "
                  << GREEN << this->_name
                  << YELLOW << " try an attack but cannot"
                  << RED << " doesnt have enough energy to attack"
                  << RESET << std::endl;
        return;
    }
    this->_energyPoint--;
    std::cout << BLUE << "ClapTrap "
              << GREEN << this->_name
              << YELLOW << " attacks "
              << GREEN << target
              << YELLOW << ", causing "
              << CYAN << this->_attackDmg
              << YELLOW << " points of damage!"
              << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoint == 0)
    {
        std::cout << BLUE << "ClapTrap "
                  << GREEN << this->_name
                  << YELLOW << " cannot take damage"
                  << RED << " because already dead!"
                  << RESET << std::endl;
        return;
    }
    if (amount >= this->_hitPoint)
        this->_hitPoint = 0;
    else
        this->_hitPoint -= amount;
    std::cout << BLUE << "ClapTrap "
              << GREEN << this->_name
              << YELLOW << " takes "
              << CYAN << amount
              << YELLOW << " dmg! Current hitPoint: "
              << CYAN << this->_hitPoint
              << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoint == 0)
    {
        std::cout << BLUE << "ClapTrap "
                  << GREEN << this->_name
                  << YELLOW << " cannot repair"
                  << RED << " because already dead!"
                  << RESET << std::endl;
        return;
    }
    if (this->_energyPoint == 0)
    {
        std::cout << BLUE << "ClapTrap "
                  << GREEN << this->_name
                  << YELLOW << " doesnt have enough energy to repairs itself!"
                  << RESET << std::endl;
        return;
    }
    this->_energyPoint--;
    this->_hitPoint += amount;
    std::cout << BLUE << "ClapTrap "
              << GREEN << this->_name
              << YELLOW << " repairs itself for "
              << CYAN << amount
              << YELLOW << " HP!"
              << std::endl
              << MAGENTA << "Current HP: "
              << CYAN << this->_hitPoint
              << RESET << std::endl;
}
