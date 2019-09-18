/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:14:55 by gstarvin          #+#    #+#             */
/*   Updated: 2019/09/18 15:11:04 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

//static char *s = NULL;

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
	printf("s befor + b = %s\n", s);
	s = (s + b);
	printf("s after + b= %s\n", s);
	i = 0;
	printf ("b = %d\n", b);
	printf("c = %c\n", s[i]);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	i--;
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
/*	char *buff;
	int nbread;
	char *tmp;
*/	int end;
	
	end = 0;
/*	nbread = 0;	
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
	
*/	if (!s)
		read_doc(fd, &s);
	while (*s == '\n')
		s++;
	end = is_endl(s);
	printf ("is_endl = %d\n", end);
//	printf ("nbread = %d\n", nbread);
	if (end >= 0)
	{
		printf ("-s for copy to line = %s", s);
		*line = ft_strnew(end);
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
//	line = malloc(1000);
//	(void) memset((void *)line, 0, (size_t)1000);
	fd = open("./file.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("OUTPUT = %s\n", line);
		free(line);
	}
	return (0);
}
