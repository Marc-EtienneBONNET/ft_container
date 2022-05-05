/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:32:37 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/05 17:29:56 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_define_include.hpp"

void	info_moniteur_iterator(int nb, std::string consigne)
{
	std::cout << VIOLET "iterator TEST N " << nb << " : "<< consigne << BLANC << std::endl;
}

template<class T, class Y>
void	etat_iterator(T &ft_iterator, Y std_iterator)
{
	std::cout << BLEU << "Debut comparaison ft::vector::iterator std::vector::iterator" << BLANC << std::endl;
	std::cout << "       ft|std" << std::endl;
	std::cout << "_ptr :\t" << BLEU_2 << *(ft_iterator) << BLANC << "|" << VERT << *(std_iterator) << BLANC << std::endl;
	std::cout << std::endl; 
}



void	teste_iterator()
{
	ft::vector<int> ft_vector0;
	std::vector<int> std_vector0;
	ft_vector0.push_back(1);
	ft_vector0.push_back(2);
	ft_vector0.push_back(3);
	ft_vector0.push_back(4);
	ft_vector0.push_back(5);
	std_vector0.push_back(1);
	std_vector0.push_back(2);
	std_vector0.push_back(3);
	std_vector0.push_back(4);
	std_vector0.push_back(5);
	std::cout << "Dans le cardes de ce teste, nous avons init un iterator vector de ft et 1 de std avec 5 valeur de 1 a 5" << std::endl;
	std::cout << VIOLET << "---------------deb des teste constructeur---------------" << BLANC << std::endl;
	info_moniteur_iterator(0,"init d un iterator par copie");
	ft::vector<int>::iterator ft_iterator1(ft_vector0.begin());
	std::vector<int>::iterator std_iterator1(std_vector0.begin());
	etat_iterator(ft_iterator1, std_iterator1);
	info_moniteur_iterator(0,"fin");
	info_moniteur_iterator(1,"operateur de comparaison");
	ft::vector<int>::iterator ft_iterator2(ft_vector0.begin() + 3);
	std::vector<int>::iterator std_iterator2(std_vector0.begin() + 3);
	ft::vector<int>::iterator ft_iterator3(ft_vector0.begin());
	std::vector<int>::iterator std_iterator3(std_vector0.begin());
	std::cout << "          ft|std" << std::endl;
	std::cout << "it1==it1 : " << (ft_iterator1 == ft_iterator1) << "|" << (std_iterator1 == std_iterator1) << std::endl;
	std::cout << "it1==it2 : " << (ft_iterator1 == ft_iterator2) << "|" << (std_iterator1 == std_iterator2) << std::endl;
	std::cout << "it1==it3 : " << (ft_iterator1 == ft_iterator3) << "|" << (std_iterator1 == std_iterator3) << std::endl << std::endl;
	std::cout << "          ft|std" << std::endl;
	std::cout << "it1!=it1 : " << (ft_iterator1 != ft_iterator1) << "|" << (std_iterator1 != std_iterator1) << std::endl;
	std::cout << "it1!=it2 : " << (ft_iterator1 != ft_iterator2) << "|" << (std_iterator1 != std_iterator2) << std::endl;
	std::cout << "it1!=it3 : " << (ft_iterator1 != ft_iterator3) << "|" << (std_iterator1 != std_iterator3) << std::endl << std::endl;
	std::cout << "          ft|std" << std::endl;
	std::cout << "it1 < it1 : " << (ft_iterator1 < ft_iterator1) << "|" << (std_iterator1 < std_iterator1) << std::endl;
	std::cout << "it1 < it2 : " << (ft_iterator1 < ft_iterator2) << "|" << (std_iterator1 < std_iterator2) << std::endl;
	std::cout << "it1 < it3 : " << (ft_iterator1 < ft_iterator3) << "|" << (std_iterator1 < std_iterator3) << std::endl << std::endl;
	std::cout << "          ft|std" << std::endl;
	std::cout << "it1 > it1 : " << (ft_iterator1 > ft_iterator1) << "|" << (std_iterator1 > std_iterator1) << std::endl;
	std::cout << "it1 > it2 : " << (ft_iterator1 > ft_iterator2) << "|" << (std_iterator1 > std_iterator2) << std::endl;
	std::cout << "it1 > it3 : " << (ft_iterator1 > ft_iterator3) << "|" << (std_iterator1 > std_iterator3) << std::endl << std::endl;
		std::cout << "          ft|std" << std::endl;
	std::cout << "it1 >= it1 : " << (ft_iterator1 >= ft_iterator1) << "|" << (std_iterator1 >= std_iterator1) << std::endl;
	std::cout << "it1 >= it2 : " << (ft_iterator1 >= ft_iterator2) << "|" << (std_iterator1 >= std_iterator2) << std::endl;
	std::cout << "it1 >= it3 : " << (ft_iterator1 >= ft_iterator3) << "|" << (std_iterator1 >= std_iterator3) << std::endl << std::endl;
		std::cout << "          ft|std" << std::endl;
	std::cout << "it1<=it1 : " << (ft_iterator1 <= ft_iterator1) << "|" << (std_iterator1 <= std_iterator1) << std::endl;
	std::cout << "it1<=it2 : " << (ft_iterator1 <= ft_iterator2) << "|" << (std_iterator1 <= std_iterator2) << std::endl;
	std::cout << "it1<=it3 : " << (ft_iterator1 <= ft_iterator3) << "|" << (std_iterator1 <= std_iterator3) << std::endl << std::endl;
	info_moniteur_iterator(1,"fin");
	info_moniteur_iterator(2,"operateur de comparaison");
	std::cout << "          ft|std" << std::endl;
	std::cout << " ++: " << *(ft_iterator1++) << "|" << *(std_iterator1++) << std::endl;
	std::cout << "++ : " << *(++ft_iterator1) << "|" << *(++std_iterator1) << std::endl;
	std::cout << " --: " << *(ft_iterator1--) << "|" << *(std_iterator1--) << std::endl;
	std::cout << "-- : " << *(--ft_iterator1) << "|" << *(--std_iterator1) << std::endl;
	ft_iterator1++;
	std_iterator1++;
	std::cout << "   : " << *(ft_iterator1) << "|" << *(std_iterator1) << std::endl;
	std::cout << "-  : " << *(ft_iterator1 - 1) << "|" << *(std_iterator1 - 1) << std::endl;
	std::cout << "-  : " << (ft_iterator1 - (ft_iterator1 + 1)) << "|" << (std_iterator1 - (std_iterator1 + 1)) << std::endl;
	std::cout << "+=  : " << *(ft_iterator1 += 3) << "|" << *(std_iterator1 += 3) << std::endl;
	std::cout << "-=  : " << *(ft_iterator1 -= 2) << "|" << *(std_iterator1 -= 2) << std::endl;
	std::cout << "[]  : " << ft_iterator1[1] << "|" << std_iterator1[1] << std::endl;
	info_moniteur_iterator(2,"fin");
	info_moniteur_iterator(3,"const iterator");
	ft::vector<int>::const_iterator ft_iterator4(ft_vector0.begin() + 3);
	std::vector<int>::const_iterator std_iterator4(std_vector0.begin() + 3);
	ft::vector<int>::const_iterator ft_iterator5(ft_vector0.begin());
	std::vector<int>::const_iterator std_iterator5(std_vector0.begin());
	std::cout << "            ft|std" << std::endl;
	std::cout << "it1==it4   : " << (ft_iterator1 == ft_iterator4) << "|" << (std_iterator1 == std_iterator4) << std::endl;
	std::cout << "it1==it5   : " << (ft_iterator1 == ft_iterator5) << "|" << (std_iterator1 == std_iterator5) << std::endl;
	std::cout << "it1!=it4   : " << (ft_iterator1 != ft_iterator4) << "|" << (std_iterator1 != std_iterator4) << std::endl;
	std::cout << "it1!=it5   : " << (ft_iterator1 != ft_iterator5) << "|" << (std_iterator1 != std_iterator5) << std::endl;
	std::cout << "it1 < it4  : " << (ft_iterator1 < ft_iterator4) << "|" << (std_iterator1 < std_iterator4) << std::endl;
	std::cout << "it1 < it5  : " << (ft_iterator1 < ft_iterator5) << "|" << (std_iterator1 < std_iterator5) << std::endl;
	std::cout << "it1 > it4  : " << (ft_iterator1 > ft_iterator4) << "|" << (std_iterator1 > std_iterator4) << std::endl;
	std::cout << "it1 > it5  : " << (ft_iterator1 > ft_iterator5) << "|" << (std_iterator1 > std_iterator5) << std::endl;
	std::cout << "it1 >= it4 : " << (ft_iterator1 >= ft_iterator4) << "|" << (std_iterator1 >= std_iterator4) << std::endl;
	std::cout << "it1 >= it5 : " << (ft_iterator1 >= ft_iterator5) << "|" << (std_iterator1 >= std_iterator5) << std::endl;
	std::cout << "it1 <= it4 : " << (ft_iterator1 <= ft_iterator4) << "|" << (std_iterator1 <= std_iterator4) << std::endl;
	std::cout << "it1 <= it5 : " << (ft_iterator1 <= ft_iterator5) << "|" << (std_iterator1 <= std_iterator5) << std::endl;
	info_moniteur_iterator(3,"fin");
}

void	teste_reverse_iterator()
{
	ft::vector<int> ft_vector0;
	std::vector<int> std_vector0;
	ft_vector0.push_back(1);
	ft_vector0.push_back(2);
	ft_vector0.push_back(3);
	ft_vector0.push_back(4);
	ft_vector0.push_back(5);
	std_vector0.push_back(1);
	std_vector0.push_back(2);
	std_vector0.push_back(3);
	std_vector0.push_back(4);
	std_vector0.push_back(5);
	std::cout << "Dans le cardes de ce teste, nous avons init un iterator vector de ft et 1 de std avec 5 valeur de 1 a 5" << std::endl;
	std::cout << VIOLET << "---------------deb des teste constructeur---------------" << BLANC << std::endl;
	info_moniteur_iterator(0,"init d un reverse_iterator par copie");
	ft::vector<int>::reverse_iterator ft_iterator1(ft_vector0.begin());
	std::vector<int>::reverse_iterator std_iterator1(std_vector0.begin());
	etat_iterator(ft_iterator1, std_iterator1);
	info_moniteur_iterator(0,"fin");
	ft::vector<int>::reverse_iterator ft_iterator2(ft_vector0.begin() + 3);
	std::vector<int>::reverse_iterator std_iterator2(std_vector0.begin() + 3);
	ft::vector<int>::reverse_iterator ft_iterator3(ft_vector0.begin());
	std::vector<int>::reverse_iterator std_iterator3(std_vector0.begin());
	info_moniteur_iterator(2,"operateur de comparaison");
	std::cout << "     ft|std" << std::endl;
	std::cout << "it1==it1 : " << (ft_iterator1 == ft_iterator1) << "|" << (std_iterator1 == std_iterator1) << std::endl;

	std::cout << "--  : " << *(--ft_iterator1) << "|" << *(--std_iterator1) << std::endl;
	std::cout << "  --: " << *(ft_iterator1--) << "|" << *(std_iterator1--) << std::endl;
	std::cout << "++  : " << *(++ft_iterator1) << "|" << *(++std_iterator1) << std::endl;
	std::cout << "  ++: " << *(ft_iterator1++) << "|" << *(std_iterator1++) << std::endl;
	ft_iterator1--;
	std_iterator1--;
	std::cout << "    : " << *(ft_iterator1) << "|" << *(std_iterator1) << std::endl;
	std::cout << "-   : " << *(ft_iterator1 - 1) << "|" << *(std_iterator1 - 1) << std::endl;
	std::cout << "-   : " << (ft_iterator1 - (ft_iterator1 + 1)) << "|" << (std_iterator1 - (std_iterator1 + 1)) << std::endl;
	std::cout << "-=  : " << *(ft_iterator1 -= 3) << "|" << *(std_iterator1 -= 3) << std::endl;
	std::cout << "+=  : " << *(ft_iterator1 += 2) << "|" << *(std_iterator1 += 2) << std::endl;
	std::cout << "[]  : " << ft_iterator1[1] << "|" << std_iterator1[1] << std::endl;
	info_moniteur_iterator(2,"fin");
}
