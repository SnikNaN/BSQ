/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:53:43 by eshana            #+#    #+#             */
/*   Updated: 2021/02/10 23:17:14 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_uint		ft_solve(char ***map, t_uint height, t_uint len)
{
	t_uint max;

	max = ft_max_uint(height, len);
	if (max < UCHAR_MAX)
		return (ft_max_square_uchar(map, (t_uchar)height, (t_uchar)len));
	else if (max < USHRT_MAX)
		return (ft_max_square_ushort(map, (t_ushort)height, (t_ushort)len));
	else
		return (ft_max_square_uint(map, height, len));
}
