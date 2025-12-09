/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:12:57 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/09 16:00:49 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

char	*g_str;

static void	create_char(char *c)
{
	size_t	len;

	len = ft_strlen(g_str);
	if (*c == '\0')
	{
		ft_printf("%s\n", g_str);
		free(g_str);
		g_str = NULL;
	}
	else
	{
		g_str = ft_realloc(g_str, len, len + 2);
		if (!g_str)
		{
			ft_printf("Error reallocating memory\n");
			exit (1);
		}
		g_str[len] = *c;
		g_str[len + 1] = '\0';
	}
}

static void	handle_signal(int sig)
{
	static char	c = 0;
	static int	bit = 0;

	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1) | 0;
	++bit;
	if (bit == 8)
	{
		if (!g_str)
		{
			g_str = ft_calloc(sizeof(char), 1);
			if (!g_str)
			{
				ft_printf("Error allocating memory\n");
				exit (1);
			}
		}
		create_char(&c);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	g_str = NULL;
	ft_printf("%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();
	}
}
