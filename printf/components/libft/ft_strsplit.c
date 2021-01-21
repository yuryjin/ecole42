/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:30:22 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/24 18:25:31 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		nb_wrds(const char *s, char c)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (*s)
	{
		if (j == 1 && *s == c)
			j = 0;
		if (j == 0 && *s != c)
		{
			j = 1;
			i++;
		}
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb;
	char	**result;
	int		i;
	int		j;
	int		point;

	if ((s == 0) || (c == 0))
		return (NULL);
	nb = nb_wrds(s, c);
	if (!(result = malloc((sizeof(char *) * (nb + 1)))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < nb)
	{
		while (s[i] && s[i] == c)
			i++;
		point = i;
		while (s[i] && s[i] != c)
			i++;
		result[j] = ft_strsub(s, point, i - point);
		i++;
	}
	result[j] = NULL;
	return (result);
}
