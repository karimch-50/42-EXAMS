/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:04:39 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 15:59:17 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{

}

Dummy::~Dummy()
{

}

Dummy::Dummy(const Dummy& _copy)
{
	*this = _copy;
}

const Dummy& Dummy::operator=(const Dummy& _assignment)
{
	if (this != &_assignment)
	{
		
	}
	return (*this);
}

ATarget* Dummy::clone() const
{
	return (new Dummy());
}
