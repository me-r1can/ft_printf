/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:59:36 by nlowe             #+#    #+#             */
/*   Updated: 2017/02/20 13:33:36 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int		result;
	int		sign;
	char	*str;

	str = (char *)s;
	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' && (ft_isdigit(*(str + 1))))
		str++;
	if (*str == '-' && (ft_isdigit(*(str + 1))))
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (sign * result);
}
