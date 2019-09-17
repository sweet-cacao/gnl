#include <stdio.h>
#include "header.h"

char 	read_byte(int fd)
{
	char	buff[2];
	size_t	nbread;

	(void) memset((void *)buff, 0, (size_t)2);
	nbread = read(fd, (void *) buff, (size_t) 2);
	if (nbread == -1 || nbread == 0)
		return (NULL);
	buff[1] = '\0';
	return (buff[0]);
}

int     ft_linelen(int fd)
{
        int linelen;

        linelen = 0;
        while (readbyte(fd) != '\n' || readbyte(fd) != NULL)
        {
                linelen++;
        }
        return (linelen);

}

void	readandprintline(int fd, size_t linelen)
{
	char	*buff;
	static size_t	nbread;
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

void	get_next_line(int fd, char **line)
{
	size_t linelen;

	linelen = ft_linelen(fd);
	readandprintline(fd, linelen);

}

int main()
{
	int fd;
	int linewidth;

	fd = open("./file.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	linewidth = BUFF_SIZE;
	if (linewidth == -1 || linewidth == 0)
		return (-1);
	readandprintlines(fd, (size_t) linewidth);
	close (fd);
	return (0);
}
