/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:57:22 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/05 07:38:19 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
#include "my_define_include.hpp"
/*
namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
	public :
		typedef typename Container::T		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;
		
		stack(const Container &cont = Container()) : c(cont){};
		~stack(void){};
		stack& operator=(const stack &ori){if (&ori != this) this->c = ori.c; return (*this);};
		reference top(){return (c.back());};
		const_reference top() const {return (c.back());};
		bool empty() const	{return c.empty();};
		size_type size() const {return (c.size());};
		void push(const value_type &value) {c.push_back(value);};
		void pop()	{c.pop_back();};
		
		template <class U, class C>
		friend	bool operator==(const stack<U, C> &lhs, const stack<U, C> &rhs);
		template <class U, class C>
		friend bool operator!=(const stack<U, C> &lhs, const stack<U, C> &rhs);
		template <class U, class C>
		friend bool operator<(const stack<U, C> &lhs, const stack<U, C> &rhs);
		template <class U, class C>
		friend bool operator<=(const stack<U, C> &lhs, const stack<U, C> &rhs);
		template <class U, class C>
		friend bool operator>(const stack<U, C> &lhs, const stack<U, C> &rhs);
		template <class U, class C>
		friend bool operator>=(const stack<U, C> &lhs, const stack<U, C> &rhs);
	protected :
		Container c;
	};
	template< class T, class Container >
	bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return lhs.c == rhs.c; };
	template< class T, class Container >
	bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return lhs.c != rhs.c; };
	template< class T, class Container >
	bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return lhs.c < rhs.c; };
	template< class T, class Container >
	bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return lhs.c <= rhs.c; };
	template< class T, class Container >
	bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return lhs.c > rhs.c; };
	template< class T, class Container >
	bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) { return lhs.c >= rhs.c; };
};
*/
#include "../templates/stack.tpp"
#endif