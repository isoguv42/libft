/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:23:15 by igyuveni          #+#    #+#             */
/*   Updated: 2024/12/15 09:45:32 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Counts the number of digits in an integer (including sign) */
int	ft_digitcount(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}
