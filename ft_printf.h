/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:13:12 by nlowe             #+#    #+#             */
/*   Updated: 2017/02/20 15:49:33 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define FT_PRINTF_FLAGS "#0-+ $L'"
# define FT_PRINTF_TYPES "sSpdDioOuUxXcCeEfFgGaAn"
# define FT_PRINTF_LENGTH "hljz"

typedef enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

typedef enum	e_length
{
	none = 0,
	h = 104,
	j = 106,
	l = 108,
	z = 122,
	hh = 208,
	ll = 216
}				t_length;

typedef struct	s_arg
{
	char		flags[10];
	int			flag_count;
	t_length	length_flag;
	long long	width;
	long long	precision;
	char		type;
	void		*target;
}				t_arg;

int		ft_printf(const char *format, ...);
void	test_arg(t_arg *arg);

#endif
