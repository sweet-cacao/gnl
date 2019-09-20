#inclide "get_next_line.c"

int	get_line(char **s, )
{
	int len;

	while (*s[fd][len] != '\n' && *s[fd] != '\0')
		s++;
	if (s[fd][nread] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = ft_strdub(tmp);
		ft_strdel(tmp);
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
}

int	get_next_line(int fd, char **line)
{
	char buff[BUFF_SIZE + 1];
	static char *s[255];
	int nbread;

	nbread = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	while ((nbread = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nread] = '\0';
		tmp = strjoin(s[fd], buff);

	}
}
