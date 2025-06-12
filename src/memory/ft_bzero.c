/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:49:23 by igyuveni          #+#    #+#             */
/*   Updated: 2024/10/26 17:44:15 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Sets the first n bytes of memory area s to zero */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
