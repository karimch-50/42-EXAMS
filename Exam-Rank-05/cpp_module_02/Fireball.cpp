/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:48:38 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 17:42:58 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{

}


Fireball::~Fireball()
{

}

Fireball::Fireball(const Fireball& _copy)
{
	*this = _copy;
}

const Fireball& Fireball::operator=(const Fireball& _assignment)
{
	if (this != &_assignment)
	{
		
	}
	return (*this);
}

ASpell* Fireball::clone() const
{
	return (new Fireball());
}
