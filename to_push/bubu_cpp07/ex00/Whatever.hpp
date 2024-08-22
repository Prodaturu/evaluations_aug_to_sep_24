/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:54:41 by mtayebi           #+#    #+#             */
/*   Updated: 2024/07/26 03:01:47 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename Type> void swap(Type &a, Type &b)
{
	Type	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename Type> Type min(Type &a, Type &b)
{
	if (a == b)
		return (a);
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename Type> Type max(Type &a, Type &b)
{
	if (a == b)
		return (a);
	if (a > b)
		return (a);
	else
		return (b);
}

#endif