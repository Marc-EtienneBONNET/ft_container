/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:29:56 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/05 11:38:47 by mbonnet          ###   ########.fr       */
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
		typedef typename Iter::value_type			value_type;
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
	template<bool B, class T = void>
	struct enable_if {};
	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <typename T>
	struct is_integral { static const bool value = false; };
	template <>
	struct is_integral<bool> { static const bool value = true; };
	template <>
	struct is_integral<char> { static const bool value = true; };
	template <>
	struct is_integral<float> { static const bool value = true; };
	template <>
	struct is_integral<short> { static const bool value = true; };
	template <>
	struct is_integral<int> { static const bool value = true; };
	template <>
	struct is_integral<long> { static const bool value = true; };
	template <>
	struct is_integral<long long> { static const bool value = true; };
	template <>
	struct is_integral<unsigned char> { static const bool value = true; };
	template <>
	struct is_integral<unsigned short> { static const bool value = true; };
	template <>
	struct is_integral<unsigned int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned long> { static const bool value = true; };
	template <>
	struct is_integral<unsigned long long> { static const bool value = true; };
}


#endif