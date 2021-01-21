/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:12:59 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/30 18:14:39 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

char	*proverka(char **point, char *ostatok)
{
	char *str;

	if ((*point = ft_strchr(ostatok, '\n')) != NULL)
	{
		str = ft_strsub(ostatok, 0, *point - ostatok);
		ft_strcpy(ostatok, ++(*point));
	}
	else
	{
		str = ft_strnew(ft_strlen(ostatok) + 1);
		ft_strcat(str, ostatok);
		ft_strclr(ostatok);
	}
	return (str);
}

int		get_next_line2(const int fd, char **line, char **ostatok)
{
	char			buffer[BUFF_SIZE + 1];
	int				used_byte;
	char			*point;
	char			*tmp;

	point = NULL;
	used_byte = 1;
	*line = proverka(&point, *ostatok);
	while (point == 0 && ((used_byte = read(fd, buffer, BUFF_SIZE)) != 0))
	{
		buffer[used_byte] = '\0';
		if ((point = ft_strchr(buffer, '\n')))
		{
			ft_strcpy(*ostatok, ++point);
			ft_strclr(--point);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buffer)) || used_byte < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return (used_byte || ft_strlen(*line)) ? 1 : 0;
}

t_gnl	*noviy_spisok(const int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->ostatok = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*osnova;
	t_gnl			*tmp;
	int				result;

	if (fd < 0 || line == 0)
		return (-1);
	if (!osnova)
		osnova = noviy_spisok(fd);
	tmp = osnova;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = noviy_spisok(fd);
		tmp = tmp->next;
	}
	result = get_next_line2(fd, line, &tmp->ostatok);
	return (result);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ret;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	line = NULL;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		printf("%s\treturn value - %d\n", line, ret);
		ft_strdel(&line);
	}
	close(fd);
//	while (1);  //for check on leaks (leaks a.out)
}
