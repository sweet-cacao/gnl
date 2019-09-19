/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:14:55 by gstarvin          #+#    #+#             */
/*   Updated: 2019/09/19 16:49:16 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_endl(char *s)
{
	int b = 0;	
	int i = 0;
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
	char *buff;
	int nbread;
	char *tmp;
	
	nbread = 0;
	buff = (char *)malloc(sizeof(*buff) * BUFF_SIZE + 1);
	(void) memset((void *)buff, 0, (size_t)BUFF_SIZE + 1);
	*s = (char *)malloc(sizeof(*buff) * BUFF_SIZE + 1);
	while  ((nbread = read(fd, (void *)buff, BUFF_SIZE)) > 0)
	{
		buff[nbread] = '\0';
		tmp = ft_strjoin(*s, buff);
		free (*s);
		*s = (char *)malloc(sizeof(tmp));
		*s = tmp;
		(void) memset((void *)buff, 0, BUFF_SIZE);
	}
	free(buff);
	if (nbread == -1)
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *s;
	int end;
	
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
