/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:31:19 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/18 19:31:41 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static ssize_t	ft_per_printer(const char format, uintptr_t ap, t_nm len)
{
	if (format == 'c')
		len.len = ft_putchar(ap, len);
	if (format == 'd' || format == 'i')
		len.len = ft_putnbr(ap, len);
	if (format == 'u')
		len.len = ft_putunbr(ap, len);
	if (format == 'X' || format == 'x')
		len.len = ft_hexa(ap, format, len);
	if (format == 'p')
	{
		len.len = ft_putstr("0x", len);
		len.len = ft_pointer(ap, 'x', len);
	}
	else if (!(ft_strchr(format)))
		len.len = ft_putchar(format, len);
	return (len.len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_nm	len;

	len.len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != 0)
		{
			if (*(format + 1) == 's')
				len.len = ft_strptr(va_arg(ap, char *), len);
			if (*(format + 1) != 's' && !ft_strchr(*(format + 1)))
				len.len = ft_putchar('%', len);
			else if (ft_strchr(*(format + 1)))
				len.len = ft_per_printer(*(format + 1), \
				va_arg(ap, uintptr_t), len);
			format++;
		}
		else
			len.len = ft_putchar(*format, len);
		format++;
	}
	va_end(ap);
	return (len.len);
}
