/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:17:52 by nlowe             #+#    #+#             */
/*   Updated: 2017/04/03 17:14:23 by nlowe            ###   ########.fr       */
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
	else if (format[*i] == '*' || (ft_isdigit(format[*i]) && format[*i] != '0'))
		check_width(format, ret, args, i);
	else if (ft_strchr(FT_PRINTF_LENGTH, format[*i]))
		add_length_flag(ret, format[*i]);
	else if (format[*i] == '.')
		check_precision(format, ret, args, i);
	else
		return (0);
	return (1);
}

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
	if (!(format[i]))
		i--;
	ret->type = format[i];
	convert_caps(ret);
	if (ret->type == 's' && ret->length_flag >= l)
		ret->widestr = va_arg(args, wchar_t *);
	else if (ft_strchr(FT_PRINTF_TYPES, ret->type) &&
		!(ret->type == '%'))
		ret->target = va_arg(args, void *);
	return (i - start);
}
