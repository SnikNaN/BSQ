/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:35:07 by eshana            #+#    #+#             */
/*   Updated: 2021/02/10 19:32:40 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void				ft_putstr(char *str)
{
	t_uint len;

	len = ft_strlen(str);
	write(1, str, len + 1);
}

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int		ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}
