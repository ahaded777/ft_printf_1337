/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:36:35 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/06 12:17:55 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	int	va;

	va = va_arg(args, int);
	return (write(1, &va, 1));
}

int	ft_format(const char c, va_list args)
{
	int	print_count;

	print_count = 0;
	if (c == 'c')
		print_count += ft_print_char(args);
	else if (c == 's')
		print_count += ft_print_string(args);
	else if (c == 'p')
		print_count += ft_print_ptr(args);
	return (print_count);
}

int	ft_printf(const char *str, ...)
{
	int i;
	int print_count;
	va_list args;

	i = 0;
	print_count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_count += ft_format(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			print_count++;
		}
		i++;
	}
	va_end(args);
	return (print_count);
}

int main()
{

	char c[6] = "abcde";
	int len1, len2;

	len1 = ft_printf("print %s, %c, %p\n", c, 'a', c);
	len2 =    printf("prino %s, %c, %p\n", c, 'a', c);
	printf("\nlen my printf: %d\n", len1);
	printf("len original printf: %d\n", len2);
}
