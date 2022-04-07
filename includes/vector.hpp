/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:22:22 by mbonnet           #+#    #+#             */
/*   Updated: 2022/04/07 16:32:01 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

template<typename T, class A = std::allocator<T> >
class my_vector 
{
public :
    typedef T                                           value_type;
    typedef A                                           allocator_type;
    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::pointer            pointeur;
    typedef typename allocator_type::const_pointer      const_pointeur;
    typedef std::iterator<T,A>                                 iterator;
    typedef const std::random_access_iterator_tag       const_iterator;
    typedef std::reverse_iterator<iterator>             reverse_iterator;
    typedef const std::reverse_iterator<iterator>       const_reverse_iterator;
    typedef typename allocator_type::size_type          size_type;
	typedef typename std::ptrdiff_t                     difference_type; 
    my_vector(void);
    my_vector(unsigned int taille, T valeur);
    ~my_vector(void);
    unsigned int size() const;

    pointeur        _start;
    pointeur        _end;
protected :
private :
    allocator_type  _alloc;
    int     size_occuper;
    int     size_reel;
};

#include "../templates/vector.tpp"
#endif