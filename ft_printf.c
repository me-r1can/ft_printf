/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:02:15 by nlowe             #+#    #+#             */
/*   Updated: 2017/02/10 16:42:21 by nlowe            ###   ########.fr       */
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

int		is_flag(const char c)
{
	if (ft_strchr(PRINTF_FLAGS, c))
		return (1);
	return (0);
}



int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			count;

	count = count_args(format);
	va_start(args, format);
	while (i < count)
	{

	}
	va_end(args);
	return (0);
}
