/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:50:52 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/18 18:48:14 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		has_flag(t_arg *arg, char flag)
{
	if (ft_strchr(arg->flags, flag))
		return (1);
	return (0);
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
		return (0);
	if (has_flag(arg, '0'))
	 	pad = '0';
	while (--width >= arg->len)
		ft_putbuff(buffer, &pad, 1);
	return (arg->width - arg->len);
}

int		print(t_buff *buffer, t_arg *arg)
{
	if (arg->type == 's')
		return (ft_printstr(buffer, arg));
	// if (arg->type == 'S')
	// 	return (ft_printwstr(buffer, arg));
	// if (arg->type == 'p')
	// 	return (ft_printptr(buffer, arg));
	if (arg->type == 'd' || arg->type == 'D' || arg->type == 'i' ||
		arg->type == 'u' || arg->type == 'U')
		return (ft_printnbr(buffer, arg));
	// if (arg->type == 'o' || arg->type == 'O')
	// 	return (ft_printoct(buffer, arg));
	if (arg->type == 'c')
		return (ft_printchar(buffer, arg));
	// if (arg->type == 'C')
	// 	return (ft_printwchar(buffer, arg));
	// if (arg->type == 'e' || arg->type == 'E' || arg->type == 'f' ||
	// 	arg->type == 'F')
	// 	return (ft_printsci(buffer, arg));
	// if (arg->type == 'x' || arg->type == 'X')
	// 	return (ft_printhex(buffer, arg));
	// if (arg->type == 'n')
	// 	return (ft_printpos(buffer, arg));
	return (0);
}
