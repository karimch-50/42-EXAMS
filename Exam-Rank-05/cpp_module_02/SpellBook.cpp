/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:35:19 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 18:14:29 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{

}

SpellBook::SpellBook(const SpellBook& _copy)
{
	*this = _copy; 
}

const SpellBook& SpellBook::operator=(const SpellBook& _assignment)
{
	if (this != &_assignment)
	{

	}
	return (*this);
}

void SpellBook::learnSpell(ASpell* _ASpell)
{
	Book.push_back(_ASpell);
}

void SpellBook::forgetSpell(std::string const & _SpellName)
{
	std::vector<ASpell *>::iterator it;
	for (it = Book.begin(); it != Book.end(); it++)
	{
		if ((*it)->getName() == _SpellName)
		{
			Book.erase(it--);
			break ;
		}
	}
}

ASpell* SpellBook::createSpell(std::string const & _SpellName)
{
	std::vector<ASpell *>::iterator it;
	for (it = Book.begin(); it != Book.end(); it++)
	{
		if ((*it)->getName() == _SpellName)
			return (*it);
	}
	return (NULL);
}
