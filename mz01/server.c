/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:35:10 by abin-saa          #+#    #+#             */
/*   Updated: 2022/07/03 18:47:44 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <stdio.h>
#include "libft/libft.h"

void	func(int sig)
{
	static int	i;
	static char	c;

	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	if (sig == SIGUSR2)
		c = (c << 1) | 0;
	i++;
	if (i == 8)
	{
		i = 0;
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("server pid :", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, func);
	signal(SIGUSR2, func);
	while (1)
		pause();
}
