/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max_uchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:27:26 by gtelly            #+#    #+#             */
/*   Updated: 2021/02/10 13:19:50 by gtelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_uchar	ft_max_uchar(t_uchar a, t_uchar b)
{
	return (a > b ? a : b);
}

t_uchar	ft_min_uchar(t_uchar a, t_uchar b)
{
	return (a < b ? a : b);
}
