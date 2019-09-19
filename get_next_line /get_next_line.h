/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:22:44 by gstarvin          #+#    #+#             */
/*   Updated: 2019/09/18 15:29:19 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H
# include "libft/libft.h"
# include <fcntl.h>
# include "sys/types.h"
# include "sys/uio.h"
# define BUFF_SIZE 32
int		get_next_line(const int fd, char **line);
#endif
