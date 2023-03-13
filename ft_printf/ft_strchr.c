/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:23:03 by razasharuku       #+#    #+#             */
/*   Updated: 2023/02/22 19:07:59 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

char	*ft_strchr(int c)
{
	char		cc;
	const char	*s;

	s = "cdiuxXp";
	cc = (char)(c);
	while (*s != '\0')
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (cc == '\0' && *s == cc)
		return ((char *)s);
	return (NULL);
}
