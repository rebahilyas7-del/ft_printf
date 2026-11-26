/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irebah <irebah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:08:16 by irebah            #+#    #+#             */
/*   Updated: 2026/11/22 11:38:42 by irebah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	ret;

	i = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		ret = write(1, s, 1);
		if (ret < 0)
			return (-1);
		i += ret;
		s++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		i;
	int		ret;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		i += ft_putchar('-');
		if (i < 0)
			return (-1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ret = ft_putnbr(nb / 10);
		if (ret < 0)
			return (-1);
		i += ret;
	}
	ret = ft_putchar((nb % 10) + '0');
	if (ret < 0)
		return (-1);
	i += ret;
	return (i);
}

int	ft_putunbr(unsigned int nb)
{
	int	i;
	int	ret;

	i = 0;
	if (nb >= 10)
	{
		ret = ft_putunbr(nb / 10);
		if (ret < 0)
			return (-1);
		i += ret;
	}
	ret = ft_putchar((nb % 10) + '0');
	if (ret < 0)
		return (-1);
	i += ret;
	return (i);
}
