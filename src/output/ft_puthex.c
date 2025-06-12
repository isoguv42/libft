/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:48:29 by igyuveni          #+#    #+#             */
/*   Updated: 2024/12/15 11:31:44 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Outputs unsigned integer as hexadecimal */
int	ft_puthex(unsigned int a, char c)
{
	const char	*base;
	int			ret;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	ret = 0;
	if (a >= 16)
		ret += ft_puthex(a / 16, c);
	ft_putchar_fd(base[a % 16], 1);
	ret++;
	return (ret);
}
