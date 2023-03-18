/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:03:06 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/18 15:07:29 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void 	InterruptSignalHandler(int signalType);



int main(int argc, char **argv)
{
	struct sigaction handler;

	handler.sa_handler = InterruptSignalHandler;

	handler.sa_flags = 0;
	if (sigaction(SIGINT, &handler, 0) < 0)
		printf("sigaction() failed !");
	while (1)
		pause();
	exit(0);

	
	// printf("getpid = %d \n", getpid());
	// return (0);
}

void	InterruptSignalHandler(int signalType)
{
	printf("Interrupt Recieved. Exiting program.\n");
	exit(1);
}