/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:28:47 by igyuveni          #+#    #+#             */
/*   Updated: 2024/12/15 10:12:18 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Counts the number of words in a string separated by delimiter */
size_t	ft_wordcount(const char *s, char delimiter)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == delimiter)
			s++;
		if (*s && *s != delimiter)
		{
			count++;
			while (*s && *s != delimiter)
				s++;
		}
	}
	return (count);
}
