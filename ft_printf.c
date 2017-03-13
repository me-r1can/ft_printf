/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:02:15 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/03 13:18:53 by nlowe            ###   ########.fr       */
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

	if (!(ret = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	ft_strclr(ret->flags);
	ret->flag_count = 0;
	ret->length_flag = none;
	ret->width = -1;
	ret->len = 0;
	ret->precision = -1;
	ret->type = 0;
	ret->target = NULL;
	return (ret);
}

void	check_precision(const char* restrict format, t_arg *ret,
	va_list args, int *i)
{
	if (format[*i + 1] && format[*i + 1] == '*')
	{
		ret->precision = va_arg(args, long long);
		(*i)++;
	}
	else if (format[*i + 1] && ft_isdigit(format [*i + 1]))
	{
		(*i)++;
		ret->precision = atoi(&(format[*i]));
		while (ft_isdigit(format[*i]))
			(*i)++;
		(*i)--;
	}
	else
		ret->precision = 0;
}

t_arg	*new_arg(const char* restrict format, va_list args, int *i)
{
	t_arg	*ret;

	ret = create_arg();
	while (!(ft_strchr(FT_PRINTF_TYPES, format[*i])))
	{
		if (ret->width == -1 && ft_isdigit(format[*i]) && format[*i] != '0')
			ret->width = atoi(&format[*i]);
		else if (ret->width == -1 && format[*i] == '*')
			ret->width = va_arg(args, long long);
		else if (ft_strchr(FT_PRINTF_FLAGS, format[*i]) && !(ft_strchr(ret->flags, format[*i])))
			ret->flags[(ret->flag_count)++] = format[*i];
		else if (ft_strchr(FT_PRINTF_LENGTH, format[*i]))
			ret->length_flag = ret->length_flag + (int)format[*i];
		else if (format[*i] == '.')
			check_precision(format, ret, args, i);
		(*i)++;
	}
	if (format[*i] && ft_strchr(FT_PRINTF_TYPES, format[*i]))
		ret->type = format[*i];
	ret->target = va_arg(args, void *);
	if (ret->len > ret->width)
		ret->len = ret->width;
	return (ret);
}

int		ft_vdprintf(int fd, const char* restrict format, va_list ap)
{
	int			i;
	t_arg		*current;
	t_buff		buffer;

	i = 0;
	buffer.fd = fd;
	while (format[i])
	{
		current = create_arg();
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putbuff(&buffer, "%", 1);
			i++;
		}
		else if (format[i] == '%')
		{
			current = new_arg(format, ap, &i);
			test_arg(current);
			print(&buffer, current);
		}
		else
			ft_putbuff(&buffer, (void *)&(format[i]), 1);
		i++;
	}
	ft_flushbuff(&buffer);
	return (0);
}

int		ft_dprintf(int fd, const char* restrict format, ...)
{
	va_list		ap;

	if (fd < 0)
		return (0);
	va_start(ap, format);
	return(ft_vdprintf(fd, format, ap));
	va_end(ap);
}

int		ft_printf(const char* restrict format, ...)
{
	va_list		ap;

	va_start(ap, format);
	return(ft_vdprintf(1, format, ap));
	va_end(ap);
}
