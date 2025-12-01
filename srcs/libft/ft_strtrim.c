/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:40:48 by ldesboui          #+#    #+#             */
/*   Updated: 2025/10/19 17:28:47 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static size_t	ft_get_end(char const *s1, char const *set)
{
	size_t	end;

	end = 0;
	while (ft_in_set(s1[end], set))
		++end;
	return (end);
}

static size_t	ft_get_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (ft_in_set(s1[start], set))
		++start;
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*str;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = ft_get_start(s1, set);
	len = ft_strlen(s1);
	end = ft_get_end(s1, set);
	if (len == start)
		len = 0;
	while (ft_in_set(s1[len - 1], set))
		--len;
	end = len;
	if (len != 0)
		len = len - start;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	len = 0;
	while (start < end)
		str[len++] = s1[start++];
	return (str);
}
