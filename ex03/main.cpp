/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:50:00 by zsonie            #+#    #+#             */
/*   Updated: 2026/01/24 20:32:25 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    if (!DEBUG_MODE)
        std::cout << std::endl
                  << RED << "FOR A FULL TEST PLS USE: make debug"
                  << std::endl;

    std::cout << GREEN << "\n========== DIAMONDTRAP TESTS ==========" << RESET << std::endl;

    std::cout << GREEN << "\n=== Test 1: DiamondTrap Construction (notice chaining order) ===" << RESET << std::endl;
    std::cout << YELLOW << "Expected order: ClapTrap -> FragTrap -> ScavTrap -> DiamondTrap" << RESET << std::endl;
    DiamondTrap diamond1("Hybrid");

    std::cout << GREEN << "\n=== Test 2: whoAmI() - Name Identity Test ===" << RESET << std::endl;
    std::cout << YELLOW << "Should show: 'Hybrid' and 'Hybrid_clap_name'" << RESET << std::endl;
    diamond1.whoAmI();

    std::cout << GREEN << "\n=== Test 3: Attack (should use ScavTrap's attack) ===" << RESET << std::endl;
    std::cout << YELLOW << "Should say: 'ScavTrap <name> attacks...'" << RESET << std::endl;
    diamond1.attack("enemy");
    diamond1.attack("another_enemy");

    std::cout << GREEN << "\n=== Test 4: DiamondTrap Attributes Test ===" << RESET << std::endl;
    std::cout << YELLOW << "HP: 100 (FragTrap), Energy: 50 (ScavTrap), Dmg: 30 (FragTrap)" << RESET << std::endl;
    DiamondTrap statsTest("StatsTest");
    statsTest.takeDamage(50); // Should survive (100 HP)
    statsTest.beRepaired(20);
    statsTest.takeDamage(70);  // Should die
    statsTest.attack("ghost"); // Can't attack when dead

    std::cout << GREEN << "\n=== Test 5: Inherited Special Abilities ===" << RESET << std::endl;
    DiamondTrap multiTalent("MultiTalent");
    std::cout << CYAN << "Testing ScavTrap's guardGate():" << RESET << std::endl;
    multiTalent.guardGate();
    std::cout << CYAN << "Testing FragTrap's highFivesGuys():" << RESET << std::endl;
    multiTalent.highFivesGuys();
    std::cout << CYAN << "Testing DiamondTrap's whoAmI():" << RESET << std::endl;
    multiTalent.whoAmI();

    std::cout << GREEN << "\n=== Test 6: Energy Depletion Test ===" << RESET << std::endl;
    DiamondTrap energyTest("EnergyTest");
    std::cout << YELLOW << "DiamondTrap has 50 energy points (from ScavTrap)" << RESET << std::endl;

    std::cout << GREEN << "Silenting the 50 next attacks" << RESET << std::endl;
    std::streambuf *old = std::cout.rdbuf(0);
    for (int i = 0; i < 50; i++)
    {
        std::cout << "Attack #" << i + 1 << ": ";
        energyTest.attack("target");
    }
    std::cout.rdbuf(old);
    energyTest.attack("target");

    std::cout << GREEN << "\n=== Test 7: Copy Constructor Test ===" << RESET << std::endl;
    std::cout << YELLOW << "Creating copy of 'Hybrid'" << RESET << std::endl;
    DiamondTrap diamond2(diamond1);
    std::cout << "NEXT LINE Should have same names" << std::endl;
    diamond2.whoAmI();
    diamond2.attack("copyTarget");

    std::cout << GREEN << "\n=== Test 8: Assignment Operator Test ===" << RESET << std::endl;
    DiamondTrap diamond3("Original");
    diamond3.whoAmI();
    std::cout << YELLOW << "Assigning 'Hybrid' to 'Original'" << RESET << std::endl;
    diamond3 = diamond1;
    std::cout << "NEXT LINE Should show new names" << std::endl;
    diamond3.whoAmI();

    std::cout << GREEN << "\n=== Test 9: Default Constructor ===" << RESET << std::endl;
    DiamondTrap defaultDiamond;
    defaultDiamond.whoAmI();
    defaultDiamond.attack("test");
    defaultDiamond.guardGate();
    defaultDiamond.highFivesGuys();

    std::cout << GREEN << "\n=== Test 10: Destruction Order ===" << RESET << std::endl;
    std::cout << YELLOW << "Expected order: ~DiamondTrap -> ~ScavTrap -> ~FragTrap -> ~ClapTrap" << RESET << std::endl;
    {
        DiamondTrap temp("Temporary");
        std::cout << MAGENTA << "Leaving scope - watch destruction order!" << RESET << std::endl;
    }

    std::cout << GREEN << "\n=== Test 11: Multiple DiamondTraps ===" << RESET << std::endl;
    DiamondTrap d1("Alpha");
    DiamondTrap d2("Beta");
    DiamondTrap d3("Gamma");
    d1.whoAmI();
    d2.whoAmI();
    d3.whoAmI();
    d1.attack("Beta");
    d2.attack("Gamma");
    d3.attack("Alpha");

    std::cout << GREEN << "\n=== Test 12: Name Shadowing Verification ===" << RESET << std::endl;
    std::cout << YELLOW << "This verifies that DiamondTrap._name and ClapTrap._name are different" << RESET << std::endl;
    DiamondTrap shadowTest("Shadow");
    std::cout << "NEXT LINE Should show 'Shadow' and 'Shadow_clap_name'" << std::endl;
    shadowTest.whoAmI();

    if (DEBUG_MODE)
        std::cout << GREEN << "\n=== Final Destructors (main scope cleanup) ===" << RESET << std::endl;
    return 0;
}