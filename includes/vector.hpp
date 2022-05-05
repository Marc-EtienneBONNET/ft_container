/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:57:22 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/05 23:12:22 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP 
# define VECTOR_HPP
#include "my_define_include.hpp"

namespace ft
{
	template<typename T, class A = std::allocator<T> >
	class vector 
	{
	public :
		typedef T								value_type;
		typedef typename A::reference			reference;
		typedef typename A::const_reference		const_reference;
		typedef typename A::pointer				pointer;
		typedef typename A::const_pointer		const_pointer;
		typedef	ft::iterator<T, false>				iterator;
		typedef	ft::iterator<T, true>				const_iterator;
		typedef	Reverseiterator<iterator>		reverse_iterator;
		typedef	Reverseiterator<const_iterator>	const_reverse_iterator;
		typedef std::ptrdiff_t					difference_type;
		typedef size_t							size_type;
		vector(const A& alloc = A()) : _ptr(NULL), _size(0), _capacity(0), _alloc(alloc){};
		vector(size_type n, const T& value = T(), const A& alloc = A()): _ptr(NULL), _size(0), _capacity(0), _alloc(alloc)
		{assign(n, value);};
		template<class ite>
		vector(ite first, ite last, const A& alloc = A()): _ptr(NULL), _size(0), _capacity(0), _alloc(alloc)
		{assign(first, last);};
		vector(vector const &ori, const A& alloc = A()): _ptr(NULL), _size(0), _capacity(0), _alloc(alloc)
		{assign(ori.begin(), ori.end());};
		~vector(void)
		{
			if (this->_capacity > 0)
				this->_alloc.deallocate(this->_ptr, this->_capacity);
		};
		vector& operator=(const vector &ori)
		{
			if (&ori == this)
				return (*this);
			assign(ori.begin(), ori.end());
			return (*this);
		};
		template<class ite>
		void assign(ite first, ite last,  typename enable_if< !is_integral< ite >::value >::type* = 0)
		{
			difference_type distance;

			distance = ft::distance(first, last);
			_clear_alloc(this->_size);
			reserve(distance);
			this->_capacity = distance;
			while (first != last)
			{
				_alloc.construct(&this->_ptr[this->_size++], *first);
				first++;
			}
		};
		void assign(size_type n, const T &val)
		{
			_clear_alloc(this->_size);
			reserve(n);
			this->_size = n;
			for (size_type i = 0; i < n; i++)
				this->_alloc.construct(this->_ptr + i, val);
		};
		void	push_back(const T &val)
		{
			if (this->_size + 1 > this->_capacity)
				reserve(this->_size + 1);
			_alloc.construct(this->_ptr + this->_size, val);
			this->_size++;
		};
		void	pop_back(void)
		{
			if (this->_size == 0)
				return ;
			_alloc.destroy(&this->_ptr[this->_size - 1]);
			this->_size--;
		}
		iterator insert(iterator position, const T &val)
		{
			return (_insert_n(position, val, 1));
		}
		void	insert(iterator position, size_type n, const T &val)
		{
			for (size_type i = 0; i < n; i++)
				position = _insert_n(position, val, 1);
		}
		template<class ite>
		void insert(iterator position, ite first, ite last)
		{
			ite			tmp_first = first;
			pointer		tmp;
			size_type	pos = &(*position) - this->_ptr;
			size_type	len = 0;
			for (ite to = first; to != last; to++)
				len++;
			if (this->_size + len < this->_capacity)
			{
				tmp = this->_alloc.allocate(len);
				for (size_type i = 0; tmp_first != last; tmp_first++, i++)
					this->_alloc.construct(tmp + i, *tmp_first);
				size_type	i = 0;
				size_type	tmp_size = this->_size;
				pointer		tab;
				
				tab = this->_alloc.allocate(this->_capacity + len);
				for (; i < pos; i++)
					this->_alloc.construct((tab + i), *(this->_ptr + i));
				for (size_type l = 0; l < len; l++, i++)
					this->_alloc.construct((tab + i), *(tmp + l));
				for (; i - len < this->_size; i++)
					this->_alloc.construct((tab + 1), *(this->_ptr + i - len));
				clear();
				this->_size = tmp_size;
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				for (size_type l = 0; l < len; l++)
					this->_alloc.destroy(tmp + l);
				this->_alloc.deallocate(tmp, len);
				this->_ptr = tab;
				this->_capacity += len;
				this->_size += len;
			}
			else 
			{
				while (first != last)
					position = insert(position, *first++);
			}
		}
		iterator erase(iterator position)
		{
			size_type pos = &(*position) - this->_ptr;
			this->_alloc.destroy(this->_ptr + pos);
			for (; pos < this->_size - 1; pos++)
			{
				this->_alloc.construct(this->_ptr + pos, *(this->_ptr + pos + 1));
				this->_alloc.destroy(this->_ptr + pos + 1);
			}
			this->_size -= 1;
			this->_capacity -= 1;
			return (iterator(position));
		}
		iterator erase(iterator first, iterator last)
		{
			size_type n = 0;
			size_type pos = (&(*first) - this->_ptr);
			for (iterator tmp = first; tmp != last; tmp++)
				n++;
			if (this->_size > 0 && n > 0)
			{
				for (size_type i = 0; i < n; i++)
					this->_alloc.destroy(this->_ptr + pos + i);
				for (size_type l = pos; l + n < this->_size; l++)
				{
					this->_alloc.construct(this->_ptr + l, *(this->_ptr + l + n));
					this->_alloc.destroy(this->_ptr + l + n);
				}
				this->_size -= n;
				this->_capacity -= n;
			}
			return (iterator(this->_ptr + pos));
		}
		void	clear() {_clear_alloc(this->_size);};
		void	swap(vector &ori)
		{
			_swap(this->_size, ori._size);
			_swap(this->_capacity, ori._capacity);
			_swap(this->_alloc, ori._alloc);
			_swap(this->_ptr, ori._ptr);
		}
		iterator		begin() {return (iterator(this->_ptr));};
		const_iterator	begin() const {return (const_iterator(this->_ptr));};
		iterator		end() {return (iterator(this->_ptr + this->_size));};
		const_iterator	end() const {return (const_iterator(this->_ptr + this->_size));};
		reverse_iterator		rbegin() {return (reverse_iterator(this->_ptr + this->_size));};
		const_reverse_iterator	rbegin() const {return (reverse_const_iterator(this->_ptr + this->_size));};
		reverse_iterator		rend() {return (reverse_iterator(this->_ptr));};
		const_reverse_iterator	rend() const {return (reverse_const_iterator(this->_ptr));};

		reference operator[](size_type n) {return (this->_ptr[n]);};
		const_reference operator[](size_type n) const {return (this->_ptr[n]);};
		reference	at(size_type n)
		{
			if (n >= this->_size)
				throw std::out_of_range("out of bound");
			return (this->_ptr[n]);
		};
		const_reference	at(size_type n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("out of bound");
			return (this->_ptr[n]);
		};
		
		reference		front() {return (*(this->_ptr));};
		const_reference	front() const {return (*(this->_ptr));};
		reference		back() {return (this->_ptr[this->_size - 1]);};
		const_reference	back() const {return (this->_ptr[this->_size - 1]);};
		
		size_type		size() const {return (this->_size);};
		size_type		max_size() const {return A().max_size();};
		void			resize(size_type n, T val = T())
		{
			if (n < 0)
				throw std::length_error("Invalide resize value");
			reserve(n);
			if (n > this->_size)
			{
				size_type old_size = this->_size;
				for (; old_size < n; old_size++)
					this->_alloc.construct(this->_ptr + old_size, val);
			}
			else
			{
				iterator last = this->end();
				for (size_type i = n; i > this->_size; i++)
					this->_alloc.destroy(&(*(last - i)));
			}
			this->_size = n;
		};
		size_type	capacity(void) const {return (this->_capacity);};
		bool		empty() const { if (this->_size == 0) return (true); return (false);};
		void		reserve(size_type n)
		{
			if (n > max_size())
				throw std::length_error("Max size excessed");
			if (n <= this->_capacity)
				return ;
			pointer tmp;
			tmp = this->_alloc.allocate(n, 0);
			for (size_type i = 0; i < this->_size; i++)
			{
				this->_alloc.construct(tmp + i, this->_ptr[i]);
				this->_alloc.destroy(this->_ptr + i);
			}
			this->_alloc.deallocate(this->_ptr, this->_capacity);
			this->_ptr = tmp;
			this->_capacity = n;
		};
		A	get_allocator() const {return (A());};
	private :
		pointer			_ptr;
		size_type		_size;
		size_type		_capacity;
		A				_alloc;
		void	_clear_alloc(size_type n)
		{
			for (size_t i = 0; i < n; i++)
				this->_alloc.destroy(&this->_ptr[i]);
			this->_size = 0;
		}
		
		template<class ite>
		iterator _insert_n(ite position, T const &val, size_type step)
		{
			size_type n = &(*position) - this->_ptr;
			if (this->_size + step > this->_capacity)
			{
				reserve(this->_size + step);
				position = ite(this->_ptr + n);
			}
			for (ite last = this->end(); last != position; last--)
			{
				this->_alloc.construct(&(*last), *(last - step));
			}
			this->_alloc.construct(&(*position), val);
			this->_size = this->_size + step;
			return (position);
		}
		template<class ite>
		void	_move_elem(ite position, int offset)
		{
			this->_alloc.construct(&(*(position + offset)), *position);
			this->_alloc.destroy(&(*position));
		}
		template<typename Any>
		void	_swap(Any &a, Any &b)
		{
			Any tmp = a;
			a = b;
			b = tmp;
		}
		
	};
	template<class T, class Alloc>
	bool operator==(const vector<T,Alloc> &v1, const vector<T,Alloc> &v2)
	{
		if (v1.size() != v2.size())
			return (false);
		for (size_t i = 0; i < v1.size(); i++)
			if (v1[i] != v2[i])
				return (false);
		return (true);
	};
	template<class T, class Alloc>
	bool operator!=(const vector<T,Alloc> &v1, const vector<T,Alloc> &v2)
	{
		if (v1 == v2)
			return (false);
		return (true);
	};
	template<class T, class Alloc>
	bool operator>(const vector<T,Alloc> &v1, const vector<T,Alloc> &v2)
	{
		return (lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
	};
	template<class T, class Alloc>
	bool operator<(const vector<T,Alloc> &v1, const vector<T,Alloc> &v2){if (v1 > v2) return (false); return (true);};
	template<class T, class Alloc>
	bool operator<=(const vector<T,Alloc> &v1, const vector<T,Alloc> &v2)
	{
		if (v1 < v2 || v1 == v2)
			return (true);
		return (false);
	};
	template<class T, class Alloc>
	bool operator>=(const vector<T,Alloc> &v1, const vector<T,Alloc> &v2){if (v1 > v2 || v1 == v2) return (true); return (false);};
};
#include "../templates/vector.tpp"
#endif