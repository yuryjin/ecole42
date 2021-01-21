/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:30:25 by zlucan            #+#    #+#             */
/*   Updated: 2019/11/05 20:30:28 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *list)
{
	t_list	*element;
	int		i;

	i = 0;
	element = list;
	while (element)
	{
		element = element->next;
		i++;
	}
	return (i);
}
