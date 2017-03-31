/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:17:52 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/31 17:32:22 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg		create_arg(void)
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
	ret.widestr = NULL;
	return (ret);
}

static int	parse(const char *restrict format, va_list args, int *i, t_arg *ret)
{
	if (ft_strchr(FT_PRINTF_FLAGS, format[*i]))
	{
		if(!(ft_strchr(ret->flags, format[*i])))
			add_flag(ret, format[*i]);
	}
	else if (ret->width == -1 && ft_isdigit(format[*i])
		&& format[*i] != '0')
		check_width(format, ret, i);
	else if (ret->width == -1 && format[*i] == '*')
		ret->width = va_arg(args, long long);
	else if (ft_strchr(FT_PRINTF_LENGTH, format[*i]))
		add_length_flag(ret, format[*i]);
	else if (format[*i] == '.')
		check_precision(format, ret, args, i);
	else
		return (0);
	return (1);
}
//
// char		last_alpha(const char *restrict format, int *i)
// {
// 	while (format[*i] && !(ft_isalpha(format[*i])))
// 		(*i)--;
// 	(*i)++;
// 	return (format[*i]);
// }

int			new_arg(const char *restrict format, va_list args, int start, t_arg *ret)
{
	int		i;

	i = start;
	if (!(format[i + 1]))
		return (0);
	i++;
	while (format[i] && !(ft_strchr(FT_PRINTF_TYPES, format[i])))
	{
		if (!(parse(format, args, &i, ret)))
			break ;
		i++;
	}
	// if (format[i] && ft_strchr(FT_PRINTF_TYPES, format[i]))
		ret->type = format[i];
	// else
	// 	ret->type = last_alpha(format, &i);
	convert_caps(ret);
	if (ret->type == 's' && ret->length_flag >= l)
		ret->widestr = va_arg(args, wchar_t *);
	else if (!(ret->type == '%'))
		ret->target = va_arg(args, void *);
	return (i - start);
}
