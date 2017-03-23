/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:17:52 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/23 16:32:19 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	create_arg(void)
{
	t_arg	ret;

	ft_strclr(ret.flags);
	ret.flag_count = 0;
	ret.length_flag = none;
	ret.width = -1;
	ret.len = 0;
	ret.precision = -1;
	ret.type = 0;
	ret.target = NULL;
	return (ret);
}

void	new_arg(const char *restrict format, va_list args, int *i, t_arg *ret)
{
	*i += 1;
	while (!(ft_strchr(FT_PRINTF_TYPES, format[*i])))
	{
		if (ft_strchr(FT_PRINTF_FLAGS, format[*i])
			&& !(ft_strchr(ret->flags, format[*i])))
			add_flag(ret, format[*i]);
		else if (ret->width == -1 && ft_isdigit(format[*i])
			&& format[*i] != '0')
			check_width(format, ret, i);
		else if (ret->width == -1 && format[*i] == '*')
			ret->width = va_arg(args, long long);
		else if (ft_strchr(FT_PRINTF_LENGTH, format[*i]))
			add_length_flag(ret, format[*i]);
		else if (format[*i] == '.')
			check_precision(format, ret, args, i);
		(*i)++;
	}
	if (format[*i] && ft_strchr(FT_PRINTF_TYPES, format[*i]))
		ret->type = format[*i];
	if (!(ret->type == '%'))
		ret->target = va_arg(args, void *);
	convert_caps(ret);
}
