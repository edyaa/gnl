/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblaze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:05:41 by kblaze            #+#    #+#             */
/*   Updated: 2021/01/20 15:05:50 by kblaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ret_line(char *str)
{
	int			i;
	char		*tmp;

	if (!str)
		return (NULL);
	if ((i = ft_strchr(str, '\n')) == -1)
		tmp = ft_substr(str, 0, ft_strlen(str));
	else
		tmp = ft_substr(str, 0, i);
	return (tmp);
}

char		*ret_memor(char *memor)
{
	char		*keep;
	size_t		lenstr;
	int			i;

	if ((i = ft_strchr(memor, '\n')) == -1)
	{
		free(memor);
		return (NULL);
	}
	lenstr = ft_strlen(memor);
	keep = ft_substr(memor, i + 1, lenstr - i);
	free(memor);
	return (keep);
}

int			get_next_line(int fd, char **line)
{
	char			*buff;
	static	char	*memor;
	int				rd;

	if ((fd < 0 || !line || BUFFER_SIZE < 1)
			|| !(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	rd = 1;
	while ((ft_strchr(memor, '\n') == -1) && rd)
	{
		if ((rd = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[rd] = '\0';
		if (!(memor = ft_strjoin(memor, buff)))
			return (-1);
	}
	free(buff);
	if (!(*line = ret_line(memor)))
		return (-1);
	if (!(memor = ret_memor(memor)) || !rd)
		return (0);
	return (1);
}
