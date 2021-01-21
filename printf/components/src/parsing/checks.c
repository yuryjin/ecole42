/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:59:12 by zlucan            #+#    #+#             */
/*   Updated: 2020/11/17 21:59:21 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

inline extern int			ft_is_conversion(const char c)
{
	return (ft_strchr("dDioOuUxXeEfFgGaAcCsSpn%", c) != NULL);
}

inline extern int			ft_is_modifier(const char c)
{
	return (ft_strchr("hljz", c) != NULL);
}

inline extern int			ft_is_flag(const char c)
{
	return (ft_strchr("#0-+' ", c) != NULL);
}

inline extern int			ft_is_precision(const char c)
{
	return (ft_strchr("$*.", c) != NULL);
}

inline int					ft_is_valid(const char c)
{
	return (ft_is_conversion(c) || ft_is_modifier(c) || ft_is_flag(c) ||
			ft_isdigit(c) || ft_is_precision(c));
}
