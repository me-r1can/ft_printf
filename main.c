/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:51:25 by nlowe             #+#    #+#             */
/*   Updated: 2017/02/10 16:56:23 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
/*
void	print_args(int ac, ...)
{
	va_list		args;
	int			i;

	va_start(args, ac);
	i = 0;
	while (i < ac)
	{
		ft_putstr(va_arg(args, char *));
		ft_putchar('\n');
		i++;
	}
	va_end(args);
}
*/
int		main(void)
{
//	print_args(3, "dogs", "cats", "monkeys");
	// printf("%S\n", "dogs");
	int		num = 15;

	printf("%e\n", num);
	//ft_printf("%s%%%ddogs");
	return (0);
}
