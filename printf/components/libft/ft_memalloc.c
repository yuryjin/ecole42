/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:09:17 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/16 18:11:41 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = malloc(size);
	if (memory == NULL)
		return (NULL);
	ft_memset(memory, 0, size);
	return (memory);
}
