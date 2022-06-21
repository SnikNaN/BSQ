/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max_ushort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:27:26 by gtelly            #+#    #+#             */
/*   Updated: 2021/02/10 13:19:50 by gtelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_ushort	ft_max_ushort(t_ushort a, t_ushort b)
{
	return (a > b ? a : b);
}

t_ushort	ft_min_ushort(t_ushort a, t_ushort b)
{
	return (a < b ? a : b);
}
