/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:14:42 by zsonie            #+#    #+#             */
/*   Updated: 2026/01/05 20:06:49 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &copy);
    FragTrap& operator=(const FragTrap &copy);
    ~FragTrap();
    void highFivesGuys(void);
    unsigned int getFragHitPoints() const;
    unsigned int getFragAttackDmg() const;
};
