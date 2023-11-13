/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:59:14 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 18:05:59 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{

}

TargetGenerator::~TargetGenerator()
{

}

TargetGenerator::TargetGenerator(const TargetGenerator& _copy)
{
	*this = _copy;
}

const TargetGenerator& TargetGenerator::operator=(const TargetGenerator& _assignment)
{
	if (this != &_assignment)
	{
		
	}
	return (*this);
}

void TargetGenerator::learnTargetType(ATarget* _ATarget)
{
	Book.push_back(_ATarget);
}

void TargetGenerator::forgetTargetType(std::string const & _TargetType)
{
	std::vector<ATarget*>::iterator it;
	for (it = Book.begin(); it != Book.end(); it++)
	{
		if ((*it)->getType() == _TargetType)
		{
			Book.erase(it);
			break ;
		}
	}
}

ATarget* TargetGenerator::createTarget(std::string const & _TargetName)
{
	std::vector<ATarget*>::iterator it;
	for (it = Book.begin(); it != Book.end(); it++)
	{
		if ((*it)->getType() == _TargetName)
			return (*it);
	}
	return (NULL);
}
