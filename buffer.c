/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:05:37 by nlowe             #+#    #+#             */
/*   Updated: 2017/03/14 12:32:41 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putbuff(t_buff *buffer, void *contents, size_t len)
{
	size_t			i;
	unsigned char	*c;
	int				ret;

	c = (unsigned char *)contents;
	i = 0;
	ret = 0;
	while (i < len)
	{
		if ((buffer->pos + i + 1) >= (BUFF_SIZE))
			ft_flushbuff(buffer);
		buffer->contents[buffer->pos] = c[i];
		i++;
		(buffer->pos)++;
	}
	printf("Buffer pos: %zu\n", buffer->pos);
	return (i);
}

void	ft_flushbuff(t_buff *buffer)
{
	int		ret;

	ret = write(buffer->fd, buffer->contents, buffer->pos);
	buffer->pos = 0;
	ft_bzero(buffer->contents, BUFF_SIZE);
}
