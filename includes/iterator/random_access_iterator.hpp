/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:14 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/03 16:58:27 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../my_define_include.hpp"
#ifndef R_ITERATOR_HPP
# define R_ITERATOR_HPP

namespace ft
{
    template <typename T, bool is_const>
    class Iterator
    {
        typedef std::ptrdiff_t                                              difference_type;
        typedef typename ft::is_constant<is_const, const T *, T *>::type    pointer;
        typedef typename ft::is_constant<is_const, const T &, T &>::type    reference;
        typedef ft::random_access_iterator_tag                              iterator_category;

        Iterator(pointer ptr = 0) : _ptr(ptr) {};
        ~Iterator(void){};
        template<bool is_const_2>
        Iterator(const Iterator<T, is_const_2> &ori) : _ptr(ori._ptr){};
        Iterator operator=(Iterator &ori)
        {
            if (&ori != this)
                this->_ptr = ori._ptr;
            return (*this);
        }
        public :
        bool            operator==(Iterator const &ori) const {if (&ori._ptr == this->_ptr){return (true);} else {return (false);}};
        bool            operator!=(Iterator const &ori) const {if (&ori._ptr != this->_ptr){return (true);} else {return (false);}};
        bool            operator<(Iterator const &ori) const {if (this->_ptr < &ori._ptr){return (true);} else {return (false);}};
        bool            operator>(Iterator const &ori) const {if (this->_ptr > &ori._ptr){return (true);} else {return (false);}};
        bool            operator<=(Iterator const &ori) const {if (this->_ptr <= &ori._ptr){return (true);} else {return (false);}};
        bool            operator>=(Iterator const &ori) const {if (this->_ptr >= &ori._ptr){return (true);} else {return (false);}};
        Iterator&       operator++(void) {this->_ptr++; return (*this);};
        Iterator&       operator--(void) {this->_ptr--; return (*this);};
        Iterator        operator++(int) {Iterator old = *this; this->_ptr++; return (old);};
        Iterator        operator--(int) {Iterator old = *this; this->_ptr--; return (old);};
        reference       operator*(void) const {return (*this->_ptr);};
        pointer        operator->(void) const {return (this->_ptr);};
        Iterator        operator+(difference_type const &ori) const {return Iterator(this->_ptr + ori);};
        Iterator        operator-(difference_type ori) const {return Iterator(this->_ptr - ori);};
        difference_type operator-(Iterator const &ori) const {return (_ptr - ori._ptr);};
        Iterator&       operator+=(difference_type const &ori) {this->_ptr += ori; return (*this);};
        Iterator&       operator-=(difference_type ori) {this->_ptr -= ori; return (*this);};
        reference       operator[](difference_type ori) {return (*(this->ptr + ori));};
        pointer         base(void) const {return (this->_ptr);};

        private :
        pointer _ptr;
    };
}

template <typename T>
bool    operator!=(const ft::Iterator<T, false> &ori, const ft::Iterator<T, true> &ori_2){ if (&ori.base() != &ori_2.base()){return (true);} return (false);};
template <typename T>
bool    operator==(const ft::Iterator<T, false> &ori, const ft::Iterator<T, true> &ori_2){ if (&ori.base() == &ori_2.base()){return (true);} return (false);};
template <typename T>
ft::Iterator<T,false>    operator+(const ft::Iterator<T, false> &ori, const ft::Iterator<T, true> &ori_2){return (ft::Iterator<T,false>(ori.base() + ori_2.base()));};
template <typename T>
ft::Iterator<T,false>    operator-(const ft::Iterator<T, false> &ori, const ft::Iterator<T, true> &ori_2){return (ft::Iterator<T,false>(ori.base() - ori_2.base()));};
template <typename T>
bool    operator<(const ft::Iterator<T, false> &ori, const ft::Iterator<T, true> &ori_2){ if (&ori.base() < &ori_2.base()){return (true);} return (false);};
template <typename T>
bool    operator>(const ft::Iterator<T, false> &ori, const ft::Iterator<T, true> &ori_2){ if (&ori.base() > &ori_2.base()){return (true);} return (false);};
template <typename T>
bool    operator<=(const ft::Iterator<T, false> &ori, const ft::Iterator<T, true> &ori_2){ if (&ori.base() <= &ori_2.base()){return (true);} return (false);};
template <typename T>
bool    operator>=(const ft::Iterator<T, false> &ori, const ft::Iterator<T, true> &ori_2){ if (&ori.base() >= &ori_2.base()){return (true);} return (false);};
# include "../../templates/iterator/random_access_iterator.tpp"
#endif