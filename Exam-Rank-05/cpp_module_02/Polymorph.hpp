/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:25:35 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 17:26:24 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include <iostream>
#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public:
		Polymorph();
		~Polymorph();
		Polymorph(const Polymorph& _copy);
		const Polymorph& operator=(const Polymorph& _assignment);
		Polymorph (std::string _Name, std::string _Effects);
		ASpell* clone() const;
};

#endif