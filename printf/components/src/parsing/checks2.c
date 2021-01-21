/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:59:31 by zlucan            #+#    #+#             */
/*   Updated: 2020/11/17 21:59:35 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

inline int					ft_is_valid_not_conversion(const char c)
{
	return (ft_is_modifier(c) || ft_is_flag(c) ||
			ft_isdigit(c) || ft_is_precision(c));
}
