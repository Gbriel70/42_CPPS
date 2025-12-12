/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:23:46 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/12/12 11:23:46 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

template< typename T >

void swap(T & a, T & b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template< typename T >
T const & min(T const & a, T const & b)
{
    return (a < b ? a : b);
}

template< typename T >
T const & max(T const & a, T const & b)
{
    return (a > b ? a : b);
}

#endif