/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:28:18 by ldesboui          #+#    #+#             */
/*   Updated: 2025/10/17 18:27:31 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		char_start;
	int			ok;
	const char	*ptr_start;

	char_start = 0;
	ok = -1;
	ptr_start = big;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (ft_strlen(ptr_start) != 0 && char_start < len)
	{
		if (ft_strlen(little) + char_start > len)
			return (0);
		ok = ft_strncmp(ptr_start, little, ft_strlen(little));
		if (ok == 0)
			return ((char *)ptr_start);
		char_start++;
		ptr_start = &big[char_start];
	}
	return (0);
}
