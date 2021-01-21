/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:12:58 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/24 18:25:31 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*memory;

	if (!(memory = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	memory[size] = 0;
	while (size--)
		memory[size] = '\0';
	return (memory);
}
