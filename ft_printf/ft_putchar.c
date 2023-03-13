/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:26:23 by razasharuku       #+#    #+#             */
/*   Updated: 2023/02/19 17:02:47 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_putchar(char c, t_nm len)
{
	write(1, &c, 1);
	len.len = len.len + 1;
	return (len.len);
}
