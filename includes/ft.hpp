/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:29:56 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/14 17:03:31 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPP
#define FT_HPP

namespace ft
{
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};
	template<class Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::value_type			value_type;
	};
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

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
		template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare2(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || first2->second < first1->second)
				return false;
			else if (first1->second < first2->second)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
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


	template <class T>
	struct less : std::binary_function<T, T, bool>
	{
		bool operator() (const T& x, const T& y) const { return (x < y); }
	};

	template<class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		pair() : first(), second() {};

		pair( const T1& x, const T2& y ) : first(x), second(y) {};

		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {};
		pair& operator=( const pair& other ) {
			if (this == &other)
				return *this;
			first = other.first;
			second = other.second;
			return *this;
		};
	};
	template<class T1, class T2>
	pair<T1,T2> make_pair( T1 t, T2 u ) { return ft::pair<T1, T2>(t, u); };
	template<class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2)) 
				return false;
			++first1;
			++first2;
		}
		return true;
	}
	template<class InputIterator1, class InputIterator2>
	bool equal2(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(first1->second == first2->second)) 
				return false;
			++first1;
			++first2;
		}
		return true;
	}
}

#endif