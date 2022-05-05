/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_reverse_access_Reverseiterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:14 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/03 17:01:52 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../my_define_include.hpp"
#ifndef R_R_Reverseiterator_HPP
# define R_R_Reverseiterator_HPP

namespace ft
{
    template <typename T, bool is_const>
    class iterator;
    template <typename T>
    class Reverseiterator
    {
    public : 
        typedef typename ft::iterator_traits<T>::difference_type     difference_type;
        typedef typename ft::iterator_traits<T>::pointer             pointer;
        typedef typename ft::iterator_traits<T>::reference           reference;
        typedef typename ft::iterator_traits<T>::iterator_category   iterator_category;
        typedef typename ft::iterator_traits<T>::value_type          value_type;
        Reverseiterator(void) : current(){};
        explicit Reverseiterator(T ori) : current(ori){};
        Reverseiterator(const Reverseiterator &ori){ if (&ori != this){this->current = ori.current;}};
        ~Reverseiterator(void) {};
        Reverseiterator &operator=(const Reverseiterator &ori){if (&ori != this){this->current = ori.current;} return (*this);};
        
        Reverseiterator&       operator++(void) {this->current--; return (*this);};
        Reverseiterator&       operator--(void) {this->current++; return (*this);};
        Reverseiterator        operator++(int) {Reverseiterator old = *this; operator++(); return (old);};
        Reverseiterator        operator--(int) {Reverseiterator old = *this; operator--(); return (old);};
        reference              operator*(void) const {T tmp = this->current; return (*(--tmp));};
        pointer                operator->(void) const { return &(operator*()); };
        Reverseiterator        operator+(difference_type ori) const {return Reverseiterator(this->current - ori);};
        Reverseiterator        operator-(difference_type ori) const {return Reverseiterator(this->current + ori);};
        difference_type        operator-(Reverseiterator const &ori) {return (ori.base() - this->base());};
        Reverseiterator&       operator+=(difference_type ori) {this->current -= ori; return (*this);};
        Reverseiterator&       operator-=(difference_type ori) {this->current += ori; return (*this);};
        reference              operator[](difference_type ori) const {return (*(this->current - ori - 1));};
        T                       base(void) const {return (this->current);};
    protected :
        T   current;
    };
    template <class Iterator>
	Reverseiterator<Iterator> operator+(typename Reverseiterator<Iterator>::difference_type n, const Reverseiterator<Iterator>& rev_it) { return (rev_it + n); }
	template< class Iterator1, class Iterator2 >
	bool	operator==(const Reverseiterator<Iterator1>& lhs, const Reverseiterator<Iterator2>& rhs) { return (lhs.base() == rhs.base()); };
	template< class Iterator >
	bool	operator==(const Reverseiterator<Iterator>& lhs, const Reverseiterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); };
	template< class Iterator1, class Iterator2 >
	bool 	operator!=(const Reverseiterator<Iterator1>& lhs, const Reverseiterator<Iterator2>& rhs) { return (lhs.base() != rhs.base()); }
	template< class Iterator >
	bool 	operator!=(const Reverseiterator<Iterator>& lhs, const Reverseiterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool	operator<(const Reverseiterator<Iterator1>& lhs, const Reverseiterator<Iterator2>& rhs) { return (lhs.base() > rhs.base()); };
	template< class Iterator>
	bool	operator<(const Reverseiterator<Iterator>& lhs, const Reverseiterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); };
	template< class Iterator1, class Iterator2 >
	bool	operator>(const Reverseiterator<Iterator1>& lhs, const Reverseiterator<Iterator2>& rhs) { return (lhs.base() < rhs.base()); };
	template< class Iterator >
	bool	operator>(const Reverseiterator<Iterator>& lhs, const Reverseiterator<Iterator>& rhs) { return (lhs.base() < rhs.base()); };
	template< class Iterator1, class Iterator2 >
	bool	operator<=(const Reverseiterator<Iterator1>& lhs, const Reverseiterator<Iterator2>& rhs) { return (lhs.base() >= rhs.base()); };
	template< class Iterator >
	bool	operator<=(const Reverseiterator<Iterator>& lhs, const Reverseiterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); };
	template< class Iterator1, class Iterator2 >
	bool	operator>=(const Reverseiterator<Iterator1>& lhs, const Reverseiterator<Iterator2>& rhs) { return (lhs.base() <= rhs.base()); };
	template< class Iterator >
	bool	operator>=(const Reverseiterator<Iterator>& lhs, const Reverseiterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); };
}

# include "../../templates/iterator/random_access_riverse_iterator.tpp"
#endif