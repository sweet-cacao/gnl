# gnl
Get_next_line is a function that returns a line read from a file descriptor.

The function is prototyped as follow :
int get_next_line(const int fd, char **line);

The return value can be 1, 0 or -1 depending on whether a line has been read,
when the reading has been completed, or if an error has happened respectively.

# Compilation
In your project #include "get_next_line.h"

Compile libft.a :
Go to folder libft,
make

Compile with get_next_line.c and libft.a 

