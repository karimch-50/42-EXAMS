/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:43:36 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 15:59:47 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget()
{

}

ATarget::~ATarget()
{

}

ATarget::ATarget(const ATarget& _copy)
{
	*this = _copy;
}

ATarget::ATarget(const std::string& _type)
{
	type = _type;
}

const ATarget& ATarget::operator=(const ATarget& _assignment)
{
	if (this != &_assignment)
	{
		type = _assignment.type;
	}
	return (*this);
}

const std::string& ATarget::getType() const
{
	return (type);
}

void	ATarget::getHitBySpell(const ASpell& _ASpell) const
{
	std::cout << type << " has been " << _ASpell.getEffects() << "!" << std::endl;
}
