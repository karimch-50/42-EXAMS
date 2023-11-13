/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:20:01 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/12 14:49:25 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell()
{

}

ASpell::~ASpell()
{

}

ASpell::ASpell(const ASpell& _copy)
{
	*this = _copy;
}

ASpell::ASpell(const std::string& _name, const std::string& _effects)
{
	name = _name;
	effects = _effects;
}

const ASpell& ASpell::operator=(const ASpell& _assignment)
{
	if (this != &_assignment)
	{
		name = _assignment.name;
		effects = _assignment.effects;
	}
	return (*this);
}

const std::string& ASpell::getName() const
{
	return (name);
}

const std::string& ASpell::getEffects() const
{
	return (effects);
}

void ASpell::launch(const ATarget& _ATarget) const
{
	_ATarget.getHitBySpell(*this);
}
