/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:12:57 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/01 18:12:57 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void handle_signal(int sig)
{
    static char c = 0;
    static int bit = 0;

    if (sig == SIGUSR1)
        c = (c << 1) | 1;
    else
        c = (c << 1) | 0;
    ++bit;
    if (bit == 8)
    {
        ft_printf("%c", c);
        c = 0;
        bit = 0;
    }
}

int main(void)
{
    pid_t   pid;

    pid = getpid();
    
    ft_printf("%d", pid);
    while (1)
    {
        signal(SIGUSR1, handle_signal);
        signal(SIGUSR2, handle_signal);
        pause();
    }
}