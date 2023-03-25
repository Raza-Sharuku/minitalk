/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:03:02 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/25 17:11:12 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libs/ft_printf/ft_printf.h"
#include "./libs/libft/libft.h"

// char	ft_convert_demical(int num)
// {
// 	int	demical;
// 	int	base;

// 	demical = 0;
// 	base = 1;
// 	while (num > 0)
// 	{
// 		demical = demical + (num % 10) * base;
// 		num = num / 10;
// 		base = base * 2;
// 	}
// 	return ((char)demical);
// }

// void	ft_handler(int signalType)
// {
// 	static int	num;
// 	static int	counter;
// 	char		c;

// 	if (signalType == SIGUSR1)
// 		num = (num * 10) + 0;
// 	if (signalType == SIGUSR2)
// 		num = (num * 10) + 1;
// 	counter++;
// 	if (counter >= 8)
// 	{
// 		c = ft_convert_demical(num);
// 		write(1, &c, 1);
// 		num = 0;
// 		counter = 0;
// 	}
// }

// int	main(void)
// {
// 	struct sigaction	handler;

// 	handler.sa_handler = ft_handler;
// 	ft_printf("PID = %d\n", getpid());
// 	sigemptyset(&handler.sa_mask);
// 	sigaddset(&handler.sa_mask, SIGUSR1);
// 	sigaddset(&handler.sa_mask, SIGUSR2);
// 	sigaction(SIGUSR1, &handler, 0);
// 	sigaction(SIGUSR2, &handler, 0);
// 	while (1)
// 		pause();
// 	exit(0);
// }

char	ft_convert_demical(int num, int client_pid)
{
	int	demical;
	int	base;

	demical = 0;
	base = 1;
	while (num > 0)
	{
		demical = demical + (num % 10) * base;
		num = num / 10;
		base = base * 2;
	}
	kill(client_pid, SIGUSR1);
	return ((char)demical);
}

void	ft_handler(int signalType, siginfo_t *info, void *context)
{
	static int		num;
	static pid_t	client_pid;
	static int		counter;
	char			c;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (signalType == SIGUSR1)
		num = (num * 10) + 0;
	if (signalType == SIGUSR2)
		num = (num * 10) + 1;
	counter++;
	if (counter >= 8)
	{
		c = ft_convert_demical(num, client_pid);
		write(1, &c, 1);
		num = 0;
		counter = 0;
	}
}

int	main(void)
{
	struct sigaction	handler;

	handler.sa_sigaction = ft_handler;
	ft_printf("PID = %d\n", getpid());
	sigemptyset(&handler.sa_mask);
	sigaddset(&handler.sa_mask, SIGUSR1);
	sigaddset(&handler.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &handler, 0);
	sigaction(SIGUSR2, &handler, 0);
	while (1)
		pause();
	exit(0);
}
