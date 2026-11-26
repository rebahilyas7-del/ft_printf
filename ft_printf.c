/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irebah <irebah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:08:04 by irebah            #+#    #+#             */
/*   Updated: 2026/11/26 16:29:10 by irebah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(const char *format, va_list args)
{
	if (format[1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[1] == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (format[1] == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (format[1] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format[1] == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (format[1] == 'x')
		return (ft_putlwhex(va_arg(args, unsigned int)));
	else if (format[1] == 'X')
		return (ft_putuphex(va_arg(args, unsigned int)));
	else if (format[1] == '%')
		return (ft_putchar('%'));
	else if ((format[1] == '\0'))
		return (-1);
	return (0);
}

int	helper(const char *f, va_list args)
{
	int	sum;
	int	ret;

	ret = 0;
	sum = 0;
	while (*f != '\0')
	{
		if (*f == '%')
		{
			ret = ft_handle_format(f, args);
			if (ret < 0)
				return (-1);
			sum += ret;
			f++;
		}
		else
		{
			ret = ft_putchar(*f);
			if (ret < 0)
				return (-1);
			sum += ret;
		}
		f++;
	}
	return (sum);
}

int	ft_printf(const char *format, ...)
{
	int		sum;
	va_list	args;

	sum = 0;
	va_start(args, format);
	sum = helper(format, args);
	if (sum < 0)
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (sum);
}
