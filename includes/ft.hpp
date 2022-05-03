/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:29:56 by mbonnet           #+#    #+#             */
/*   Updated: 2022/05/03 15:51:25 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPP
#define FT_HPP

namespace ft
{
	struct random_access_iterator_tag {};
	template <bool isConstant, typename const_type, typename notConst_type>
	struct is_constant{};

	template <typename const_type, typename notConst_type>
	struct is_constant<true, const_type, notConst_type> { typedef const_type type;};

	template <typename const_type, typename notConst_type>
	struct is_constant<false, const_type, notConst_type> { typedef notConst_type type;};
	
}


#endif