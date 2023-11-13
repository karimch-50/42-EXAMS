/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:57:54 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 17:22:43 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <iostream>
#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
		Fireball();
		~Fireball();
		Fireball(const Fireball& _copy);
		const Fireball& operator=(const Fireball& _assignment);
		Fireball (std::string _Name, std::string _Effects);
		ASpell* clone() const;
};

#endif