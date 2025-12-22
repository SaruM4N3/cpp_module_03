/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:50:00 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 22:59:16 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fragtrap.hpp"
#include <iostream>

int main()
{
    std::cout << GREEN << "\n========== FRAGTRAP TESTS ==========" << RESET << std::endl;

    std::cout << GREEN << "\n=== Test 1: FragTrap Construction (notice chaining) ===" << RESET << std::endl;
    FragTrap frag1("Destroyer");

    std::cout << GREEN << "\n=== Test 2: FragTrap Attack (30 dmg!) ===" << RESET << std::endl;
    frag1.attack("victim");
    frag1.attack("another_victim");

    std::cout << GREEN << "\n=== Test 3: High Fives Request ===" << RESET << std::endl;
    frag1.highFivesGuys();

    std::cout << GREEN << "\n=== Test 4: FragTrap Stats Test ===" << RESET << std::endl;
    FragTrap statsTest("StatsTest");
    std::cout << "Testing 100 HP:" << std::endl;
    statsTest.takeDamage(50);
    statsTest.beRepaired(20);
    statsTest.takeDamage(70);
    std::cout << "Testing 30 attack damage:" << std::endl;
    statsTest.attack("dummy");

    std::cout << GREEN << "\n=== Test 5: FragTrap Copy & Assignment ===" << RESET << std::endl;
    FragTrap frag2(frag1);
    frag2.highFivesGuys();
    FragTrap frag3("TempFrag");
    frag3 = frag1;
    frag3.highFivesGuys();

    std::cout << GREEN << "\n=== Test 6: FragTrap Death Test ===" << RESET << std::endl;
    FragTrap deadFrag("DeadFrag");
    deadFrag.takeDamage(100);
    deadFrag.attack("ghost");
    deadFrag.highFivesGuys();  // Can still high five when dead!

    std::cout << GREEN << "\n=== Test 7: Destruction Order (reverse of construction) ===" << RESET << std::endl;
    {
        FragTrap temp("Temporary");
        std::cout << MAGENTA << "Leaving scope - watch destruction order!" << RESET << std::endl;
    }

    std::cout << GREEN << "\n=== Test 8: Default Constructor ===" << RESET << std::endl;
    FragTrap defaultFrag;
    defaultFrag.highFivesGuys();
    defaultFrag.attack("test");

    std::cout << GREEN << "\n=== Final Destructors ===" << RESET << std::endl;
    return 0;
}
