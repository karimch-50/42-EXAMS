/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:29:27 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/13 17:30:13 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include <iostream>
#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public:
		BrickWall();
		~BrickWall();
		BrickWall(const BrickWall& _copy);
		const BrickWall& operator=(const BrickWall& _assignment);
		ATarget* clone() const;
};

#endif