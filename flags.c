/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:50:52 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/03 13:30:11 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//# define FT_PRINTF_TYPES "sSpdDioOuUxXcCeEfFgGaAn"

int (*print)(t_arg *arg)[FT_PRINTF_TYPE_COUNT] = {ft_printstr, ft_printwstr,
	ft_printptr, ft_printnbr, ft_printdec, ft_printdec, ft_printdec,
	ft_printoct, ft_printoct, ft_printdec, ft_printdec, ft_printdec,
	ft_printchar, ft_printwchar, ft_printsci, ft_printsci, ft_printdec,
	ft_printdec, ft_printdec, ft_printdec, ft_printhex, ft_printhex,
	ft_printpos};

int		has_flag(t_arg *arg, char flag)
{
	if (ft_strchr(arg->flags, flag))
		return (1);
	return (0);
}

int		get_type(t_arg *arg)
{
	int		i;

	i = -1;
	while (++i < FT_PRINTF_TYPE_COUNT)
		if (FT_PRINTF_TYPES[i] == arg->type)
			return (i);
	return (-1);
}

int		padding(t_buff *buffer, t_arg *arg)
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
	if (has_flag(arg, '0'))
	 	pad = '0';
	while (--width >= arg->len)
		ft_putbuff(buffer, &pad, 1);
	return (arg->width - arg->len);
}

int		print(t_buff *buffer, t_arg *arg)
{
	(void)buffer;
	printf("type: %d\n", get_type(arg));
	return (0);
}

// int		process(t_buff *buffer, t_arg *arg)
// {
// 	int		ret;
//
// 	ret = 0;
// 	// if (has_flag(arg, '-'))
// 	// {
// 	// 	//ret = print();
// 	// 	padding(buffer, arg);
// 	// }
// 	// else
// 	// {
// 	// 	padding(buffer, arg);
// 	// 	//ret = print();
// 	// }
//
// 	return (ret);
// }
