/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:57:06 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/12 13:03:53 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
	
}

Fwoosh::~Fwoosh()
{
	
}

Fwoosh::Fwoosh(const Fwoosh& _copy)
{
	*this = _copy;
}

const Fwoosh& Fwoosh::operator=(const Fwoosh& _assignment)
{
	if (this != &_assignment)
	{
		
	}
	return (*this);
}

ASpell* Fwoosh::clone() const
{
	return (new Fwoosh());
}
