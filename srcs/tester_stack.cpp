/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_stack.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:32:37 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/05 23:13:04 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_define_include.hpp"

void	info_moniteur_stack(int nb, std::string consigne)
{
	std::cout << VIOLET "iterator TEST N " << nb << " : "<< consigne << BLANC << std::endl;
}

template<class T, class Y>
void	etat_stack(T &ft_stack, Y &std_stack)
{
	std::cout << BLEU << "Debut comparaison ft::vector::iterator std::vector::iterator" << BLANC << std::endl;
	std::cout << "       ft|std" << std::endl;
	std::cout << "_ptr :\t" << BLEU_2 << *(ft_stack.begin()) << BLANC << "|" << VERT << *(std_stack.begin()) << BLANC << std::endl;
	std::cout << std::endl; 
}

void	teste_stack()
{
	ft::vector<int> ft_tmp(3,10);
	std::vector<int> std_tmp(3,10);
	ft::vector<int> ft_tmp2(3,42);
	std::vector<int> std_tmp2(3,42);
	ft::stack<int> ft_stack0;
	std::stack<int> std_stack0;
	
	ft::stack<int, ft::vector<int> > ft_stack1(ft_tmp);
	std::stack<int, std::vector<int> > std_stack1(std_tmp);
	ft::stack<int, ft::vector<int> > ft_stack2(ft_tmp2);
	std::stack<int, std::vector<int> > std_stack2(std_tmp2);
	std::cout << VIOLET << "---------------deb des teste reserve iterator---------------" << BLANC << std::endl;
	std::cout << "top   : " << ft_stack1.top() << "|" << std_stack1.top() << std::endl;
	std::cout << "empty : " << ft_stack1.empty() << "|" << std_stack1.empty() << std::endl;
	std::cout << "size  : " << ft_stack1.size() << "|" << std_stack1.size() << std::endl;
	std::cout << "test push * 1" << std::endl;
	ft_stack1.push(4);
	std_stack1.push(4);
	std::cout << "size  : " << ft_stack1.size() << "|" << std_stack1.size() << std::endl;
	std::cout << "test push * 4" << std::endl;
	ft_stack1.pop();
	std_stack1.pop();
	ft_stack1.pop();
	std_stack1.pop();
	ft_stack1.pop();
	std_stack1.pop();
	ft_stack1.pop();
	std_stack1.pop();
	std::cout << "size  : " << ft_stack1.size() << "|" << std_stack1.size() << std::endl;
	std::cout << "empty : " << ft_stack1.empty() << "|" << std_stack1.empty() << std::endl;
	std::cout << "operator :" << std::endl;
	std::cout << "== " << (ft_stack1 == ft_stack2) << "|"  << (std_stack1 == std_stack2)<< std::endl;
	std::cout << "!= " << (ft_stack1 != ft_stack2) << "|"  << (std_stack1 != std_stack2)<< std::endl;
	std::cout << "<  " << (ft_stack1 < ft_stack2) << "|"  << (std_stack1 < std_stack2)<< std::endl;
	std::cout << ">  " << (ft_stack1 > ft_stack2) << "|"  << (std_stack1 > std_stack2)<< std::endl;
	std::cout << "<=  " << (ft_stack1 <= ft_stack2) << "|"  << (std_stack1 <= std_stack2)<< std::endl;
	std::cout << ">=  " << (ft_stack1 >= ft_stack2) << "|"  << (std_stack1 >= std_stack2)<< std::endl;


	
	std::cout << VIOLET << "---------------fin des teste reserve iterator---------------" << BLANC << std::endl;

}
