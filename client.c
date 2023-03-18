/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:02:55 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/18 19:42:14 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_convert_signal(unsigned int argv, int pid)
{
	char bit[9];
	int i;

	bit[8] = '\0';
	i = 7;
	while (argv >= 1 || i >= 0)
	{
		if (argv >= 1)
		{
			bit[i] = argv % 2;
			argv = argv / 2;
		}
		else
			bit[i] = 0;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		if (bit[i] == 0)
			kill(pid, SIGUSR1);
		else if (bit[i] == 1)
			kill(pid, SIGUSR2);
		printf("%d ", bit[i]);
		i++;
		usleep(500);
	}
}

int	main (int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
		return (0);
	printf("pid str =  %s\n", argv[1]);
	pid = ft_atoi(argv[1]);
	printf("pid str =  %u\n", argv[2][1]);
	while(argv[2][i])
	{
		ft_convert_signal((int)argv[2][i], pid);
		i++;
	}
}