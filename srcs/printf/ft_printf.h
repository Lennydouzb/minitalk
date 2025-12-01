/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:03:40 by ldesboui          #+#    #+#             */
/*   Updated: 2025/10/22 17:40:25 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);

void	ft_putchar(char c, int *k);

void	ft_putnbr_base(long nbr, char *base, int *k);

void	ft_putstr(char *str, int *k);

int		ft_printf(const char *s, ...) __attribute__((format(printf, 1, 2)));

#endif
