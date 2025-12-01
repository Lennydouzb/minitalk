/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:26:52 by ldesboui          #+#    #+#             */
/*   Updated: 2025/10/16 17:22:54 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	number;

	number = 0;
	if (!dest && !src)
		return (NULL);
	while (number < n)
	{
		((unsigned char *)dest)[number] = ((unsigned char *) src)[number];
		++number;
	}
	return (dest);
}
