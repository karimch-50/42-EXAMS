/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:35:17 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 17:40:13 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <vector>
#include "ASpell.hpp"

class SpellBook
{
	private:
		SpellBook(const SpellBook& _copy);
		const SpellBook& operator=(const SpellBook& _assignment);
		std::vector<ASpell *> Book;
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell* _ASpell);
		void forgetSpell(std::string const & _SpellName);
		ASpell* createSpell(std::string const & _SpellName);
};

#endif