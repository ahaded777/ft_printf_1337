/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:30:35 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/07 12:44:39 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_put_strf(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	ft_print_len_nbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int nb)
{
	int		len_num;
	char	*res;

	len_num = ft_print_len_nbr(nb);
	res = malloc(len_num + 1);
	if (!res)
		return (NULL);
	res[len_num] = '\0';
	if (nb == 0)
		res[0] = '0';
	while (nb)
	{
		res[--len_num] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}

int	ft_print_unsigned(va_list args)
{
	unsigned int	va;
	char			*str;
	int				print_count;

	va = va_arg(args, unsigned int);
	str = ft_uitoa(va);
	print_count = ft_put_strf(str);
	free(str);
	if (print_count == -1)
		return (-1);
	return (print_count);
}
