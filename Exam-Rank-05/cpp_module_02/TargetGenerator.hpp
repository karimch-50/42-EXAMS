/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:55:59 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 18:03:49 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <vector>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::vector<ATarget*> Book;
		TargetGenerator(const TargetGenerator& _copy);
		const TargetGenerator& operator=(const TargetGenerator& _assignment);
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget* _ATarget);
		void forgetTargetType(std::string const & _TargetType);
		ATarget* createTarget(std::string const & _TargetType);
};

#endif