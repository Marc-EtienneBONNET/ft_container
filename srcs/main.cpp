/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:09:38 by mbonnet           #+#    #+#             */
/*   Updated: 2022/04/12 19:43:30 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_define_include.hpp"

int	main(void)
{
	int	tab[] = {1,20,30,40};
	std::vector<int> test;
	test.push_back(1);
	test.push_back(20);
	test.push_back(30);
	test.push_back(40);

	R_A_iterator<int> test_iterator(tab);
	int	tab2[] = {1,20,30,40};
	std::vector<int>::iterator i_tem = test.begin();
	R_A_iterator<int> tmp;
	R_A_iterator<int> tmp2;
	std::cout << VIOLET << "nombre rentrer dans le test : 1, 20, 30, 40" << BLANC << std::endl; 
	std::cout << VIOLET << "--------Random_access_iterator--------" << BLANC << std::endl;
	std::cout << "methode getVal : " << *test_iterator << std::endl;
	//std::cout << "methode getVal : " << i_tem.getValPointeur() << std::endl;

	std::cout << "methode get    : " << test_iterator.getPointeur() << std::endl;
	std::cout << BLEU << "---operateur(++) ---" << BLANC << std::endl;
	++test_iterator;
	std::cout << "methode getVal : " << test_iterator.getValPointeur() << std::endl;
	std::cout << BLEU << "---operateur(--) ---" << BLANC << std::endl;
	--test_iterator;
	std::cout << "methode getVal : " << test_iterator.getValPointeur() << std::endl;
	std::cout << BLEU << "---operateur(+(+2)) ---" << BLANC << std::endl;
	tmp = test_iterator + 2;
	std::cout << "methode getVal : " <<  tmp.getValPointeur() << std::endl;
	std::cout << BLEU << "---operateur(-(-2)) ---" << BLANC << std::endl;
	tmp2 = tmp - 4;
	std::cout << "methode getVal : " << tmp2.getValPointeur() << std::endl;
	std::cout << BLEU << "---operateur(+=3) ---" << BLANC << std::endl;
	test_iterator += 3;
	std::cout << "methode getVal : " << test_iterator.getValPointeur() << std::endl;
	std::cout << BLEU << "---operateur(-=3) ---" << BLANC << std::endl;
	test_iterator -= 3;
	std::cout << "methode getVal : " << test_iterator.getValPointeur() << std::endl;
	std::cout << BLEU << "---operateur(+= lui meme) ---" << BLANC << std::endl;
	test_iterator += test_iterator.getValPointeur();
	std::cout << "methode getVal : " << test_iterator.getValPointeur() << std::endl;
	std::cout << BLEU << "---operateur(-= lui meme) ---" << BLANC << std::endl;
	test_iterator -= test_iterator.getValPointeur();
	std::cout << "methode getVal : " << test_iterator.getValPointeur() << std::endl;
	std::cout << BLEU << "---operateur([2]) ---" << BLANC << std::endl;
	std::cout << "methode getVal : " << test_iterator[2] << std::endl;
	std::cout << BLEU << "---operateur de comparaison ---" << BLANC << std::endl;
	std::cout << BLEU << "\toperateur ==" << BLANC << std::endl;
	if (test_iterator == tmp2)
		std::cout << "\tles deux iterateur sont egaux" << std::endl;
	else 
		std::cout << "\tles deux iterateur sont inegaux" << std::endl;
	std::cout << BLEU << "\toperateur !=" << BLANC <<std::endl;
	if (test_iterator != tmp2)
		std::cout << "\tles deux iterateur sont inegaux" << std::endl;
	else 
		std::cout << "\tles deux iterateur sont egaux" << std::endl;
	std::cout << BLEU << "\toperateur <=" << BLANC <<std::endl;
	if (test_iterator <= tmp2)
		std::cout << "\tval test_iterateur <= a tmp2" << std::endl;
	else 
		std::cout << "\tval test_iterateur > a tmp2" << std::endl;
	std::cout << BLEU << "\toperateur >=" << BLANC <<std::endl;
	if (test_iterator >= tmp2)
		std::cout << "\tval test_iterateur >= a tmp2" << std::endl;
	else 
		std::cout << "\tval test_iterateur < a tmp2" << std::endl;
	std::cout << BLEU << "\toperateur >" << BLANC <<std::endl;
	if (test_iterator > tmp2)
		std::cout << "\tval test_iterateur > a tmp2" << std::endl;
	else 
		std::cout << "\tval test_iterateur <= a tmp2" << std::endl;
	std::cout << BLEU << "\toperateur <" << BLANC << std::endl;
	if (test_iterator < tmp2)
		std::cout << "\tval test_iterateur < a tmp2" << std::endl;
	else 
		std::cout << "\tval test_iterateur >= a tmp2" << std::endl;






	//std::cout << "operator << : " << test_iterator << std::endl;
	return (0);
}