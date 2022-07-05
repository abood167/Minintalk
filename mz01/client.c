/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:01:31 by abin-saa          #+#    #+#             */
/*   Updated: 2022/07/04 18:17:11 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <stdio.h>
#include "libft/libft.h"

void	killuser(char *message, int pid)
{
	int		i;
	char	x;
	char	bit;
	int		shift;
	int		check;

	i = 0;
	while (message[i] != '\0')
	{
		x = message[i];
		shift = 7;
		while (shift >= 0)
		{
			bit = (x >> shift) & 1;
			if (bit == 1)
				check = kill(pid, SIGUSR1);
			else
				check = kill(pid, SIGUSR2);
			shift--;
			usleep(250);
		}
		i++;
	}
	if (check == -1)
		ft_putstr_fd("wrong pid", 1);
}

int	checker(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		write(1, "Error: Enter 3 arguments only", 30);
		return (0);
	}
	while (av[1][i])
	{
		if (ft_isalpha(av[1][i]) == 1)
		{
			write(1, "dont put letters with pid,(pid  عم   فرح  عضت  ال)", 61);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;

	if (!checker(ac, av))
		return (0);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "wrong pid", 10);
		return (0);
	}
	message = av[2];
	killuser(message, pid);
	return (0);
}
