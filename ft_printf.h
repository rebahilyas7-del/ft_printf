/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irebah <irebah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:07:48 by irebah            #+#    #+#             */
/*   Updated: 2026/11/25 07:57:20 by irebah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define LOW_HEX "0123456789abcdef"
# define UPP_HEX "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_putlwhex(unsigned long n);
int		ft_putchar(int c);
int		ft_putuphex(unsigned int n);
int		ft_putptr(void *p);
int		ft_putunbr(unsigned int nb);
int		ft_putnbr(int n);
int		ft_putstr(char *s);

#endif