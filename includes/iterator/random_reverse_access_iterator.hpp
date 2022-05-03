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
        ReverseIterator(void){};
        ReverseIterator(void){};
        ReverseIterator(void){};
        ~ReverseIterator(void){};

        public :
        ReverseIterator&       operator=(const ReverseIterator &ori){ if (&ori != this){this->curant = ori;}return (*this);};
        ReverseIterator&       operator++(void) {this->_ptr++; return (*this);};
        ReverseIterator&       operator--(void) {this->_ptr--; return (*this);};
        ReverseIterator        operator++(int) {ReverseIterator old = *this; this->_ptr++; return (old);};
        ReverseIterator        operator--(int) {ReverseIterator old = *this; this->_ptr--; return (old);};
        reference              operator*(void) const {return (*this->_ptr);};
        pointer                operator->(void) const {return (this->_ptr);};
        ReverseIterator        operator+(difference_type const &ori) const {return ReverseIterator(this->_ptr + ori);};
        ReverseIterator        operator-(difference_type ori) const {return ReverseIterator(this->_ptr - ori);};
        difference_type        operator-(ReverseIterator const &ori) const {return (_ptr - ori._ptr);};
        ReverseIterator&       operator+=(difference_type const &ori) {this->_ptr += ori; return (*this);};
        ReverseIterator&       operator-=(difference_type ori) {this->_ptr -= ori; return (*this);};
        reference              operator[](difference_type ori) {return (*(this->ptr + ori));};
        T                      base(void) const {return (this->_ptr);};
        protected :

    };

    template <typename T>
    bool    operator!=(const ft::ReverseIterator<T, false> &ori, const ft::ReverseIterator<T, true> &ori_2){ if (&ori.base() != &ori_2.base()){return (true);} return (false);};
    template <typename T>
    bool    operator==(const ft::ReverseIterator<T, false> &ori, const ft::ReverseIterator<T, true> &ori_2){ if (&ori.base() == &ori_2.base()){return (true);} return (false);};
    template <typename T>
    ft::ReverseIterator<T,false>    operator+(const ft::ReverseIterator<T, false> &ori, const ft::ReverseIterator<T, true> &ori_2){return (ft::ReverseIterator<T,false>(ori.base() + ori_2.base()));};
    template <typename T>
    ft::ReverseIterator<T,false>    operator-(const ft::ReverseIterator<T, false> &ori, const ft::ReverseIterator<T, true> &ori_2){return (ft::ReverseIterator<T,false>(ori.base() - ori_2.base()));};
    template <typename T>
    bool    operator<(const ft::ReverseIterator<T, false> &ori, const ft::ReverseIterator<T, true> &ori_2){ if (&ori.base() < &ori_2.base()){return (true);} return (false);};
    template <typename T>
    bool    operator>(const ft::ReverseIterator<T, false> &ori, const ft::ReverseIterator<T, true> &ori_2){ if (&ori.base() > &ori_2.base()){return (true);} return (false);};
    template <typename T>
    bool    operator<=(const ft::ReverseIterator<T, false> &ori, const ft::ReverseIterator<T, true> &ori_2){ if (&ori.base() <= &ori_2.base()){return (true);} return (false);};
    template <typename T>
    bool    operator>=(const ft::ReverseIterator<T, false> &ori, const ft::ReverseIterator<T, true> &ori_2){ if (&ori.base() >= &ori_2.base()){return (true);} return (false);};
}

# include "../../templates/ReverseIterator/random_access_ReverseIterator.tpp"
#endif