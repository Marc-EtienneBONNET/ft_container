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
/*
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
}
*/

namespace ft {
	template < class T,	bool B >
	class Iterator ;

	template <typename T>
	class ReverseIterator
	{
		public:
			typedef T																iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference			reference;
			typedef typename ft::iterator_traits<T>::iterator_category				iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type			value_type; 
			/* Constructor */
			ReverseIterator(void): current() {};
			explicit ReverseIterator( iterator_type x ): current(x) {};
			/* Destructor */
			~ReverseIterator(void) {};
			/* Copy constructor */
			template< class U >
			ReverseIterator( const ReverseIterator<U>& other ): current(other.base()) {};
			/* Copy Assignation constructor */
			ReverseIterator&		operator=(const ReverseIterator& rhs)
			{
				if (this != &rhs)
					this->current = rhs.base();
				return (*this);
			}
			/* Increment Decrement Part */
			ReverseIterator&	operator--(void) { ++current; return *this; }
			ReverseIterator		operator--(int) { ReverseIterator old = *this; operator--(); return old; }
			ReverseIterator&	operator++(void) { --current; return *this; }
			ReverseIterator		operator++(int) { ReverseIterator old = *this; operator++(); return old; }
			reference			operator*(void) const { iterator_type tmp = current; return *(--tmp); }
			pointer				operator->(void) const { return &(operator*()); }
			/* Arithmetic operations */
			ReverseIterator		operator+(difference_type rhs) const { return ReverseIterator(current - rhs); }
			ReverseIterator		operator-(difference_type rhs) const { return ReverseIterator(base() + rhs); }
			difference_type		operator-(ReverseIterator const &r) { return r.base() - this->base(); }
			/* Compound assignement arithmetics operations */
			ReverseIterator&	operator+=(difference_type rhs) { current -= rhs; return *(this); }
			ReverseIterator&	operator-=(difference_type rhs) { current += rhs; return *this; }
			/* Offset dereference operator */
			reference			operator[](difference_type rhs) const { return *(current - rhs - 1); }
			iterator_type		base(void) const { return current; };
		protected:
			iterator_type		current;
	};

	template <class Iterator>
	ReverseIterator<Iterator> operator+(typename ReverseIterator<Iterator>::difference_type n, const ReverseIterator<Iterator>& rev_it) { return (rev_it + n); }
	template< class Iterator1, class Iterator2 >
	bool	operator==(const ReverseIterator<Iterator1>& lhs, const ReverseIterator<Iterator2>& rhs) { return (lhs.base() == rhs.base()); };
	template< class Iterator >
	bool	operator==(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); };
	template< class Iterator1, class Iterator2 >
	bool 	operator!=(const ReverseIterator<Iterator1>& lhs, const ReverseIterator<Iterator2>& rhs) { return (lhs.base() != rhs.base()); }
	template< class Iterator >
	bool 	operator!=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool	operator<(const ReverseIterator<Iterator1>& lhs, const ReverseIterator<Iterator2>& rhs) { return (lhs.base() > rhs.base()); };
	template< class Iterator>
	bool	operator<(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); };
	template< class Iterator1, class Iterator2 >
	bool	operator>(const ReverseIterator<Iterator1>& lhs, const ReverseIterator<Iterator2>& rhs) { return (lhs.base() < rhs.base()); };
	template< class Iterator >
	bool	operator>(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) { return (lhs.base() < rhs.base()); };
	template< class Iterator1, class 0Iterator2 >
	bool	operator<=(const ReverseIterator<Iterator1>& lhs, const ReverseIterator<Iterator2>& rhs) { return (lhs.base() >= rhs.base()); };
	template< class Iterator >
	bool	operator<=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); };
	template< class Iterator1, class Iterator2 >
	bool	operator>=(const ReverseIterator<Iterator1>& lhs, const ReverseIterator<Iterator2>& rhs) { return (lhs.base() <= rhs.base()); };
	template< class Iterator >
	bool	operator>=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); };
}
# include "../../templates/iterator/random_access_riverse_iterator.tpp"
#endif