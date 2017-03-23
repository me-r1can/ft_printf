/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 21:19:04 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/23 17:14:41 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_base(t_arg *arg)
{
	if (is_hex(arg->type))
		return (16);
	if (is_oct(arg->type))
		return (8);
	return (10);
}

int		ft_nbrlen(unsigned long long nbr, int base)
{
	int		len;

	len = 0;
	if (nbr == 0)
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
	if (len <= 0)
		return (0);
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

int		ft_printsign(t_buff *buffer, t_arg *arg, unsigned long long nbr)
{
	if (arg->negative)
		return (ft_putbuff(buffer, "-", 1));
	if (arg->type == 'u' || arg->type == 'U')
		return (0);
	if (has_flag(arg, '+'))
		return (ft_putbuff(buffer, "+", 1));
	if (has_flag(arg, ' '))
		return (ft_putbuff(buffer, " ", 1));
	if (is_oct(arg->type) && has_flag(arg, '#'))
		return (ft_putbuff(buffer, "0", 1));
	if (nbr == 0 && arg->type != 'p')
		return (0);
	if ((is_hex(arg->type) || arg->type == 'b') && has_flag(arg, '#'))
		return ((ft_putbuff(buffer, "0", 1) +
			ft_putbuff(buffer, &(arg->type), 1)));
	return (0);
}

void	precision(t_arg *arg, int *digits, unsigned long long nbr)
{
	if (arg->precision != -1 && arg->precision > *digits)
	{
		*digits = arg->precision;
		if (is_oct(arg->type) && has_flag(arg, '#'))
			*digits -= 1;
	}
	if (nbr == 0 && arg->precision == 0)
		*digits = 0;
	arg->len = *digits;
}

int		ft_printnbr(t_buff *buffer, t_arg *arg)
{
	int					ret;
	int					digits;
	unsigned long long	nbr;

	ret = 0;
	nbr = get_negative(arg);
	arg->base = get_base(arg);
	digits = ft_nbrlen(nbr, arg->base);
	precision(arg, &digits, nbr);
	arg->len += prefix_count(arg);
	if (has_flag(arg, '0'))
		ret += ft_printsign(buffer, arg, nbr);
	if (!(has_flag(arg, '-')))
		ret += padding(buffer, arg);
	if (!(has_flag(arg, '0')))
		ret += ft_printsign(buffer, arg, nbr);
	ret += ft_setnbr(buffer, arg, digits, nbr);
	if (has_flag(arg, '-'))
		ret += padding(buffer, arg);
	return (ret);
}
