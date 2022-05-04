/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:29:56 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/04 11:41:14 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPP
#define FT_HPP

namespace ft
{
	template<class Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::T					value_type;
	};
	struct random_access_iterator_tag {};
	template <bool isConstant, typename const_type, typename notConst_type>
	struct is_constant{};

	template <typename const_type, typename notConst_type>
	struct is_constant<true, const_type, notConst_type> { typedef const_type type;};

	template <typename const_type, typename notConst_type>
	struct is_constant<false, const_type, notConst_type> { typedef notConst_type type;};
	
	template<class T>
	typename ft::iterator_traits<T>::difference_type distance(T first, T last)
	{
		int x;

		x = 0;
		while (first != last)
		{
			first++;
			x++;
		}
		return (x);
	}
}


#endif