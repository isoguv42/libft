/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:55:18 by igyuveni          #+#    #+#             */
/*   Updated: 2024/12/15 11:38:27 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Outputs unsigned integer to stdout */
int	ft_putunsigned(unsigned int a)
{
	int	ret;

	ret = 0;
	if (a >= 10)
		ret += ft_putunsigned(a / 10);
	ft_putchar_fd('0' + (a % 10), 1);
	ret++;
	return (ret);
}
