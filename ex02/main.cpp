/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:50:00 by zsonie            #+#    #+#             */
/*   Updated: 2026/01/24 19:40:42 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
    if (!DEBUG_MODE)
        std::cout << std::endl
                  << RED << "FOR A FULL TEST PLS USE: make debug"
                  << std::endl;

    std::cout << GREEN << "\n========== FRAGTRAP TESTS ==========" << RESET << std::endl;

    std::cout << GREEN << "\n=== Test 1: FragTrap construct and actions ===" << RESET << std::endl;
    FragTrap frag1("Destroyer");
    frag1.attack("victim");
    frag1.attack("another_victim");
    frag1.highFivesGuys();

    std::cout << GREEN << "\n=== Test 2: FragTrap Stats Test ===" << RESET << std::endl;
    FragTrap statsTest("StatsTest");
    std::cout << "Testing 100 HP:" << std::endl;
    statsTest.takeDamage(50);
    statsTest.beRepaired(20);
    statsTest.takeDamage(70);
    std::cout << "Testing 30 attack damage:" << std::endl;
    statsTest.attack("dummy");

    std::cout << GREEN << "\n=== Test 3: FragTrap Copy & Assignment ===" << RESET << std::endl;
    FragTrap frag2(frag1);
    frag2.highFivesGuys();
    FragTrap frag3("TempFrag");
    frag3 = frag1;
    frag3.highFivesGuys();

    std::cout << GREEN << "\n=== Test 4: FragTrap Death Test ===" << RESET << std::endl;
    FragTrap deadFrag("DeadFrag");
    deadFrag.takeDamage(100);
    deadFrag.attack("ghost");
    deadFrag.highFivesGuys();

    std::cout << GREEN << "\n=== Test 5: Destruction Order ===" << RESET << std::endl;
    {
        FragTrap temp("Temporary");
        std::cout << MAGENTA << "Leaving scope - watch destruction order!" << RESET << std::endl;
    }

    std::cout << GREEN << "\n=== Test 6: Default Constructor ===" << RESET << std::endl;
    FragTrap defaultFrag;
    defaultFrag.highFivesGuys();
    defaultFrag.attack("test");

    if (DEBUG_MODE)
        std::cout << GREEN << "\n=== Final Destructors ===" << RESET << std::endl;
    return 0;
}
