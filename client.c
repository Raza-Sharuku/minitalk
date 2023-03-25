/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:02:55 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/25 17:09:32 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include"./libs/ft_printf/ft_printf.h"
#include"./libs/libft/libft.h"

// void	push_signal(int bit, int pid)
// {
// 	if (bit == 0)
// 		kill(pid, SIGUSR1);
// 	else if (bit == 1)
// 		kill(pid, SIGUSR2);
// 	usleep(500);
// }

// void	ft_convert_signal(unsigned int argv, int pid)
// {
// 	char	bit[9];
// 	int		i;

// 	bit[8] = '\0';
// 	i = 7;
// 	while (argv >= 1 || i >= 0)
// 	{
// 		if (argv >= 1)
// 		{
// 			bit[i] = argv % 2;
// 			argv = argv / 2;
// 		}
// 		else
// 			bit[i] = 0;
// 		i--;
// 	}
// 	i = 0;
// 	while (i < 8)
// 	{
// 		push_signal(bit[i], pid);
// 		i++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int	i;
// 	int	pid;

// 	i = 0;
// 	if (argc != 3)
// 		return (0);
// 	pid = ft_atoi(argv[1]);
// 	while (argv[2][i])
// 	{
// 		ft_convert_signal((int)argv[2][i], pid);
// 		i++;
// 	}
// }



void	push_signal(int bit, int pid)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else if (bit == 1)
		kill(pid, SIGUSR2);
	usleep(500);
}

void	ft_convert_signal(unsigned int argv, int pid)
{
	char	bit[9];
	int		i;

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
		push_signal(bit[i], pid);
		i++;
	}
}

void	message_recieved(int sign)
{
	(void)sign;
	write(1, "Message Recieved!!\n", 20);
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;

	i = 0;
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, message_recieved);
	while (argv[2][i])
	{
		ft_convert_signal((int)argv[2][i], pid);
		i++;
	}
	while (1)
		pause();
	return (0);
}
