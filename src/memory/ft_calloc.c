/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:08:54 by igyuveni          #+#    #+#             */
/*   Updated: 2024/10/24 22:21:30 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Allocates and zeros memory for count objects of size bytes */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && size && (count > SIZE_MAX / size))
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
