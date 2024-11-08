/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:21:39 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/06 22:42:39 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_string(va_list args);
int	ft_print_ptr(va_list args);
int	ft_print_char(va_list args);
int	ft_print_num(va_list args);
int	ft_print_hex(char c, va_list args);
int	ft_print_unsigned(va_list args);
int	ft_put_str(char *str);

#endif
