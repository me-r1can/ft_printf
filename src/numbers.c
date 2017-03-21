/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 21:19:04 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/21 16:00:57 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_base(t_arg *arg)
{
	if (arg->type == 'X' || arg->type == 'x' || arg->type == 'A'
		|| arg->type == 'a')
		return (16);
	if (arg->type == 'O' || arg->type == 'o')
		return (8);
	return (10);
}

int		ft_nbrlen(unsigned long long nbr, int base)
{
	int		len;

	len = 0;
	if (nbr == 0 && base == 10)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int		ft_setnbr(t_buff *buffer, t_arg *arg, int len,
	unsigned long long nbr)
{
	char				out[MAX_INT_SIZE];
	int					i;

	ft_memset(out, '0', MAX_INT_SIZE);
	i = len - 1;
	while (nbr != 0 && i >= 0)
	{
		if (arg->type == 'X' || arg->type == 'O')
			out[i--] = HEX[nbr % arg->base];
		else
			out[i--] = SMALL_HEX[nbr % arg->base];
		nbr /= arg->base;
	}
	return (ft_putbuff(buffer, out, len));
}

int		ft_printsign(t_buff *buffer, t_arg *arg)
{
	if (arg->negative)
		return (ft_putbuff(buffer, "-", 1));
	if (has_flag(arg, ' '))
		return (ft_putbuff(buffer, " ", 1));
	if (has_flag(arg, '+'))
		return (ft_putbuff(buffer, "+", 1));
	if ((arg->type == 'x' || arg->type == 'X'
		|| arg->type == 'b') && has_flag(arg, '#'))
		return ((ft_putbuff(buffer, "0", 1) +
			ft_putbuff(buffer, &(arg->type), 1)));
		if ((arg->type == 'o' || arg->type == 'O') && has_flag(arg, '#'))
		return (ft_putbuff(buffer, "0", 1));
	return (0);
}

int		ft_printnbr(t_buff *buffer, t_arg *arg)
{
	int					ret;
	int					len;
	unsigned long long	nbr;

	ret = 0;
	nbr = get_negative(arg);
	arg->base = get_base(arg);
	len = ft_nbrlen(nbr, arg->base);
	arg->len = len;
	if (arg->precision != -1 && arg->precision > arg->len)
		arg->len = arg->precision;
	arg->len += prefix_count(arg);
	if (!(has_flag(arg, '-')))
		ret += padding(buffer, arg);
	ret += ft_printsign(buffer, arg);
	ret += ft_setnbr(buffer, arg, len, nbr);
	if (has_flag(arg, '-'))
		ret += padding(buffer, arg);
	return (ret);
}
