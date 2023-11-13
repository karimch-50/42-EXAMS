/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:43:39 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/12 15:53:10 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"
class ASpell;

class ATarget
{
	private:
		std::string type;
	public:
		ATarget();
		virtual ~ATarget();
		ATarget(const ATarget& _copy);
		ATarget(const std::string& type);
		const ATarget& operator=(const ATarget& _assignment);
		const std::string& getType() const;
		virtual ATarget* clone() const = 0;
		void	getHitBySpell(const ASpell& _ASpell) const;
};

#endif