/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:38:22 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/21 17:09:47 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock()
{

}

Warlock::Warlock(const Warlock& _copy)
{
	*this = _copy;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const std::string& _name, const std::string& _title)
{
	name = _name;
	title = _title;
	std::cout << name << ": This looks like another boring day." << std::endl;
}

const Warlock& Warlock::operator=(const Warlock& _assignment)
{
	if (this != &_assignment)
	{
		name = _assignment.name;
		title = _assignment.title;
	}
	return (*this);
}

const std::string& Warlock::getName() const
{
	return (name);
}

const std::string& Warlock::getTitle() const
{
	return (title);
}

void  Warlock::setTitle(const std::string& _title)
{
	title = _title;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* _ASpell)
{
	book.learnSpell(_ASpell);
}

void Warlock::forgetSpell(std::string _spellName)
{
	book.forgetSpell(_spellName);
}

void Warlock::launchSpell(std::string _spellName, const ATarget& _ATarget)
{
	ASpell* tmp = book.createSpell(_spellName);
	if (tmp)
		tmp->launch(_ATarget);
}
