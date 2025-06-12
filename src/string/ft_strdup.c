/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:47:11 by igyuveni          #+#    #+#             */
/*   Updated: 2024/10/29 21:07:26 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Creates a duplicate copy of a string using malloc */
char	*ft_strdup(const char *src)
{
	size_t	length;
	size_t	i;
	char	*copy;

	if (!src)
		return (NULL);
	length = ft_strlen(src);
	copy = (char *)malloc((length + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < length)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
