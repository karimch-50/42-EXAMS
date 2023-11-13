/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:29:30 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 17:42:51 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{

}

BrickWall::~BrickWall()
{

}


BrickWall::BrickWall(const BrickWall& _copy)
{
	*this = _copy;
}

const BrickWall& BrickWall::operator=(const BrickWall& _assignment)
{
	if (this != &_assignment)
	{

	}
	return (*this);
}

ATarget* BrickWall::clone() const
{
	return (new BrickWall());
}
