/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:50:52 by nlowe             #+#    #+#             */
/*   Updated: 2017/02/22 21:40:29 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		has_flag(t_arg *arg, char flag)
{
	if (ft_strchr(arg->flags, flag))
		return (1);
	return (0);
}

int		padding(t_buff *buffer, t_arg *arg, int fd)
{
	char		pad;
	long long	width;

	pad = ' ';
	width = arg->width;
	if (width == -1)
		return (0);
	if (arg->len > arg->width)
	{
		arg->len = arg->width;
		return (0);
	}
	// if (has_flag(arg, '-'))
	//
	// else if (has_flag(arg, '0'))
	//  	pad = '0';
	while (--width >= arg->len)
	{
		write(1, "Here\n", 5);
		ft_putbuff(buffer, &pad, 1, fd);
	}
	return (arg->width - arg->len);
}

int		print(t_buff *buffer, t_arg *arg, int fd)
{
	int		ret;

	ret = 0;
	arg->len = ft_strlen(arg->target);
	ret += padding(buffer, arg, fd);
	if (arg->type == 's')
	{
		ret += ft_putbuff(buffer, arg->target, arg->len, fd);
	}

	// else if (arg->type == 'S')
	// 	ft_putbuff(buffer, ft_toupper(arg->target), ft_strlen(arg->target), fd);
	return (ret);
}
