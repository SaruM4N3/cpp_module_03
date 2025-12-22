/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:50:00 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/23 00:14:43 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << GREEN << "\n========== CLAPTRAP TESTS ==========" << RESET << std::endl;
    std::cout << GREEN << "=== Test 1: Constructors and assignment ===" << RESET << std::endl;
    ClapTrap clap1("MONKEYTRAP");
    ClapTrap clap2;
    ClapTrap clap3(clap1);
    ClapTrap clap4("MANTRAP");
    clap4 = clap1;

    std::cout << std::endl;
    std::cout << GREEN << "=== Test 2: Basic Actions ===" << RESET << std::endl;
    clap1.attack("RANDOMTRAP");
    clap1.beRepaired(5);
    clap1.takeDamage(8);

    std::cout << std::endl;
    std::cout << GREEN << "=== Test 3: Multiple Actions (Energy Depletion) ===" << RESET << std::endl;
    ClapTrap energyTest("EnergyTrap");
    std::cout << GREEN << "Silenting the 10 next attacks" << RESET << std::endl;
    std::streambuf *old = std::cout.rdbuf(0);
    for (int i = 0; i < 10; i++)
        energyTest.attack("EnergyVampireTrap");
    std::cout.rdbuf(old);
    std::cout << "Action after energy lost :" << std::endl;
    energyTest.attack("EnergyVampireTrap");

    std::cout << std::endl;
    std::cout << GREEN << "=== Test 4: Death Test ===" << RESET << std::endl;
    ClapTrap deadTest("DeadManTrap");
    std::cout << "Next should die : " << std::endl;
    deadTest.takeDamage(10);
    std::cout << "Cant attack cause dead : " << std::endl;
    deadTest.attack("RandomTrap");
    std::cout << "Cant repair cause dead : " << std::endl;
    deadTest.beRepaired(5);
    std::cout << "already dead cannot take dmg : " << std::endl;
    deadTest.takeDamage(5);

    std::cout << std::endl;
    std::cout << GREEN << "=== Test 5: Repair After Damage ===" << RESET << std::endl;
    ClapTrap healTest("HealerTrap");
    healTest.takeDamage(7);
    healTest.beRepaired(3);
    healTest.attack("targetTrap");

    std::cout << std::endl;
    std::cout << GREEN << "=== Destructors will be called now ===" << RESET << std::endl;
    return 0;
}