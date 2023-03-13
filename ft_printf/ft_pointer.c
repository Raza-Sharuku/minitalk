/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:28:06 by sraza             #+#    #+#             */
/*   Updated: 2023/02/22 14:47:36 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_pointer(uintptr_t num, char x, t_nm len)
{
	char	*hexa;

	if (x == 'x')
		hexa = "0123456789abcdef";
	if (num == 0)
		len.len = ft_putchar('0', len);
	if (num <= 15 && num > 0)
		len.len = ft_putchar(hexa[num], len);
	else if (num > 0)
	{
		len.len = ft_pointer(num / 16, x, len);
		len.len = ft_putchar(hexa[num % 16], len);
	}
	return (len.len);
}
