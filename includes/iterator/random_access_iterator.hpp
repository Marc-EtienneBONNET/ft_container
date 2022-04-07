/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:14 by mbonnet           #+#    #+#             */
/*   Updated: 2022/04/07 17:58:15 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../my_define_include.hpp"
#ifndef R_ITERATOR_HPP
# define R_ITERATOR_HPP

template<typename T>
class R_A_iterator : std::iterator<std::random_access_iterator_tag, T>
{
public :
    R_A_iterator(void)                                  {};
    R_A_iterator(R_A_iterator &ori)                     {(void)ori;};
    R_A_iterator(T *ori)                                {this->pointeur = ori;};
    ~R_A_iterator(void)                                 {}; 
    T            *getPointeur() const                   {return (this->pointeur);};
    T            getValPointeur()const                  {return (*(this->pointeur));};
    R_A_iterator &operator=(R_A_iterator &ori)          {if (this != &ori) *this = ori; return (*this);};
    R_A_iterator &operator=(T *val)                     {this->pointeur = val; return (*this);};
    R_A_iterator operator*(R_A_iterator *ori) const     {return (*ori);};
    R_A_iterator &operator->(void) const                {return (*this);};
    //void         operator++(R_A_iterator &ori)          {ori.getPointeur()++;};
    //void         operator--(R_A_iterator &ori)          {ori.getPointeur()--;};
    void         operator++(void)                       {this->pointeur++;};
    void         operator--(void)                       {this->pointeur--;};
    T            operator+(R_A_iterator &ori) const     {return (*(this->pointeur) + ori.getValPointeur());};
    T            operator-(R_A_iterator &ori) const     {return (*(this->pointeur) - ori.getValPointeur());};;
    T            operator+(T val) const                 {return (*(this->pointeur) + val);};
    T            operator-(T val) const                 {return (*(this->pointeur) - val);};
    void         operator+=(R_A_iterator &ori)          {*(this->pointeur) += ori.getValPointeur();};
    void         operator-=(R_A_iterator &ori)          {*(this->pointeur) -= ori.getValPointeur();};
    void         operator+=(T val)                      {*(this->pointeur) += val;};
    void         operator-=(T val)                      {*(this->pointeur) -= val;};
    int          operator==(R_A_iterator &ori) const    {if (this->pointeur == ori.getPointeur()) return (0); else return (1);};
    int          operator==(T val) const                {if (*(this->pointeur) == val) return (0); else return (1);};
    int          operator!=(R_A_iterator &ori) const    {if (this->pointeur != ori.getPointeur()) return (0); else return (1);};
    int          operator!=(T val) const                {if (*(this->pointeur) != val) return (0); else return (1);};
    int          operator<=(R_A_iterator &ori) const    {if (*(this->pointeur) <= ori.getValPointeur()) return (0); else return (1);};
    int          operator<(R_A_iterator &ori) const     {if (*(this->pointeur) < ori.getValPointeur()) return (0); else return (1);};
    int          operator>=(R_A_iterator &ori) const    {if (*(this->pointeur) >= ori.getValPointeur()) return (0); else return (1);};
    int          operator>(R_A_iterator &ori) const     {if (*(this->pointeur) > ori.getValPointeur()) return (0); else return (1);};
    T            operator[](int index)                  {return (this->pointeur[index]);};
    T            *operator<<(R_A_iterator &ori)         {return (ori->getPointeur());};
protected :
private :
    T *pointeur;
};

# include "../../templates/iterator/random_access_iterator.tpp"
#endif