/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:14:55 by gstarvin          #+#    #+#             */
/*   Updated: 2019/09/18 11:20:20 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

static char *s = NULL;

int		is_endl()
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
	s += b;
	i = 0;
	printf ("b = %d\n", b);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	i--;
	return (i);
}



int	get_next_line(int fd, char **line)
{
	char *buff;
	int nbread = 0;
	char *tmp;
	int end;

	end = 0;	
	nbread = 0;
	buff = (char *)malloc(sizeof(*buff) * BUFF_SIZE + 1);
	(void) memset((void *)buff, 0, (size_t)BUFF_SIZE + 1);
	if (fd < 0)
		return (-1);
	if (!s)
		s = (char *)malloc(sizeof(*buff) * BUFF_SIZE + 1);
	while  ((nbread = read(fd, (void *)buff, BUFF_SIZE)) > 0)
	{
		buff[nbread] = '\0';
		tmp = ft_strjoin(s, buff);
		free (s);
		s = (char *)malloc(sizeof(tmp));
		s = tmp;
		(void) memset((void *)buff, 0, BUFF_SIZE);
	}
	free(buff);
	if (nbread == -1)
		return (-1);
	end = is_endl();
	printf ("is_endl = %d\n", end);
	printf ("nbread = %d\n", end);
	if (end >= 0)
	{
		ft_memmove(*line, s, end);
		s += end + 1;
//		printf ("the rest of s = %s", s);
		return (1);
	}
	if (end == -1)
		return (-1);
	return (0);
}

int		main()
{
	int fd;
	char *line;
	line = malloc(1000);
	(void) memset((void *)line, 0, (size_t)1000);
	fd = open("./file.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
	return (0);
}
