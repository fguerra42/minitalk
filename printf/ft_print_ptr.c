/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguerra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 00:58:48 by fguerra           #+#    #+#             */
/*   Updated: 2024/05/25 00:58:53 by fguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_adr(unsigned long int n)
{
	if (n >= 16)
	{
		ft_print_adr(n / 16);
		ft_print_adr(n % 16);
	}
	else
	{
		if (n < 10)
			ft_print_c(n + '0');
		else if (n >= 10)
			ft_print_c((n - 10) + 'a');
	}
}

int	ft_print_p(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_print_s(PTRNULL);
		return (count);
	}
	count += ft_print_s("0x");
	ft_print_adr(n);
	count += ft_ptr_len(n);
	return (count);
}

int	ft_print_ptr(unsigned long int n, t_flags flags)
{
	int	count;

	count = 0;
	if (n == 0)
		flags.width -= ft_strlen(PTRNULL) - 1;
	else
		flags.width -= 2;
	if (flags.left == 1)
		count += ft_print_p(n);
	count += ft_pad_width(flags.width, ft_ptr_len(n), 0);
	if (flags.left == 0)
		count += ft_print_p(n);
	return (count);
}
