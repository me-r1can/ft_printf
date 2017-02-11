/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:02:15 by nlowe             #+#    #+#             */
/*   Updated: 2017/02/11 18:43:42 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_args(const char *format)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (format[++i])
		if (format[i] == '%')
			if (format[i + 1] != '%')
				count++;
	return (count);
}

t_arg	*create_arg(void)
{
	t_arg	*ret;

	ft_strclr(ret->flags);
	ret->flag_count = 0;
	ret->length_flag = none;
	width = -1;
	precision = -1;
	return (ret);
}

void	check_precision(const char restrict *format, va_list args, size_t *i)
{
	if (format[i + 1] && format[i + 1] == '*')
	{
		ret->precision = va_arg(args, long long);
		(*i)++;
	}
	else if (format[i + 1] && ft_isdigit(format [i + 1]))
	{
		ret->precision = ft_atoi(format[i + 1]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
	else
		ret->precision = 0;
}

void	new_arg(const char restrict *format, va_list args)
{
	t_arg	*ret;
	size_t	i;

	ret = create_arg();
	while (!(ft_strchr(FT_PRINTF_TYPES, format[i])))
	{
		if (ft_strchr(FT_PRINTF_FLAGS, format[i]))
			ret->flags[(ret->flag_count)++] = format[i];
		else if (ft_strchr(FT_PRINTF_LENGTH, format[i]))
			ret->length_flag = ret->length_flag + (int)format[i];
		else if (format[i] == '.')
			check_precision(format, args, &i);
		else if (ret->width == -1 && ft_isdigit(format[i]))
			ret->width = ft_atoi(format[i]);
		else if (ret->width == -1 && format[i] == '*')
			ret->width = va_arg(args, long long);
		i++;
	}
}

int		ft_printf(const char restrict *format, ...)
{
	va_list		args;
	int			i;
	int			count;

	count = count_args(format);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
			write(FD, '%', 1);
		else if (format[i] == '%')
			new_arg(format, args);
		i++;
	}
	va_end(args);
	return (0);
}
