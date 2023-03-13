/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:14:48 by sraza             #+#    #+#             */
/*   Updated: 2023/02/22 18:53:32 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_strptr(char *s, t_nm len)
{
	if (s == NULL)
		len.len = ft_putstr("(null)", len);
	else
		len.len = ft_putstr(s, len);
	return (len.len);
}
