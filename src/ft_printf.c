/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:02:15 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/20 18:44:22 by nlowe            ###   ########.fr       */
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

void	check_precision(const char * restrict format, t_arg *ret,
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
		ret->precision = atoi(&(format[*i]));
		while (ft_isdigit(format[*i]))
			(*i)++;
		(*i)--;
	}
	else
		ret->precision = 0;
}

void	check_width(const char* restrict format, t_arg *ret, int *i)
{
	ret->width = atoi(&format[*i]);
	while (ft_isdigit(format[*i]))
		(*i)++;
	(*i)--;
}

void	add_flag(t_arg *ret, char f)
{
	ret->flags[(ret->flag_count)++] = f;
}

void	add_width_flag(t_arg *ret, char f)
{
	if (!(ret->length_flag + f > 216))
		ret->length_flag = ret->length_flag + (int)f;
}

void	convert_caps(t_arg *ret)
{
	if (ret->type != 'X' && ret->type != 'O' &&
		ret->type >= 'A' && ret->type <= 'Z')
	{
		add_width_flag(ret, 'l');
		ret->type = ft_tolower(ret->type);
	}
}

t_arg	*new_arg(const char* restrict format, va_list args, int *i)
{
	t_arg	*ret;

	ret = create_arg();
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
			add_width_flag(ret, format[*i]);
		else if (format[*i] == '.')
			check_precision(format, ret, args, i);
		(*i)++;
	}
	if (format[*i] && ft_strchr(FT_PRINTF_TYPES, format[*i]))
		ret->type = format[*i];
	ret->target = va_arg(args, void *);
	convert_caps(ret);
	return (ret);
}

int		ft_vdprintf(int fd, const char * restrict format, va_list ap)
{
	int			i;
	t_arg		*current;
	t_buff		buffer;
	int			ret;

	i = 0;
	ret = 0;
	buffer.fd = fd;
	ft_bzero(buffer.contents, BUFF_SIZE);
	while (format[i])
	{
		current = create_arg();
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ret += ft_putbuff(&buffer, "%", 1);
			i++;
		}
		else if (format[i] == '%')
		{
			current = new_arg(format, ap, &i);
			//test_arg(current);
			ret += print(&buffer, current, ret);
		}
		else
			ret += ft_putbuff(&buffer, (void *)&(format[i]), 1);
		i++;
	}
	ft_flushbuff(&buffer);
	return (ret);
}

int		ft_dprintf(int fd, const char * restrict format, ...)
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
