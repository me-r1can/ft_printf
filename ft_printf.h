/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:13:12 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/14 11:59:21 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 10000
# define FT_PRINTF_FLAGS "#0-+ $L'"
# define FT_PRINTF_TYPES "sSpdDioOuUxXcCeEfFgGaAn"
# define FT_PRINTF_TYPE_COUNT 23
# define FT_PRINTF_LENGTH "hljz"

typedef enum		e_bool
{
	false = 0,
	true = 1
}					t_bool;

typedef enum		e_length
{
	none = 0,
	h = 104,
	j = 106,
	l = 108,
	z = 122,
	hh = 208,
	ll = 216
}					t_length;

typedef struct		s_arg
{
	char			flags[10];
	int				flag_count;
	t_length		length_flag;
	long long		width;
	long long		len;
	long long		precision;
	char			type;
	void			*target;
}					t_arg;

typedef struct		s_buff
{
	unsigned char	contents[BUFF_SIZE];
	size_t			pos;
	int				fd;
}					t_buff;

int					ft_printf(const char *format, ...);
void				test_arg(t_arg *arg);
int					ft_putbuff(t_buff *buffer, void *contents, size_t len);
void				ft_flushbuff(t_buff *buffer);
int					print(t_buff *buffer, t_arg *arg);
int					padding(t_buff *buffer, t_arg *arg);
int					has_flag(t_arg *arg, char flag);


int					ft_printstr(t_buff *buffer, t_arg *arg);


#endif
