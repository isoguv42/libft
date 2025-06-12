/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:35:22 by igyuveni          #+#    #+#             */
/*   Updated: 2024/12/15 10:18:55 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Frees an array of strings up to specified count */
void	ft_free_array(char **array, size_t count)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (i < count && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/** Frees a null-terminated array of strings */
void	ft_free_array_null(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
