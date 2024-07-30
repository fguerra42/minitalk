/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguerra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:31:50 by fguerra           #+#    #+#             */
/*   Updated: 2024/05/20 09:31:57 by fguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	s_zero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}

void	*ft_calloc(size_t count, size_t n)
{
	void	*arm;

	if (count && n && count > (UINT_MAX / n))
		return (NULL);
	arm = malloc(count * n);
	if (!arm)
		return (NULL);
	s_zero(arm, count * n);
	return (arm);
}
