/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:09:38 by mbonnet           #+#    #+#             */
/*   Updated: 2022/04/07 13:43:48 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_define_include.hpp"

int	main(void)
{
	my_vector<int> test1_vector;
	my_vector<int> test2_vector(3,10);
	for (my_vector<int>::pointeur it = test2_vector._start; it != test2_vector._end; it++)
		std::cout << "test2_vector contenue : " << *it << std::endl;
	std::cout << "test1_vector: " << test1_vector.size() << std::endl;
	std::cout << "test2_vector: " << test2_vector.size() << std::endl;
	//std::cout << "test2_vector : " << test1_vector._start << std::endl;
	//my_vector<int> test3_vector(test2_vector.begin(),test2_vector.end());

	//for (int x = 0; x < 10 ; x++)
	//	std::cout << "test2_vector : " << test2_vector.tab[x] << std::endl;
	return (0);
}