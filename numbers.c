/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 21:19:04 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/16 21:53:04 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

unsigned long long	negative(t_arg *arg, int *negative)
{
	unsigned long long	ul;
	long long			l;

	if (arg->type == 'd' || arg->type == 'i')
	{
		nbr = (long long)arg->target;
		if (l < 0)
		{
			*negative = -1;
			if (nbr == −9223372036854775808)
				return (9223372036854775808);
			nbr *= -1;
		}
		return((unsigned long long)nbr);
	}
	return ((unsigned long long)arg->target);
}

int					ft_printnbr(t_buff *buffer, t_arg *arg)
{
	char				out[22];
	int					i;
	unsigned long long	nbr;


}
