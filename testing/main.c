/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:46:42 by kneth             #+#    #+#             */
/*   Updated: 2017/04/05 18:52:26 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <locale.h>
#include <errno.h>

int		main()
{
	int 	i;
	int		j;
	int		adress;
	int		fd;
	int		n;
	char	*filename = "test.txt";

	i = 90;
	j = 120;
	adress = 0;
	setlocale(LC_ALL, "en_US.UTF-8");
	i = ft_printf("My printf   : %c\n", 'm');
	j = printf("Real printf : %c\n", 'm');
	printf("%d\n", i);
	printf("%d\n", j);
	i = ft_printf("My printf   : %C\n", L'猫');
	j = printf("Real printf : %C\n", L'猫');
	printf("%d\n", i);
	printf("%d\n", j);
	i = ft_printf("My printf   : %s\n", "Ce printf merite un 125 =D");
	j = printf("Real printf : %s\n", "Ce printf merite un 125 =D");
	printf("%d\n", i);
	printf("%d\n", j);
	i = ft_printf("My printf   : %S\n", L"我是一只猫。");
	j = printf("Real printf : %S\n", L"我是一只猫。");
	printf("%d\n", i);
	printf("%d\n", j);
	i = ft_printf("My printf   : %d\n", 42);
	j = printf("Real printf : %d\n", 42);
	printf("%d\n", i);
	printf("%d\n", j);
	i = ft_printf("My printf   : %i\n", 42);
	j = printf("Real printf : %i\n", 42);
	printf("%d\n", i);
	printf("%d\n", j);
	// i = ft_printf("My printf   : %D\n", 3000000000);
	// j = printf("Real printf : %D\n", 3000000000);
	// printf("%d\n", i);
	// printf("%d\n", j);
	i = ft_printf("My printf   : %o\n", 42);
	j = printf("Real printf : %o\n", 42);
	printf("%d\n", i);
	printf("%d\n", j);
	// i = ft_printf("My printf   : %O\n", 3000000000);
	// j = printf("Real printf : %O\n", 3000000000);
	// printf("%d\n", i);
	// printf("%d\n", j);
	i = ft_printf("My printf   : %u\n", 42);
	j = printf("Real printf : %u\n", 42);
	printf("%d\n", i);
	printf("%d\n", j);
	// i = ft_printf("My printf   : %U\n", 3000000000);
	// j = printf("Real printf : %U\n", 3000000000);
	// printf("%d\n", i);
	// printf("%d\n", j);
	i = ft_printf("My printf   : %p\n", &adress);
	j = printf("Real printf : %p\n", &adress);
	printf("%d\n", i);
	printf("%d\n", j);
	i = ft_printf("My printf   : %x\n", 42);
	j = printf("Real printf : %x\n", 42);
	printf("%d\n", i);
	printf("%d\n", j);
	i = ft_printf("My printf   : %X\n", 42);
	j = printf("Real printf : %X\n", 42);
	printf("%d\n", i);
	printf("%d\n", j);
	i = ft_printf("My printf   : %c %s %d %p\n", 'm', "salut", 42, &adress);
	j = printf("Real printf : %c %s %d %p\n", 'm', "salut", 42, &adress);
	printf("%d\n", i);
	printf("%d\n", j);
	printf("%s\n", "\n=====\nBONUS\n=====\n");
	i = ft_printf("My printf   : %b\n", 42);
	printf("%d\n", i);
	i = ft_printf("My printf   : %*s\n", 50, "Ce printf merite un 125 =D");
	printf("%d\n", i);
	i = ft_printf("My printf   : %.*s\n", 10, "Ce printf merite un 125 =D");
	printf("%d\n", i);

	i = ft_printf("We have now output|%ncharacters: ", &n);
	printf("%d\n", n);
	j = printf("We have now output|%ncharacters: ", &n);
	printf("%d\n", n);

	if ((fd = open(filename, O_RDWR)) < 0)
		printf("%s\n", strerror(errno));
	else
	{
		ft_printf("Successfully opened file, fd = %d\nNow writing to file...\n", fd);
		ft_dprintf(fd, "TEST OUTPUT TO FILE %d\n", 42);
		ft_dprintf(fd, "My printf   : %X\n", 42);
		ft_dprintf(fd, "END OF FILE\n");
		close(fd);
	}
	return (0);
}
