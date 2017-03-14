/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:21:23 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/14 12:37:51 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printstr(t_buff *buffer, t_arg *arg)
{
	char		*str;
	long long	ret;

	str = (char *)arg->target;
	ret = 0;
	arg->len = ft_strlen(str);
	if (arg->precision != -1 && arg->precision < arg->len)
		arg->len = arg->precision;
	if (has_flag(arg, '-'))
	{
		ret = ft_putbuff(buffer, str, arg->len);
		ret += padding(buffer, arg);
	}
	else
	{
		ret += padding(buffer, arg);
		ret = ft_putbuff(buffer, str, arg->len);
	}
	return (ret);
}

int		ft_printwstr(t_buff *buffer, t_arg *arg)
{
	char		*str;
	long long	ret;

	str = (char *)arg->target;
	arg->len = ft_strlen(str);
	if (has_flag(arg, '-'))
	{
		ret = ft_putbuff(buffer, str, arg->len);
		padding(buffer, arg);
	}
	else
	{
		padding(buffer, arg);
		ret = ft_putbuff(buffer, str, arg->len);
	}
	return (ret);
}
