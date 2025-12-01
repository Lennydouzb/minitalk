/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pututils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:02:28 by ldesboui          #+#    #+#             */
/*   Updated: 2025/10/30 13:24:16 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *k)
{
	int	i;

	i = write(1, &c, 1);
	if (i != -1)
		++(*k);
}

void	ft_putstr(char *str, int *k)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr("(null)", k);
	else
	{
		while (str[i])
		{
			ft_putchar(str[i], k);
			++i;
		}
	}
}

static void	proceed_number(long nb, char	*base, int *k)
{
	char	c;
	size_t	size_base;

	size_base = ft_strlen(base);
	c = base[nb % size_base];
	if (nb / size_base >= 1)
		proceed_number(nb / size_base, base, k);
	ft_putchar(c, k);
}

void	ft_putnbr_base(long nbr, char *base, int *k)
{
	if (nbr < 0)
	{
		ft_putstr("-", k);
		nbr *= -1;
	}
	proceed_number(nbr, base, k);
}
