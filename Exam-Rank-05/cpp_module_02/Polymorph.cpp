/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:25:38 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 17:43:03 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{

}

Polymorph::~Polymorph()
{

}

Polymorph::Polymorph(const Polymorph& _copy)
{
	*this = _copy;
}

const Polymorph& Polymorph::operator=(const Polymorph& _assignment)
{
	if (this != &_assignment)
	{

	}
	return (*this);
}

ASpell* Polymorph::clone() const
{
	return (new Polymorph());
}
