/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:13:12 by nlowe             #+#    #+#             */
/*   Updated: 2017/02/09 16:07:42 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define PRINTF_FLAGS "#0-+ *$L'."

typedef enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

typedef struct	s_arg
{
	t_bool		pos;
	t_bool		left;
	t_bool		force_sign;
	t_bool		space;
	t_bool		pound;
	t_bool		zero;
	long long	width;
	long long	precision;
}				t_arg;

int		ft_printf(const char *format, ...);

#endif
