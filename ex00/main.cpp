/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:50:00 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 00:04:19 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include <iostream>

int main()
{
    std::cout << GREEN << "=== Test 1: Basic Constructor ===" << RESET << std::endl;
    Claptrap clap1("Bob");

    std::cout << GREEN << "=== Test 2: Default Constructor ===" << RESET << std::endl;
    Claptrap clap2;

    std::cout << GREEN << "=== Test 3: Copy Constructor ===" << RESET << std::endl;
    Claptrap clap3(clap1);

    std::cout << GREEN << "=== Test 4: Assignment Operator ===" << RESET << std::endl;
    Claptrap clap4("Alice");
    clap4 = clap1;

    std::cout << GREEN << "=== Test 5: Basic Attack ===" << RESET << std::endl;
    clap1.attack("target dummy");

    std::cout << GREEN << "=== Test 6: Basic Repair ===" << RESET << std::endl;
    clap1.beRepaired(5);

    std::cout << GREEN << "=== Test 7: Take Damage ===" << RESET << std::endl;
    clap1.takeDamage(8);

    std::cout << GREEN << "=== Test 8: Multiple Actions (Energy Depletion) ===" << RESET << std::endl;
    Claptrap energyTest("EnergyBoy");
    for (int i = 0; i < 12; i++)
    {
        std::cout << "Action " << i + 1 << ": ";
        energyTest.attack("enemy");
    }

    std::cout << GREEN << "=== Test 9: Death Test ===" << RESET << std::endl;
    Claptrap deadTest("DeadMan");
    deadTest.takeDamage(10);  // Should die
    deadTest.attack("ghost");  // Can't attack when dead
    deadTest.beRepaired(5);    // Can't repair when dead
    deadTest.takeDamage(5);    // Already dead

    std::cout << GREEN << "=== Test 10: Repair After Damage ===" << RESET << std::endl;
    Claptrap healTest("Healer");
    healTest.takeDamage(7);
    healTest.beRepaired(3);
    healTest.attack("target");

    std::cout << GREEN << "=== Test 11: Overkill Damage ===" << RESET << std::endl;
    Claptrap overkill("Victim");
    overkill.takeDamage(50);  // More damage than HP

    std::cout << GREEN << "=== Test 12: Energy Depletion with Repair ===" << RESET << std::endl;
    Claptrap mixTest("Mixer");
    mixTest.attack("enemy1");
    mixTest.beRepaired(2);
    mixTest.attack("enemy2");
    mixTest.beRepaired(3);
    mixTest.attack("enemy3");
    mixTest.attack("enemy4");
    mixTest.attack("enemy5");
    mixTest.attack("enemy6");
    mixTest.attack("enemy7");
    mixTest.beRepaired(1);  // Should have 1 energy left
    mixTest.attack("enemy8");  // Should fail - no energy

    std::cout << GREEN << "=== Destructors will be called now ===" << RESET << std::endl;
    return 0;
}