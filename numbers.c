/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 21:19:04 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/18 19:12:26 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	convert(t_arg *arg, unsigned long long nbr)
{
	if (arg->length_flag == hh)
		return ((char)nbr);
	if (arg->length_flag == h)
		return ((short)nbr);
	if (arg->length_flag == l)
		return ((long)nbr);
	if (arg->length_flag == ll)
		return (nbr);
	if (arg->length_flag == j)
		return ((size_t)nbr);
	if (arg->length_flag == h)
		return ((short)nbr);
	return (nbr);
}

unsigned long long	get_negative(t_arg *arg, int *negative)
{
	//unsigned long long	ul;
	long long			l;

	if (arg->type == 'd' || arg->type == 'i')
	{
		l = (long long)arg->target;
		if (l < 0)
		{
			*negative = -1;
			if (l < -9223372036854775807)
				return (9223372036854775808ULL);
			l *= -1;
		}
		return((unsigned long long)l);
	}
	return ((unsigned long long)arg->target);
}

int					get_base(t_arg *arg)
{
	if (arg->type == 'x' || arg->type == 'X' || arg->type == 'a' ||
		arg->type == 'A')
		return (16);
	return (10);
}

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

int					ft_printnbr(t_buff *buffer, t_arg *arg)
{
	char				out[MAX_INT_SIZE];
	int					i;
	int					j;
	unsigned long long	nbr;
	unsigned long long	base;
	int					negative;

	nbr = get_negative(arg, &negative);
	base = get_base(arg);
	ft_bzero(out, MAX_INT_SIZE);
	i = 0;
	j = 0;
	while (nbr != 0)
	{
		out[i++] = HEX[nbr % base];
		nbr /= base;
	}
	arg->len = i;
	while (j < arg->len)
		ft_swap(&(out[j++]), &(out[i--]));
	return(ft_putbuff(buffer, out, i));
}
