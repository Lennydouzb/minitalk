/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:27:52 by ldesboui          #+#    #+#             */
/*   Updated: 2025/10/17 18:39:42 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_revtab(char *str)
{
	size_t	i;
	char	temp_c;

	i = 0;
	while (i < (ft_strlen(str) / 2))
	{
		temp_c = str[i];
		str[i] = str[ft_strlen(str) - i - 1];
		str[ft_strlen(str) - i - 1] = temp_c;
		++i;
	}
}

static int	ft_howpow(int n)
{
	int	i;

	i = 1;
	while ((n / 10) >= 1 || (n / 10) <= -1)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	long long	nb;
	char		*str;

	i = 0;
	nb = n;
	if (n < 0)
		nb *= -1;
	str = ft_calloc(ft_howpow(n) + 1 + (n < 0), sizeof(char));
	if (!str)
		return (NULL);
	while ((nb / 10) >= 1)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		++i;
	}
	str[i] = (nb % 10) + '0';
	if (n < 0)
		str[++i] = '-';
	str[i + 1] = '\0';
	ft_revtab(str);
	return (str);
}
