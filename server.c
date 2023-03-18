/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:03:02 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/18 19:06:53 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

char ft_convert_demical(int num)
{
	int demical;
	int base;

	demical = 0;
	base = 1;
	while(num > 0)
	{
		demical = demical + (num % 10) * base;
		num = num / 10;
		base = base * 2;
	}
	return ((char)demical);
}

void	ft_handler(int signalType)
{
	static int num;
	static int counter;
	char c;

	if (signalType == SIGUSR1)
		num = (num * 10) + 0;
	if (signalType == SIGUSR2)
		num = (num * 10) + 1;
	counter++;
	if (counter >= 8)
	{
		c = ft_convert_demical(num);
		write(1, &c, 1);
		num = 0;
		counter = 0;
	}
}

int main()
{
	struct sigaction handler;
	
	handler.sa_handler = ft_handler;
	printf("PID = %d\n", getpid());

	sigemptyset(&handler.sa_mask);
	sigaddset(&handler.sa_mask, SIGUSR1);
	sigaddset(&handler.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &handler, 0);
	sigaction(SIGUSR2, &handler, 0);
	while (1)
		pause();
	exit(0);

}