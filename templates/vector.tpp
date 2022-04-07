/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:22:22 by mbonnet           #+#    #+#             */
/*   Updated: 2022/04/07 15:44:14 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

# include "../includes/vector.hpp"



//constructeur et destructeur 
template<typename T, class A>
my_vector<T,A>::my_vector(void)
{
    
    std::cout << VERT << "---construction vide vector---" << BLANC << std::endl;
    this->_start = this->_alloc.allocate(sizeof(T));
    this->_end = this->_start;
    this->size_occuper = 0;
    this->size_reel = 1;
}


template<typename T, class A>
my_vector<T,A>::my_vector(unsigned int taille, T valeur)
{
    std::cout << VERT << "---construction vide vector---" << BLANC << std::endl;
    this->_start = this->_alloc.allocate(sizeof(T) * taille);
    pointeur tmp = this->_start;
    for (unsigned int x = 0; x <= taille; x++ && tmp++)
        *tmp = valeur;
    this->_end = tmp;
    this->size_occuper = taille;
    this->size_reel = taille;
}

template<typename T, typename A>
my_vector<T,A>::~my_vector(void)
{
    std::cout << VERT << "---Destruction vector---" << BLANC << std::endl;
    this->_alloc.deallocate(this->_start,this->size_reel);
}


template<typename T, typename A>
unsigned int my_vector<T,A>::size() const
{
    unsigned int x = 0;
    pointeur tmp = this->_start;
    for (x = 0; tmp != this->_end ; x++ && tmp++);
    if (x == 0)
        return (x);
    return (x - 1);
}

#endif