/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:42:01 by ldesboui          #+#    #+#             */
/*   Updated: 2025/10/16 17:29:14 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	number;

	number = 0;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		while (number < n)
		{
			((unsigned char *)dest)[number] = ((unsigned char *)src)[number];
			++number;
		}
	}
	else
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			--n;
		}
	}
	return (dest);
}
