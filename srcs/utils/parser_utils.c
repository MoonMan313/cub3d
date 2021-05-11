/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:23:19 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 17:48:55 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

char	*ft_isdigit(const char *s)
{
	while ((*s > 47) && (*s < 58))
		++s;
	return ((char *)s);
}

char	*ft_isspase(const char *s)
{
	while (*s == ' ')
		++s;
	return ((char *)s);
}

char	*pass_for_atoi(const char *line)
{
	line = ft_isspase(line);
	line = ft_isdigit(line);
	line = ft_isspase(line);
	if (*line == ',')
		return ((char *)(line + 1));
	else
		error_param(1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	value;
	int	i;

	value = 0;
	i = 0;
	str = ft_isspase(str);
	while (*str > 47 && *str < 58)
	{
		value = value * 10 + (int)(*str - 48);
		++str;
		++i;
		if (i > 6)
			return (1000000);
		if (*str < 47 || *str > 58)
			return (value);
	}
	return (-1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;
	size_t			i;

	i = 0;
	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (p_s1[i] == '\0' && p_s2[i] == '\0')
			return (0);
		if (p_s1[i] != p_s2[i])
			return (p_s1[i] - p_s2[i]);
		++i;
	}
	return (0);
}
