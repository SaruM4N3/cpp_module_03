/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diamondtrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:42 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 23:05:05 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Claptrap.hpp"

class DiamondTrap : public Claptrap
{
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &copy);
    DiamondTrap& operator=(const DiamondTrap &copy);
    ~DiamondTrap();
};
