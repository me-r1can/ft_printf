/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:50:52 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/13 13:24:00 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//# define FT_PRINTF_TYPES "sSpdDioOuUxXcCeEfFgGaAn"
//
// int (*print[FT_PRINTF_TYPE_COUNT])(t_arg *arg) = {ft_printstr, ft_printwstr,
// 	ft_printptr, ft_printdec, ft_printoct, ft_printchar, ft_printwchar,
// 	ft_printsci, ft_printhex, ft_printpos};

int		has_flag(t_arg *arg, char flag)
{
	if (ft_strchr(arg->flags, flag))
		return (1);
	return (0);
}

// int		get_type(t_arg *arg)
// {
// 	int		i;
//
// 	i = -1;
// 	while (++i < FT_PRINTF_TYPE_COUNT)
// 		if (FT_PRINTF_TYPES[i] == arg->type)
// 			return (i);
// 	return (-1);
// }

t_printfunc	get_type(t_arg *arg)
{
	if (arg->type == 's')
		return (ft_printstr);
	if (arg->type == 'S')
		return (ft_printwstr);
	if (arg->type == 'p')
		return (ft_printptr);
	if (arg->type == 'd' || arg->type == 'D' || arg->type == 'i' ||
		arg->type == 'u' || arg->type == 'U')
		return (ft_printdec);
	if (arg->type == 'o' || arg->type == 'O')
		return (ft_printoct);
	if (arg->type == 'c')
		return (ft_printchar);
	if (arg->type == 'C')
		return (ft_printwchar);
	if (arg->type == 'e' || arg->type == 'E' || arg->type == 'f' ||
		arg->type == 'F')
		return (ft_printsci);
	if (arg->type == 'x' || arg->type == 'X')
		return (ft_printhex);
	if (arg->type == 'n')
		return (ft_printpos);
	return (NULL);
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
