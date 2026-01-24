/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:50:00 by zsonie            #+#    #+#             */
/*   Updated: 2026/01/24 19:34:59 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    if (!DEBUG_MODE)
        std::cout << std::endl
                  << RED << "FOR A FULL TEST PLS USE: make debug"
                  << std::endl;
    
    std::cout << GREEN << "\n========== SCAVTRAP TESTS ==========" << RESET << std::endl;
    std::cout << GREEN << "\n=== Test 1: ScavTrap construct and actions ===" << RESET << std::endl;
    ScavTrap scav1("Guardian");
    scav1.attack("intruder");
    scav1.attack("intruder2");
    scav1.guardGate();

    std::cout << GREEN << "\n=== Test 2: ClapTrap vs ScavTrap ===" << RESET << std::endl;
    ClapTrap weakling("Weakling");
    ScavTrap strong("Terminator");
    weakling.attack("target");
    strong.attack("target");

    std::cout << GREEN << "\n=== Test 3: ScavTrap Energy (50 energy) ===" << RESET << std::endl;
    ScavTrap energyScav("EnergyScav");
    std::cout << GREEN << "Silenting the 50 next attacks" << RESET << std::endl;
    std::streambuf *old = std::cout.rdbuf(0);
    for (int i = 0; i < 50; i++)
        energyScav.attack("enemy");
    std::cout.rdbuf(old);
    energyScav.attack("enemy");

    std::cout << GREEN << "\n=== Test 4: Copy & Assignment ===" << RESET << std::endl;
    ScavTrap scav2(scav1);
    scav2.guardGate();
    ScavTrap scav3("TempScav");
    scav3 = scav1;

    std::cout << GREEN << "\n=== Test 5: ScavTrap Death ===" << RESET << std::endl;
    ScavTrap deadScav("DeadScav");
    deadScav.takeDamage(100);
    deadScav.attack("ghost");
    deadScav.guardGate();

    if (DEBUG_MODE)
        std::cout << GREEN << "\n=== Destructors ===" << RESET << std::endl;
    return 0;
}