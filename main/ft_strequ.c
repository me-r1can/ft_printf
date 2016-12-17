/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:17:58 by nlowe             #+#    #+#             */
/*   Updated: 2016/12/17 15:29:17 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

int		main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	printf("%i\n", ft_strnequ(av[1], av[2], 4));
	return (0);
}
