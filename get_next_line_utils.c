/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblaze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:06:02 by kblaze            #+#    #+#             */
/*   Updated: 2021/01/20 15:06:04 by kblaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return ((void*)0);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return ((void*)0);
	len = ft_strlen(s);
	while (i < len && start <= len)
	{
		string[i] = s[start];
		i++;
		start++;
	}
	string[i] = '\0';
	return (string);
}

int			ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

char		*ft_strjoin(char *s1, const char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*str;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = -1;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (lens1 + lens2) + 1)))
		return (NULL);
	while (s1 && s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		str[i + lens1] = s2[i];
	str[lens1 + i] = '\0';
	free(s1);
	return (str);
}
