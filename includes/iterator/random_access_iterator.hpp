/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:14 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/05 22:56:03 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../my_define_include.hpp"
#ifndef R_iterator_HPP
# define R_iterator_HPP

namespace ft
{
    template <typename T, bool is_const>
    class iterator
    {
        public :
		typedef T														    value_type;
        typedef std::ptrdiff_t                                              difference_type;
        typedef typename ft::is_constant<is_const, const T *, T *>::type    pointer;
        typedef typename ft::is_constant<is_const, const T &, T &>::type    reference;
        typedef ft::random_access_iterator_tag                              iterator_category;

        iterator(pointer ptr = 0) : _ptr(ptr) {};
        ~iterator(void){};
        template<bool is_const_2>
        iterator(const iterator<T, is_const_2> &ori) : _ptr(ori.base()){};
        iterator &operator=(iterator const &ori)
        {
            if (&ori != this)
                this->_ptr = ori._ptr;
            return (*this);
        }
        bool            operator==(iterator const &ori) const {if (ori._ptr == this->_ptr){return (true);} else {return (false);}};
        bool            operator!=(iterator const &ori) const {if (ori._ptr != this->_ptr){return (true);} else {return (false);}};
        bool            operator<(iterator const &ori) const {if (this->_ptr < ori._ptr){return (true);} else {return (false);}};
        bool            operator>(iterator const &ori) const {if (this->_ptr > ori._ptr){return (true);} else {return (false);}};
        bool            operator<=(iterator const &ori) const {if (this->_ptr <= ori._ptr){return (true);} else {return (false);}};
        bool            operator>=(iterator const &ori) const {if (this->_ptr >= ori._ptr){return (true);} else {return (false);}};
        iterator&       operator++(void) {this->_ptr++; return (*this);};
        iterator&       operator--(void) {this->_ptr--; return (*this);};
        iterator        operator++(int) {iterator old = *this; this->_ptr++; return (old);};
        iterator        operator--(int) {iterator old = *this; this->_ptr--; return (old);};
        reference       operator*(void) const {return (*this->_ptr);};
        pointer        operator->(void) const {return (this->_ptr);};
        iterator        operator+(difference_type const &ori) const {return iterator(this->_ptr + ori);};
        iterator        operator-(difference_type ori) const {return iterator(this->_ptr - ori);};
        difference_type operator-(iterator const &ori) const {return (this->_ptr - ori._ptr);};
        iterator&       operator+=(difference_type const &ori) {this->_ptr += ori; return (*this);};
        iterator&       operator-=(difference_type ori) {this->_ptr -= ori; return (*this);};
        reference       operator[](difference_type ori) {return (*(this->_ptr + ori));};
        pointer         base(void) const {return (this->_ptr);};

        private :
        pointer _ptr;
    };
}

template <typename T>
bool    operator!=(const ft::iterator<T, false> &ori, const ft::iterator<T, true> &ori_2){ if (ori.base() != ori_2.base()){return (true);} return (false);};
template <typename T>
bool    operator==(const ft::iterator<T, false> &ori, const ft::iterator<T, true> &ori_2){ if (ori.base() == ori_2.base()){return (true);} return (false);};
template <typename T>
ft::iterator<T,false>    operator+(const ft::iterator<T, false> &ori, const ft::iterator<T, true> ori_2){return (ft::iterator<T,false>(ori.base() + ori_2.base()));};
template <typename T>
ft::iterator<T,false>    operator-(const ft::iterator<T, false> &ori, const ft::iterator<T, true> ori_2){return (ft::iterator<T,false>(ori.base() - ori_2.base()));};
template <typename T>
bool    operator<(const ft::iterator<T, false> &ori, const ft::iterator<T, true> &ori_2){ if (ori.base() < ori_2.base()){return (true);} return (false);};
template <typename T>
bool    operator>(const ft::iterator<T, false> &ori, const ft::iterator<T, true> &ori_2){ if (ori.base() > ori_2.base()){return (true);} return (false);};
template <typename T>
bool    operator<=(const ft::iterator<T, false> &ori, const ft::iterator<T, true> &ori_2){ if (ori.base() <= ori_2.base()){return (true);} return (false);};
template <typename T>
bool    operator>=(const ft::iterator<T, false> &ori, const ft::iterator<T, true> &ori_2){ if (ori.base() >= ori_2.base()){return (true);} return (false);};
# include "../../templates/iterator/random_access_iterator.tpp"
#endif