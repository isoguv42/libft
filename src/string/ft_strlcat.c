/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:50:13 by igyuveni          #+#    #+#             */
/*   Updated: 2024/10/26 17:45:27 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Concatenates string with size limit */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	j = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[i] != '\0')
		i++;
	dest_len = i;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	while (src[j] && (dest_len + j) < (size - 1))
	{
		dest[dest_len + j] = src[j];
		j++;
	}
	dest[dest_len + j] = '\0';
	return (dest_len + src_len);
}
