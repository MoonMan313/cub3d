/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:56:48 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 16:18:11 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

char	*line_join(char *dst, char *src, int len)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = ft_strlen(dst) + len + 1;
	buf = (char *)malloc(j * sizeof(char));
	if (!buf)
		return (NULL);
	while (dst[i] != '\0')
	{
		buf[i] = dst[i];
		i++;
	}
	free(dst);
	j = 0;
	while (src[j] != '\0' && len != j)
	{
		buf[i + j + 1] = '\0';
		buf[i + j] = src[j];
		j++;
	}
	return (buf);
}

int	ft_strn(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		++i;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
