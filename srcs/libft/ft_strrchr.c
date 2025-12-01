/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:55:36 by ldesboui          #+#    #+#             */
/*   Updated: 2025/10/19 19:04:52 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	while (size > 0)
	{
		if (s[size] == (unsigned char)c)
			return ((char *)&s[size]);
		--size;
	}
	if (s[size] == (unsigned char)c)
		return ((char *)&s[size]);
	return (0);
}
