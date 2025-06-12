/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:56:04 by igyuveni          #+#    #+#             */
/*   Updated: 2024/12/05 21:37:51 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format_string(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	ft_format_special(char c)
{
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(c, 1);
		return (2);
	}
}

/** Handles format specifiers for printf */
int	ft_format(va_list *args, char c)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(*args, int), 1);
		return (1);
	}
	else if (c == 's')
		return (ft_format_string(args));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, unsigned long), 1));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), c));
	else
		return (ft_format_special(c));
}

/** Formatted output function */
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (-1);
			len += ft_format(&args, str[++i]);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
