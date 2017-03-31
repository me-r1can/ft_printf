/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:15:50 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/31 17:26:17 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_precision(const char *restrict format, t_arg *ret,
	va_list args, int *i)
{
	if (format[*i + 1] && format[*i + 1] == '*')
	{
		ret->precision = va_arg(args, long long);
		(*i)++;
	}
	else if (format[*i + 1] && ft_isdigit(format[*i + 1]))
	{
		(*i)++;
		ret->precision = ft_atoi(&(format[*i]));
		while (ft_isdigit(format[*i]))
			(*i)++;
		(*i)--;
	}
	else
		ret->precision = 0;
}

void	check_width(const char *restrict format, t_arg *ret, int *i)
{
	ret->width = ft_atoi(&format[*i]);
	while (ft_isdigit(format[*i]))
		(*i)++;
	(*i)--;
}

void	add_flag(t_arg *ret, char f)
{
	ret->flags[(ret->flag_count)++] = f;
}

void	add_length_flag(t_arg *ret, char f)
{
	if (!(ret->length_flag + f > 216))
		ret->length_flag = ret->length_flag + (int)f;
}

void	convert_caps(t_arg *ret)
{
	if (!(ft_strchr(FT_PRINTF_FLAGS, ret->type)))
		ret->length_flag = 0;
	else if (ret->type != 'X')
	{
		ret->length_flag = l;
		ret->type = ft_tolower(ret->type);
	}
}
