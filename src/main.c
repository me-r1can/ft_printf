/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:51:25 by nlowe             #+#    #+#             */
/*   Updated: 2017/04/03 17:04:15 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>


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
/*
static void test_simple_mix(void)
{
	// test->debug = 1;
	ft_printf("s: %s, p: %p, d:%d\n\n", "a string", &test_simple_mix, 42);
	printf("s: %s, p: %p, d:%d\n\n", "a string", &test_simple_mix, 42);
}
*/
static void test_super_mix(void)
{
	// test->debug = 1;
	ft_printf("%s%p%d%d%p%s%p%p%s\n\n",
		"a", &free, 1, 2, &malloc, "b", &free, &malloc, "c")  ;
	printf("%s%p%d%d%p%s%p%p%s\n\n",
		"a", &free, 1, 2, &malloc, "b", &free, &malloc, "c")  ;
}

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

setlocale(LC_ALL, "en_US.utf8");

#define VALUE 42

#define DECIMAL "{%*3d}", 5, 0

	printf("\n---DECIMAL---\n");
	printf("u---> return: %d\n", ft_printf(DECIMAL));
	printf("s---> return: %d\n", printf(DECIMAL));
/*
#define OCTAL "|%+O|\n"

	printf("\n---OCTAL---\n");
	printf("u---> return: %d\n", ft_printf(OCTAL, -42));
//	printf("s---> return: %d\n", printf(OCTAL, 0));

#define HEXA "|%#llX|\n"

	printf("\n---HEX---\n");
	printf("u---> return: %d\n", ft_printf(HEXA, VALUE));
	printf("s---> return: %d\n", printf(HEXA, VALUE));

#define PERCENT "|.%.%.%.%.%.%.%.%.|\n"

	printf("\n---PERCENT---\n");
	printf("u---> return: %d\n", ft_printf(PERCENT));
	printf("s---> return: %d\n", printf(PERCENT));

#define SIZE_T "|%zu|\n"

	printf("\n---SIZE_T---\n");
	printf("u---> return: %d\n", ft_printf(SIZE_T, 4294967295));
	printf("s---> return: %d\n", printf(SIZE_T, 4294967295));

#define PTR "|%p|\n"

	int i;
	printf("\n---POINTER---\n");
	printf("u---> return: %d\n", ft_printf(PTR, &i));
	printf("s---> return: %d\n", printf(PTR, &i));

#define WCHAR "{%30ls}"
#define WCHAR_VALUE NULL

	// wchar_t *wstr = L"我是一只猫。";
	// wchar_t *wstr = L"test...";
	ft_printf("\n---WIDE STRING---\n");
	//printf("s---> return: %d\n", printf(WCHAR, WCHAR_VALUE));
	printf("u---> return: %d\n", ft_printf(WCHAR, NULL));
	printf("strerror: %s\n", strerror(errno));

#define SSS "|%4.15s|\n", "TEST"

	printf("\n---STRING---\n");
	printf("u---> return: %d\n", ft_printf(SSS));
	printf("s---> return: %d\n", printf(SSS));

#define BINARY "|%.8#b|\n"

	int	b = 2;
	ft_printf("\n---BINARY---\n");
	printf("u---> return: %d\n", ft_printf(BINARY, b));

// #define MIXED "%s %C %d %p %x %% %ls", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"
// 	ft_printf("\n---MIXED---\n");
// 	printf("u---> return: %d\n", ft_printf(MIXED));
// 	printf("s---> return: %d\n", printf(MIXED));

	// test_simple_mix();
	// test_super_mix();

	printf("u---> return: %d\n", ft_printf("%10z", &free));
	printf("s---> return: %d\n", printf("%10z", &free));
	ft_printf("--%10z\n", &free);
	printf("%10zq\n", &free);
	*/
	return (0);
}
