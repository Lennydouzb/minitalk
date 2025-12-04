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

char ***strs;

static void printstrings()
{
    int i;

    i = 0;
    while (strs[0][i])
    {
        ft_printf("%s", strs[0][i]);
        free(strs[0][i]);
        ++i;
    }
    free(strs[0]);
    free(strs);
}
static void freeall(char ***strs)
{
    int i;

    i = 0;
    if (strs)
    {
        while (strs[0][i])
        {
            free(strs[0][i]);
            ++i;
        }
        free(strs[0]);
        free(strs);
    }
}

static void create_char(char *c, int *pos, int *bit)
{
    if (c == NULL)
        printstrings();
    strs[0][*pos] = ft_calloc(sizeof(char *), 2);
    if (strs[0][*pos] == NULL)
    {
        ft_printf("Error allocating memory\n");
        freeall(strs);
        exit(1);
    }
    strs[0][*pos][0] = ft_calloc(sizeof(char), 2);
    strs[0][*pos][0] = *c;
    *c = 0;
    *bit = 0;
    ++(*pos);
}
static void handle_signal(int sig)
{
    static char c = 0;
    static int bit = 0;
    static int pos = 0;

    if (sig == SIGUSR1)
        c = (c << 1) | 1;
    else
        c = (c << 1) | 0;
    ++bit;
    if (bit == 8)
    {
        create_char(&c, &pos, &bit);   
    }
}

int main(void)
{
    pid_t   pid;

    pid = getpid();
    
    strs = ft_calloc(sizeof(char **), 2);
    if (!strs)
    {
        ft_printf("Error allocating memory\n"); 
        return (1);
    }
    ft_printf("%d", pid);
    while (1)
    {
        signal(SIGUSR1, handle_signal);
        signal(SIGUSR2, handle_signal);
        pause();
    }
}