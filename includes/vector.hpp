/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:22:22 by mbonnet           #+#    #+#             */
/*   Updated: 2022/04/06 18:15:23 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

template<typename T, class A = std::allocator<T> >
class my_vector 
{
public :
    my_vector(void);
    ~my_vector(void);
    typedef T                                           value_type;
    typedef A                                           allocator_type;
    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::pointer            pointeur;
    typedef typename allocator_type::const_pointer      const_pointeur;
    typedef std::random_access_iterator_tag             iterator;
    typedef const std::random_access_iterator_tag       const_iterator;
    typedef std::reverse_iterator<iterator>                    reverse_iterator;
    typedef const std::reverse_iterator<iterator>              const_reverse_iterator;
    typedef typename allocator_type::size_type                   size_type;
	typedef typename std::ptrdiff_t    difference_type; 
protected :
private :
};

#include "../templates/vector.tpp"
#endif
