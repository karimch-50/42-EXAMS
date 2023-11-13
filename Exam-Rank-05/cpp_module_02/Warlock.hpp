/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:38:25 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 18:07:19 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		SpellBook book;
		Warlock();
		const Warlock& operator=(const Warlock& _assignment);
		Warlock(const Warlock& _copy);
	public:
		~Warlock();
		Warlock(const std::string& _name, const std::string& _title);
		const std::string& getName() const;
		const std::string& getTitle() const;
		void  setTitle(const std::string& _title);
		void introduce() const;
		void learnSpell(ASpell* _ASpell);
		void forgetSpell(std::string _spellName);
		void launchSpell(std::string _spellName, const ATarget& _ATarget);
};

#endif