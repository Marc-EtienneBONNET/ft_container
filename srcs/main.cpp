/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:09:38 by mbonnet           #+#    #+#             */
/*   Updated: 2022/04/07 18:02:37 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_define_include.hpp"

int	main(void)
{
	int	tab[] = {1,2,3,4};
	R_A_iterator<int> test_iterator(tab);
	std::cout << VIOLET << "--------Random_access_iterator--------" << BLANC << std::endl;
	std::cout << "methode getVal : " << test_iterator.getValPointeur() << std::endl;
	std::cout << "methode get    : " << test_iterator.getPointeur() << std::endl;
	std::cout << "---operateur++ ---" << std::endl;
	++test_iterator;
	std::cout << "methode getVal : " << test_iterator.getValPointeur() << std::endl;
	std::cout << "---operateur-- ---" << std::endl;
	--test_iterator;
	std::cout << "methode getVal : " << test_iterator.getValPointeur() << std::endl;

	//std::cout << "operator << : " << test_iterator << std::endl;
	
	

	return (0);
}