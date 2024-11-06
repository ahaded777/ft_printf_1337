/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:19:39 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/06 15:35:42 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_put_char(char c)
{
	return (write(1, &c, 1));
}

static int	ft_put_hex(unsigned long long  va)
{
	int		print_count;
	char	*str_hex;

	print_count = 0;
	str_hex = "0123456789abcdef";
	if (va >= 16)
		print_count += ft_put_hex(va / 16);
	print_count += ft_put_char(str_hex[va % 16]);
	return (print_count);
}

int	ft_print_ptr(va_list args)
{
	int					print_count;
	unsigned long long	va;

	print_count = 0;
	va = va_arg(args, unsigned long long);
	if (!va)
		return (write(1, "(nil)", 5));
	print_count += write(1, "0x", 2);
	if (va == 0)
		print_count += write(1, "0", 1);
	else
		print_count += ft_put_hex(va);
	return (print_count);
}