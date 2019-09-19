/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:01:34 by gstarvin          #+#    #+#             */
/*   Updated: 2019/09/19 18:02:12 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_endl(char *s)
{
	int b;
	int i;

	i = 0;
	b = 0;
	if (s[i] == '\0')
		return (-1);
	while (s[i] == '\n')
	{
		i++;
		b++;
	}
	s = (s + b);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int		read_doc(int fd, char **s)
{
	char	buff[BUFF_SIZE + 1];
	int		nbread;
	char	*tmp;

	nbread = 0;
//	buff = (char *)malloc(sizeof(*buff) * BUFF_SIZE + 1);
	*s = ft_strnew(BUFF_SIZE);
//	*s = (char *)malloc(sizeof(*buff) * BUFF_SIZE + 1);
	while ((nbread = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbread] = '\0';
		tmp = ft_strjoin(*s, buff);
		ft_strdel(&*s);
		*s = ft_strdup(tmp);
		ft_strdel(&tmp);
		/*
		free(s);
		*s = (char *)malloc(sizeof(tmp));
		*s = tmp;*/
	}
//	free(buff);
	if (nbread == -1)
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *s;
	int			end;

	end = 0;
	if (!s)
		read_doc(fd, &s);
	while (*s == '\n')
		s++;
	end = is_endl(s);
	if (end >= 0)
	{
		*line = ft_strnew(end);
		ft_memmove(*line, s, end);
		s += end + 1;
		return (1);
	}
	if (end == -1)
	{
		return (-1);
	}
	return (0);
}
