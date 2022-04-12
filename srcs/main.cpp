/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:09:38 by mbonnet           #+#    #+#             */
/*   Updated: 2022/04/12 18:48:57 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_define_include.hpp"

int	main(void)
{
	int	tab[] = {1,20,30,40};
	R_A_iterator<int> test_iterator(tab);
	R_A_iterator<int> tmp;
	R_A_iterator<int> tmp2;
	std::cout << VIOLET << "nombre rentrer dans le test : 1, 20, 30, 40" << BLANC << std::endl; 
	std::cout << VIOLET << "--------Random_access_iterator--------" << BLANC << std::endl;
	std::cout << "methode getVal : " << test_iterator.getValPointeur() << std::endl;
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



	//std::cout << "operator << : " << test_iterator << std::endl;
	return (0);
}