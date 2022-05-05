/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_vector.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:29:45 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/05 22:56:03 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_define_include.hpp"


template<class T, class Y>
void	etat_vector(T &ft_vector, Y &std_vector)
{
	std::cout << BLEU << "Debut comparaison ft::vector std::vector" << BLANC << std::endl;
	std::cout << "                ft|std" << std::endl;
	//	std::cout << "_ptr         :\t" << BLEU_2 << *(ft_vector.begin())    << BLANC << "|" << VERT << *(std_vector.begin()) << BLANC << std::endl;
	std::cout << "_size        :\t " << BLEU_2 << ft_vector.size()        << BLANC << "|" << VERT << std_vector.size() << BLANC << std::endl;
	std::cout << "_capacity    :\t " << BLEU_2 << ft_vector.capacity()    << BLANC << "|" << VERT << std_vector.capacity() << BLANC << std::endl;
	std::cout << "ft  : ";
	for (typename T::iterator it = ft_vector.begin(); it != ft_vector.end(); it++)
		std::cout << JAUNE << *it << " " << BLANC;
	std::cout << std::endl;
	std::cout << "std : "; 
	for (typename Y::iterator it = std_vector.begin(); it != std_vector.end(); it++)
		std::cout << JAUNE << *it << " " << BLANC;
	std::cout << std::endl; 
}

void	teste_vector()
{
	std::cout << VIOLET << "---------------deb des teste constructeur---------------" << BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N " << "0 : init par constructeur vide"<< BLANC << std::endl;
	ft::vector<int> ft_vector0;
	std::vector<int> std_vector0;
	std::cout << VIOLET "VECTOR TEST N 0 fin(il yt aurais eu un segment fault si probleme)\n"<< BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 1 init par constructeur de 3 case a la 10"<< BLANC << std::endl;
	ft::vector<int> ft_vector1(3,10);
	std::vector<int> std_vector1(3,10);
	etat_vector(ft_vector1, std_vector1);
	std::cout << VIOLET "VECTOR TEST N 1 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 2 init par constructeur par iterateur deb et fin"<< BLANC << std::endl;
	ft::vector<int> ft_vector2(std_vector1.begin(),std_vector1.end());
	std::vector<int> std_vector2(std_vector1.begin(),std_vector1.end());
	etat_vector(ft_vector2, std_vector2);
	std::cout << VIOLET "VECTOR TEST N 2 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 3 init par constructeur par copie de vector"<< BLANC << std::endl;
	ft::vector<int> ft_vector3(ft_vector2);
	std::vector<int> std_vector3(std_vector2);
	etat_vector(ft_vector3, std_vector3);
	std::cout << VIOLET "VECTOR TEST N 3 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET << "---------------fin des teste constructeur---------------" << BLANC << std::endl;
	std::cout << std::endl << VIOLET << "---------------deb des teste ft---------------" << BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 4 assign par tranch d iterator"<< BLANC << std::endl;
	std::vector<int> std_tmp(5, 32);
	ft::vector<int> ft_vector4;
	std::vector<int> std_vector4;
	ft_vector4.assign(std_tmp.begin(), std_tmp.end());
	std_vector4.assign(std_tmp.begin(), std_tmp.end());
	etat_vector(ft_vector4, std_vector4);
	std::cout << VIOLET "VECTOR TEST N 4 fin\n"<< BLANC << std::endl;
	
	std::cout << VIOLET "VECTOR TEST N 5 assign par tranch n case a la valeur val"<< BLANC << std::endl;
	ft::vector<int> ft_vector5;
	std::vector<int> std_vector5;
	ft_vector5.assign(3, 42);
	std_vector5.assign(3, 42);
	etat_vector(ft_vector5, std_vector5);
	std::cout << VIOLET "VECTOR TEST N 5 fin\n"<< BLANC << std::endl;

	std::cout << VIOLET "VECTOR TEST N 6 push_back"<< BLANC << std::endl;
	ft_vector5.push_back(10);
	std_vector5.push_back(10);
	etat_vector(ft_vector5, std_vector5);
	std::cout << VIOLET "VECTOR TEST N 6 fin\n"<< BLANC << std::endl;
	
	std::cout << VIOLET "VECTOR TEST N 7 pop_back"<< BLANC << std::endl;
	ft_vector5.pop_back();
	std_vector5.pop_back();
	etat_vector(ft_vector5, std_vector5);
	std::cout << VIOLET "VECTOR TEST N 7 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 8 insert, ajoue d une valeur par position(a la position 0)"<< BLANC << std::endl;
	ft_vector5.insert(ft_vector5.begin(), 10);
	std_vector5.insert(std_vector5.begin(), 10);
	etat_vector(ft_vector5, std_vector5);
	std::cout << VIOLET "VECTOR TEST N 8 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 9 insert, ajoue d un creno d iterator par position(a la position 0)"<< BLANC << std::endl;
	ft_vector5.insert(ft_vector5.begin(), ft_vector4.begin(), ft_vector4.end());
	std_vector5.insert(std_vector5.begin(), std_vector4.begin(), std_vector4.end());
	etat_vector(ft_vector5, std_vector5);
	std::cout << VIOLET "VECTOR TEST N 9 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 10 ecrase, par position (a la position 0)"<< BLANC << std::endl;
	ft_vector5.erase(ft_vector5.begin());
	std_vector5.erase(std_vector5.begin());
	etat_vector(ft_vector5, std_vector5);
	std::cout << VIOLET "VECTOR TEST N 10 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 11 ecrase, par position (a la position 0)"<< BLANC << std::endl;
	ft_vector5.erase(ft_vector5.begin(), ft_vector5.end() - 3);
	std_vector5.erase(std_vector5.begin(), std_vector5.end() - 3);
	etat_vector(ft_vector5, std_vector5);
	std::cout << VIOLET "VECTOR TEST N 11 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 12 clear"<< BLANC << std::endl;
	ft_vector5.clear();
	std_vector5.clear();
	std::cout << "\t ajoue avec push pour afficher les resulta" << std::endl;
	ft_vector5.push_back(43);
	std_vector5.push_back(43);
	etat_vector(ft_vector5, std_vector5);
	std::cout << VIOLET "VECTOR TEST N 12 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 13 swap, avec vector4"<< BLANC << std::endl;
	ft_vector5.swap(ft_vector4);
	std_vector5.swap(std_vector4);
	etat_vector(ft_vector5, std_vector5);
	std::cout << VIOLET "VECTOR TEST N 13 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 14 at/front/back/size/max_size/capacity/empty"<< BLANC << std::endl;
	std::cout << "\tajoue de plusieur valeur" << std::endl;
	ft_vector5.insert(ft_vector5.begin() + 2, 10);
	std_vector5.insert(std_vector5.begin() + 2, 10);
	ft_vector5.insert(ft_vector5.end(), 99);
	std_vector5.insert(std_vector5.end(), 99);
	ft_vector5.insert(ft_vector5.begin(), 11);
	std_vector5.insert(std_vector5.begin(), 11);
	etat_vector(ft_vector5, std_vector5);
	std::cout << "at a l index 2 : " << BLEU_2 << ft_vector5.at(2) << BLANC << std::endl;
	std::cout << "at a l index 2 : " << VERT << std_vector5.at(2) << BLANC << std::endl;
	etat_vector(ft_vector5, std_vector5);
	std::cout << "front          : " << BLEU_2 << ft_vector5.front() << BLANC << std::endl;
	std::cout << "front          : " << VERT << std_vector5.front() << BLANC << std::endl;
	etat_vector(ft_vector5, std_vector5);
	std::cout << "back           : " << BLEU_2 << ft_vector5.back() << BLANC << std::endl;
	std::cout << "back           : " << VERT << std_vector5.back() << BLANC << std::endl;
	etat_vector(ft_vector5, std_vector5);
	std::cout << "size           : " << BLEU_2 << ft_vector5.size() << BLANC << std::endl;
	std::cout << "size           : " << VERT << std_vector5.size() << BLANC << std::endl;
	etat_vector(ft_vector5, std_vector5);
	
	std::cout << "max_size       : " << BLEU_2 << ft_vector5.max_size() << BLANC << std::endl;
	std::cout << "max_size       : " << VERT << std_vector5.max_size() << BLANC << std::endl;
	etat_vector(ft_vector5, std_vector5);
	std::cout << "capacity       : " << BLEU_2 << ft_vector5.capacity() << BLANC << std::endl;
	std::cout << "capacity       : " << VERT << std_vector5.capacity() << BLANC << std::endl;
	std::cout << "empty          : " << BLEU_2 << ft_vector5.empty() << BLANC << std::endl;
	std::cout << "empty          : " << VERT << std_vector5.empty() << BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 14 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 15 resize"<< BLANC << std::endl;
	ft_vector5.resize(3);
	std_vector5.resize(3);
	etat_vector(ft_vector5, std_vector5);
	std::cout << VIOLET "VECTOR TEST N 15 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET "VECTOR TEST N 16 reserve"<< BLANC << std::endl;
	ft_vector5.reserve(5);
	std_vector5.reserve(5);
	etat_vector(ft_vector5, std_vector5);
	std::cout << VIOLET "VECTOR TEST N 16 fin\n"<< BLANC << std::endl;
	std::cout << VIOLET << "---------------fin des teste ft---------------" << BLANC << std::endl;
}