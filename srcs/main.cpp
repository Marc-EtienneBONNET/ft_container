/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:09:38 by mbonnet           #+#    #+#             */
/*   Updated: 2022/04/06 17:36:43 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_define_include.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	//int myints_3[] = {2,30,7,30};
	my_vector<int> test_1;
	
	//std::cout << std::endl << VIOLET << "----------test de cpp : 0----------" << BLANC << std::endl;

	/*
	std::cout << std::endl << VIOLET << "----------test de cpp : 1----------" << BLANC << std::endl;
	std::vector<int> first;                                // empty vector of ints
  	
	  std::vector<int> second (4,100);                       // four ints with value 100
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
   		std::cout << ' ' << *it;
	std::cout << std::endl << VIOLET << "----------test de cpp : 2----------" << BLANC << std::endl;
  
  	std::vector<int> third (second.begin(),second.end());  // iterating through second
	for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
   		std::cout << ' ' << *it;
	std::cout << std::endl << VIOLET << "----------test de cpp : 3----------" << BLANC << std::endl;
 	
	std::vector<int> fourth (third);                       // a copy of third
	for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
   		std::cout << ' ' << *it;
	std::cout << std::endl << VIOLET << "----------test de cpp : 4----------" << BLANC << std::endl;
	int myints[] = {16,2,77,29};
	int myints_2[] = {2,30,7,30};
	std::cout << "ici : " << myints + sizeof(myints) / sizeof(int)  << std::endl;
	std::cout << "ici : " << myints  << std::endl;
	  std::vector<int> fifth (myints_2, myints_2 + sizeof(myints_2) / sizeof(int) );
  	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
   		std::cout << ' ' << *it;
  	std::cout << '\n';
	*/
	return (0);
}