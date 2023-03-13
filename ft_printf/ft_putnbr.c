/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:41:50 by razasharuku       #+#    #+#             */
/*   Updated: 2023/02/22 14:49:23 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_putnbr(int n, t_nm len)
{
	unsigned int	ln;

	if (n < 0)
	{
		len.len = ft_putchar('-', len);
		ln = -n;
	}
	else
		ln = n;
	len.len = ft_putunbr(ln, len);
	return (len.len);
}
