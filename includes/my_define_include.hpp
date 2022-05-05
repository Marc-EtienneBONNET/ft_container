/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_define_include.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:14:08 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/05 17:24:59 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_DEFINE_INCLUDE_H
# define MY_DEFINE_INCLUDE_H
# include <iostream>
# include <string>
# include <iterator>
# include <memory>
# include <limits>
# include <cstddef>
#include <vector>

# define BLEU "\e[1;36m"
# define BLEU_2 "\e[1;34m"
# define ROUGE "\e[1;31m"
# define VERT "\e[1;32m"
# define JAUNE "\e[1;33m"
# define VIOLET "\e[1;35m"
# define BLANC "\e[0m"
# include "ft.hpp"
# include "iterator/random_access_iterator.hpp"
# include "iterator/random_access_riverse_iterator.hpp"
# include "vector.hpp"
# include "stack.hpp"

void	teste_vector();
void	teste_iterator();
void	teste_reverse_iterator();


#endif