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

char *str;

static void create_char(char *c)
{
    size_t len;

    len = ft_strlen(str);
    if (*c == '\0')
        {
            ft_printf("%s\n", str);
            free(str);
            str = ft_calloc(sizeof(char), 1);
            if (!str)
            {
                ft_printf("Error allocating memory\n");
                exit (1);
            }
        }
    else
    {
        str = ft_realloc(str, len, len + 2);
        if (!str)
        {
            ft_printf("Error reallocating memory\n");
            exit (1);
        }
        str[len] = *c;
        str[len + 1] = '\0';
    }
}

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
        create_char(&c);
        c = 0;
        bit = 0;
    }
}

int main(void)
{
    pid_t   pid;

    pid = getpid();
    str = ft_calloc(sizeof(char), 1);
    if (!str)
    {
        ft_printf("Error allocating memory\n"); 
        exit (1);
    }
    ft_printf("%d\n", pid);
    while (1)
    {
        signal(SIGUSR1, handle_signal);
        signal(SIGUSR2, handle_signal);
        pause();
    }
}