/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:19:49 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/12 15:53:05 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"
class ATarget;

class ASpell
{
	private:
		std::string name;
		std::string effects;
	public:
		ASpell();
		virtual ~ASpell();
		ASpell(const ASpell& _copy);
		ASpell(const std::string& name, const std::string& effects);
		const ASpell& operator=(const ASpell& _assignment);
		const std::string& getName() const;
		const std::string& getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(const ATarget& _ATarget) const;
};

#endif
