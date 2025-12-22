/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:50:00 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 01:11:04 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Scavtrap.hpp"
#include <iostream>

int main()
{
    std::cout << GREEN << "\n========== CLAPTRAP TESTS ==========" << RESET << std::endl;
    
    std::cout << GREEN << "\n=== Test 1: Basic Constructor ===" << RESET << std::endl;
    Claptrap clap1("MONKEYTRAP");

    std::cout << GREEN << "\n=== Test 2: Attack & Repair ===" << RESET << std::endl;
    clap1.attack("RANDOMTRAP");
    clap1.beRepaired(5);
    clap1.takeDamage(8);

    std::cout << GREEN << "\n=== Test 3: Energy Depletion (10 energy) ===" << RESET << std::endl;
    Claptrap energyTest("EnergyTrap");
    for (int i = 0; i < 3; i++)
        energyTest.attack("enemy");
    std::cout << "... (7 more attacks silently)" << std::endl;
    for (int i = 0; i < 7; i++)
        energyTest.attack("enemy");  // Silent loop
    std::cout << "Last attack:" << std::endl;
    energyTest.attack("enemy");  // Should fail - no energy

    std::cout << GREEN << "\n=== Test 4: Death Test ===" << RESET << std::endl;
    Claptrap deadTest("DeadTrap");
    deadTest.takeDamage(10);
    deadTest.attack("ghost");

    std::cout << GREEN << "\n========== SCAVTRAP TESTS ==========" << RESET << std::endl;
    
    std::cout << GREEN << "\n=== Test 5: ScavTrap Construction ===" << RESET << std::endl;
    ScavTrap scav1("Guardian");

    std::cout << GREEN << "\n=== Test 6: ScavTrap Attack (20 dmg!) ===" << RESET << std::endl;
    scav1.attack("intruder");
    scav1.attack("intruder2");

    std::cout << GREEN << "\n=== Test 7: Guard Gate Mode ===" << RESET << std::endl;
    scav1.guardGate();

    std::cout << GREEN << "\n=== Test 8: ClapTrap vs ScavTrap ===" << RESET << std::endl;
    Claptrap weakling("Weakling");
    ScavTrap strong("Terminator");
    weakling.attack("target");  // 0 dmg
    strong.attack("target");    // 20 dmg!

    std::cout << GREEN << "\n=== Test 9: ScavTrap Energy (50 energy) ===" << RESET << std::endl;
    ScavTrap energyScav("EnergyScav");
    std::cout << "First 3 attacks:" << std::endl;
    for (int i = 0; i < 3; i++)
        energyScav.attack("enemy");
    std::cout << "... (attacking 44 more times silently) ..." << std::endl;
    for (int i = 0; i < 44; i++)
        energyScav.attack("enemy");  // Silent loop
    std::cout << "Final 3 attacks:" << std::endl;
    energyScav.attack("enemy");  // 48
    energyScav.attack("enemy");  // 49
    energyScav.attack("enemy");  // 50
    energyScav.attack("enemy");  // Should fail

    std::cout << GREEN << "\n=== Test 10: Copy & Assignment ===" << RESET << std::endl;
    ScavTrap scav2(scav1);
    scav2.guardGate();
    ScavTrap scav3("TempScav");
    scav3 = scav1;

    std::cout << GREEN << "\n=== Test 11: ScavTrap Death ===" << RESET << std::endl;
    ScavTrap deadScav("DeadScav");
    deadScav.takeDamage(100);
    deadScav.attack("ghost");
    deadScav.guardGate();

    std::cout << GREEN << "\n=== Destructors ===" << RESET << std::endl;
    return 0;
}