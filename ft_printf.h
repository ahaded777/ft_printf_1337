/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:21:39 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/06 16:32:39 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_print_string(va_list args);
int	ft_print_ptr(va_list args);
int	ft_print_char(va_list args);
int ft_printf_num(va_list args);

#endif
