/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:42 by zsonie            #+#    #+#             */
/*   Updated: 2026/01/05 19:09:28 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap 
{
private:
    std::string _name;
public:
    DiamondTrap();
    DiamondTrap(std::string const& name);
    DiamondTrap(const DiamondTrap &copy);
    DiamondTrap& operator=(const DiamondTrap &copy);
    ~DiamondTrap();

    void whoAmI();
    using ScavTrap::attack;
};
