/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:10:57 by gtelly            #+#    #+#             */
/*   Updated: 2021/02/10 10:29:04 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_uint	ft_atoi(char *str)
{
	t_uint	num;
	t_uint	i;

	num = 0;
	i = 0;
	if (str[i] == '0')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i == (MAX_UINT_LEN - 1) && (num >= (MAX_UINT / 10)
						&& (str[i + 1] != '\0')) && str[i + 1] > '5')
			return (0);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' || i > MAX_UINT_LEN)
		return (0);
	return (num);
}
