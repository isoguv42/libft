/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:52:36 by igyuveni          #+#    #+#             */
/*   Updated: 2024/12/15 11:35:12 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Outputs pointer address as hexadecimal */
int	ft_putptr(unsigned long a, int sign)
{
	const char	*base;
	int			ret;

	base = "0123456789abcdef";
	ret = 0;
	if (a == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	if (sign == 1)
	{
		ft_putstr_fd("0x", 1);
		ret += 2;
	}
	if (a >= 16)
		ret += ft_putptr(a / 16, 0);
	ft_putchar_fd(base[a % 16], 1);
	ret++;
	return (ret);
}
