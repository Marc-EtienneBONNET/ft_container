/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_reverse_access_ReverseIterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:14 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/03 17:01:52 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../my_define_include.hpp"
#ifndef R_R_ReverseIterator_HPP
# define R_R_ReverseIterator_HPP

namespace ft
{
    template <typename T, bool is_const>
    class Iterator;
    template <typename T>
    class ReverseIterator
    {
    public : 
        typedef typename ft::iterator_traits<T>::difference_type     difference_type;
        typedef typename ft::iterator_traits<T>::pointer             pointer;
        typedef typename ft::iterator_traits<T>::reference           reference;
        typedef typename ft::iterator_traits<T>::iterator_category   iterator_category;
        typedef typename ft::iterator_traits<T>::value_type          value_type;
        ReverseIterator(void) : current(){};
        explicit ReverseIterator(T ori) : current(ori){};
        ReverseIterator(const ReverseIterator &ori){ if (&ori != this){this->current = ori.current;}};
        ~ReverseIterator(void) {};
        ReverseIterator &operator=(const ReverseIterator &ori){if (&ori != this){this->current = ori.current;} return (*this);};
        
        ReverseIterator&       operator++(void) {this->current--; return (*this);};
        ReverseIterator&       operator--(void) {this->current++; return (*this);};
        ReverseIterator        operator++(int) {ReverseIterator old = *this; operator++(); return (old);};
        ReverseIterator        operator--(int) {ReverseIterator old = *this; operator--(); return (old);};
        reference              operator*(void) const {T tmp = this->current; return (*(--tmp));};
        pointer                operator->(void) const {T tmp = this->current; return (--tmp);};
        ReverseIterator        operator+(difference_type ori) const {return ReverseIterator(this->current - ori);};
        ReverseIterator        operator-(difference_type ori) const {return ReverseIterator(this->current + ori);};
        difference_type        operator-(ReverseIterator const &ori) {return (ori.base() - this->base());};
        ReverseIterator&       operator+=(difference_type ori) {this->current -= ori; return (*this);};
        ReverseIterator&       operator-=(difference_type ori) {this->current += ori; return (*this);};
        reference              operator[](difference_type ori) const {return (*(this->current - ori - 1));};
        pointer                base(void) const {return (this->current);};
    protected :
        T   current;
    };
}

# include "../../templates/iterator/random_access_riverse_iterator.tpp"
#endif