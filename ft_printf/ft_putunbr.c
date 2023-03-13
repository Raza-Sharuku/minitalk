/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:59:58 by sraza             #+#    #+#             */
/*   Updated: 2023/02/22 14:49:41 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_putunbr(unsigned int ln, t_nm len)
{
	if (ln == 0)
		len.len = ft_putchar('0', len);
	if (ln <= 9 && ln > 0)
		len.len = ft_putchar(ln + 48, len);
	else if (ln > 0)
	{
		len.len = ft_putunbr(ln / 10, len);
		len.len = ft_putchar(ln % 10 + 48, len);
	}
	return (len.len);
}
