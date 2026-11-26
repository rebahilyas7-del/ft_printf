/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putXpx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irebah <irebah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:44:03 by irebah            #+#    #+#             */
/*   Updated: 2026/11/25 08:08:13 by irebah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlwhex(unsigned long n)
{
	int		i;
	int		ret;

	i = 0;
	if (n >= 16)
	{
		ret = ft_putlwhex(n / 16);
		if (ret < 0)
			return (-1);
		i += ret;
	}
	ret = ft_putchar(LOW_HEX[n % 16]);
	if (ret < 0)
		return (-1);
	i += ret;
	return (i);
}

int	ft_putuphex(unsigned int n)
{
	int	i;
	int	ret;

	i = 0;
	if (n >= 16)
	{
		ret = ft_putuphex(n / 16);
		if (ret < 0)
			return (-1);
		i += ret;
	}
	ret = ft_putchar(UPP_HEX[n % 16]);
	if (ret < 0)
		return (-1);
	i += ret;
	return (i);
}

int	ft_putptr(void *p)
{
	int		i;
	int		ret;

	i = 0;
	if (!p)
	{
		p = "(nil)";
		while (*(char *)p)
		{
			ret = write(1, p++, 1);
			if (ret < 0)
				return (-1);
			i += ret;
		}
		return (i);
	}
	i = write(1, "0x", 2);
	if (i < 0)
		return (-1);
	ret = ft_putlwhex((unsigned long)p);
	if (ret < 0)
		return (-1);
	i += ret;
	return (i);
}
