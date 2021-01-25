/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblaze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:10:21 by kblaze            #+#    #+#             */
/*   Updated: 2021/01/20 15:10:31 by kblaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int			get_next_line(int fd, char **line);
int			ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, const char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
