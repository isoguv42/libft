/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:47:45 by igyuveni          #+#    #+#             */
/*   Updated: 2024/10/26 17:44:11 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Converts string to integer */
int	ft_atoi(const char *str)
{
	int	n;
	int	negative;

	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	negative = 0;
	if (*str == '-' || *str == '+')
	{
		if (*(str + 1) == '-' || *(str +1) == '+')
			return (0);
		if (*str == '-')
			negative = 1;
		str++;
	}
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	if (negative)
		n *= -1;
	return (n);
}
