/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:42 by zsonie            #+#    #+#             */
/*   Updated: 2025/12/22 00:46:24 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Claptrap.hpp"

class ScavTrap : public Claptrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &copy);
    ScavTrap& operator=(const ScavTrap &copy);
    ~ScavTrap();
    
    void attack(const std::string &target);
    void guardGate();
};
