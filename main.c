#include <stdio.h>
#include "header.h"
/*
int 	readlinewidth(int fd)
{
	char	buff[2];
	size_t	nbread;

	(void) memset((void *)buff, 0, (size_t)2);
	nbread = read(fd, (void *) buff, (size_t) 2);
	if (nbread == -1 || nbread == 0)
		return (-1);
	buff[1] = '\0';
	return (atoi(buff));
}
*/
void	readandprintlines(int fd, size_t linewidth)
{
	char	*buff;
	size_t	nbread;
	buff = (char *)malloc((linewidth + 1) * sizeof(*buff));
	if (buff == NULL)
		return ;
	(void) memset((void *)buff, 0, linewidth + 1);
	while ((nbread = read(fd, (void *)buff, linewidth)) != 0)
	{
		printf("%s", buff);
		(void) memset((void *)buff, 0, linewidth);
	}
	free(buff);
	return  ;
}

void get_next_line(int fd, char **line)
{
	while 
}

int main()
{
	int fd;
	int linewidth;

	fd = open("./file.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	linewidth = 1;
	if (linewidth == -1 || linewidth == 0)
		return (-1);
	readandprintlines(fd, (size_t) linewidth);
	close (fd);
	return (0);
}
