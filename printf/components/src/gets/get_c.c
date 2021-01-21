/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/11/17 22:23:46 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		printf_c(t_pf_argums *arguments, char argchar)
{
	char	subst;
	int		widthval;

	widthval = arguments->width;
	subst = ' ';
	arguments->flags & PF_FLAG_ZERO ? subst = ' ' : 0;
	while (widthval > 1 && !(arguments->flags & PF_FLAG_MINUS))
	{
		write(1, &subst, 1);
		widthval--;
		arguments->outputlen++;
	}
	write(1, &argchar, 1);
	arguments->outputlen++;
	while (widthval > 1 && arguments->flags & PF_FLAG_MINUS)
	{
		write(1, &subst, 1);
		widthval--;
		arguments->outputlen++;
	}
	return (0);
}

int		get_c(t_pf_argums *arguments, va_list list)
{
	char	argchar;
	int		j;

	j = 0;
	argchar = va_arg(list, int);
	printf_c(arguments, argchar);
	return (0);
}
