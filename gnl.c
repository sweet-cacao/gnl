/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:14:55 by gstarvin          #+#    #+#             */
/*   Updated: 2019/09/17 20:02:00 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

static char *s = NULL;

int		is_endl()
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char *buff;
//[BUFF_SIZE + 1];
	int nbread;
	char *tmp;
	buff = malloc(1000);
	(void) memset((void *)buff, 0, (size_t)BUFF_SIZE + 1);
	if (fd < 0)
		return (-1);
//	if (nbread == -1 || nbread == 0)
//		return (0);
	s = malloc(1000);
	while  ((nbread = read(fd, (void *)buff, BUFF_SIZE)) > 0)
	{
		buff[nbread] = '\0';
		printf("buff = %s\n", buff);
		tmp = ft_strjoin(s, buff);
		printf("tmp = %s\n", tmp);
		free (s);
		s = malloc(1000);
		s = tmp;
		printf("s = %s\n", s);
		int end = is_endl();
//		printf ("is_endl = %d", is_endl());
		if (end > 0)
		{
			printf ("is_endl = %d\n", end);
			ft_strncpy(*line, &s[0], end);
			printf("line = %s\n", *line);
			break ;
		}
		(void) memset((void *)buff, 0, BUFF_SIZE);
	}
	free(buff);
}

int		main()
{
	int fd;
	char *line;
	line = malloc(1000);
	(void) memset((void *)line, 0, (size_t)1000);
	fd = open("./file.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
	return (0);
}
