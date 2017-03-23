/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:51:25 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/23 14:39:34 by nlowe            ###   ########.fr       */
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
	// t_buff	buffer;
	//
	// if (ac != 2)
	// 	return (0);
	// buffer.pos = 0;
	// ft_bzero(buffer.contents, BUFF_SIZE);
	// printf("chars to buff = %d\n", ft_putbuff(&buffer, av[1], ft_strlen(av[1]), 1));
	// printf("chars to stdout = %d\n", ft_flushbuff(&buffer, 1));
	// char c = 'c';
	// char *s = "string";
	// wchar_t *str = L"WSTRING";
	// wchar_t x = L'X';
//	int test = 0;
	//int *p = &test;

	// printf("---> return: %d\n", ft_printf("|%.1s %.1ls %5c %10lc this is a test|\n", s, str, c, x));
	// printf("---> return: %d\n", printf("|%.1s %.1ls %5c %10lc this is a test|\n", s, str, c, x));
	//
	// printf("---> return: %d\n", ft_printf("|%-#*X|\n", 10, 225));
	// printf("---> return: %d\n", printf("|%-#*X|\n", 10, 225));
	//
	// printf("---> return: %d\n", ft_printf("|%#lx|\n", s));
	// printf("---> return: %d\n", printf("|%p|\n", s));

#define VALUE 0

#define DECIMAL "|%u|\n"

	printf("\n---DECIMAL---\n");
	printf("u---> return: %ud\n", ft_printf(DECIMAL, VALUE));
	printf("s---> return: %ud\n", printf(DECIMAL, VALUE));

#define OCTAL "|%#.1o|\n"

	printf("\n---OCTAL---\n");
	printf("u---> return: %d\n", ft_printf(OCTAL, VALUE));
	printf("s---> return: %d\n", printf(OCTAL, VALUE));

#define HEXA "|%#.1x|\n"

	printf("\n---HEX---\n");
	printf("u---> return: %d\n", ft_printf(HEXA, VALUE));
	printf("s---> return: %d\n", printf(HEXA, VALUE));

	return (0);
}
