/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:06:24 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/09 18:07:22 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_define_include.hpp"

void	teste_map()
{
	ft::map<int, int> test_map;
	ft::map<int, int> test_map2;
	std::cout << VIOLET << "Instanciation du tableau test_map" << BLANC << std::endl;
	std::cout << VIOLET << "Instanciation du tableau test_map2" << BLANC << std::endl;
	std::cout << VIOLET << "affichage de test_tmp : " << BLANC << std::endl;
	test_map.print();
	
	test_map2.insert(ft::make_pair(1,2));
	test_map2.insert(ft::make_pair(2,12));
	test_map2.insert(ft::make_pair(3,22));
	test_map2.insert(ft::make_pair(-2,32));
	test_map2.insert(ft::make_pair(-10,42));
	test_map.insert(ft::make_pair(1,10));
	test_map.insert(ft::make_pair(-3,10));
	test_map.insert(ft::make_pair(2,10));
	test_map.insert(ft::make_pair(-1,10));
	test_map.insert(++test_map.begin(),ft::make_pair(-2,10));
	std::cout << VIOLET << "test de la fonction insert : " << BLANC << std::endl;
	test_map.print();
	std::cout << VIOLET << "test de la fonction clear : " << BLANC << std::endl;
	test_map.clear();
	test_map.print();
	test_map.insert(ft::make_pair(1,10));
	test_map.insert(ft::make_pair(2,10));
	test_map.insert(ft::make_pair(3,10));
	test_map.insert(ft::make_pair(-2,42));
	std::cout << VIOLET << "reremplissage du test_map avec de nouvel valeur : " << BLANC << std::endl;
	test_map.print();
	std::cout << VIOLET << "test de la fonction ecrase : " << BLANC << std::endl;
	test_map.erase(test_map.find(1), test_map.find(3));
	test_map.print();
	test_map.erase(test_map.find(3));
	test_map.print();
	test_map.erase(-2);
	test_map.print();
	std::cout << VIOLET << "test de la fonction swap entre test_map et test_map2 : " << BLANC << std::endl;
	test_map.swap(test_map2);
	test_map.print();
	std::map<int, int> std_map;
	std_map.insert(std::make_pair(1,2));
	std_map.insert(std::make_pair(2,12));
	std_map.insert(std::make_pair(3,22));
	std_map.insert(std::make_pair(-2,32));
	std_map.insert(std::make_pair(-10,42));
	std::cout << VIOLET << "test des diverse fonction d affichage des info map : " << BLANC << std::endl;
	std::cout << "size tree        : " << BLEU_2 << test_map.size() << BLANC << " std : " << VERT << std_map.size() << BLANC << std::endl;
	std::cout << "count(9)         : " << BLEU_2 << test_map.count(9) << BLANC << " std : " << VERT << std_map.count(9) << BLANC << std::endl;
	std::cout << "count(2)         : " << BLEU_2 << test_map.count(2) << BLANC << " std : " << VERT << std_map.count(2) << BLANC << std::endl;
	std::cout << "count(-2)        : " << BLEU_2 << test_map.count(-2) << BLANC << " std : " << VERT << std_map.count(-2) << BLANC << std::endl;
	std::cout << "count(3)         : " << BLEU_2 << test_map.count(3) << BLANC << " std : " << VERT << std_map.count(3) << BLANC << std::endl;
	std::cout << "count(-10)       : " << BLEU_2 << test_map.count(-10) << BLANC << " std : " << VERT << std_map.count(-10) << BLANC << std::endl;
	std::cout << "count(1)         : " << BLEU_2 << test_map.count(1) << BLANC << " std : " << VERT << std_map.count(1) << BLANC << std::endl;
	std::cout << "max_size tree    : " << BLEU_2 << test_map.max_size() << BLANC << " std : " << VERT << std_map.max_size() << BLANC << std::endl;
	std::cout << "empty            : " << BLEU_2 << test_map.empty() << BLANC << " std : " << VERT << std_map.empty() << BLANC << std::endl;
	std::cout << "begin ()         : key = " << BLEU_2 << (test_map.begin())->first << BLANC " val = " << (test_map.begin())->second << std::endl;
	std::cout << "std begin ()     : key = " << VERT << (std_map.begin())->first << " val = " << (std_map.begin())->second << BLANC <<  std::endl;
	std::cout << "end ()           : key = " << BLEU_2 << (test_map.end())->first << " val = " << (test_map.end())->second << BLANC << std::endl;
	std::cout << "std end ()       : key = " << VERT << (std_map.end())->first << " val = " << (std_map.end())->second << BLANC << std::endl;
	std::cout << "operator[-2]     : val = " << BLEU_2 << test_map[-2] << BLANC << " std : " << VERT << std_map[-2] << BLANC << std::endl;
	std::cout << "operator[-10]    : val = " << BLEU_2 << test_map[-10]<< BLANC  << " std : " << VERT << std_map[-10] << BLANC << std::endl;
	std::cout << "operator[1]      : val = " << BLEU_2 << test_map[1] << BLANC << " std : " << VERT << std_map[1]  << BLANC << std::endl;
	std::cout << "lower_bound(0)   : " << BLEU_2 << test_map.lower_bound(0)->first << BLANC  << " std : " << VERT<< std_map.lower_bound(0)->first << BLANC << std::endl;
	std::cout << "upper_bound(0)   : " << BLEU_2 << test_map.upper_bound(0)->first << BLANC << " std : " << VERT<< std_map.upper_bound(0)->first << BLANC<< std::endl;
	

	
		
	
	

	std::cout << std::endl;

}
