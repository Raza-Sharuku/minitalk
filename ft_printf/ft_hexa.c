/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:43:37 by razasharuku       #+#    #+#             */
/*   Updated: 2023/02/22 14:48:11 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_hexa(unsigned int num, char x, t_nm len)
{
	char	*hexa;

	if (x == 'X')
		hexa = "0123456789ABCDEF";
	if (x == 'x')
		hexa = "0123456789abcdef";
	if (num == 0)
		len.len = ft_putchar('0', len);
	if (num <= 15 && num > 0)
		len.len = ft_putchar(hexa[num], len);
	else if (num > 0)
	{
		len.len = ft_hexa(num / 16, x, len);
		len.len = ft_putchar(hexa[num % 16], len);
	}
	return (len.len);
}
