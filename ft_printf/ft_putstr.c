/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:26:17 by razasharuku       #+#    #+#             */
/*   Updated: 2023/02/22 14:48:56 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_putstr(char *s, t_nm len)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		len.len = ft_putchar(s[i], len);
		i++;
	}
	return (len.len);
}
