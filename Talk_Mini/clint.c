/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:56:10 by ecayir            #+#    #+#             */
/*   Updated: 2022/04/17 13:59:07 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	send_to_server(int *s, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (s[i] == 0)
			kill(pid, SIGUSR1);
		else if (s[i] == 1)
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

void	sig_back(int signal, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)signal;
	(void)siginfo;
	ft_putstr("SINGAL SENT\n");
}

int	main(int ac, char **av)
{
	int					sid;
	struct sigaction	act;
	int					*arr;
	int					i;

	i = 0;
	sid = ft_atoi(av[1]);
	if (ac != 3)
		return (0);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sig_back;
	sigaction(SIGUSR2, &act, NULL);
	ft_putstr("SENDNG TO : ");
	ft_putnbr(sid);
	ft_putstr("\n");
	while (av[2][i])
	{
		arr = convert_binary((unsigned char)av[2][i]);
		send_to_server(arr, sid);
		i++;
	}
}
