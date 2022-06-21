/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_square_uchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:09:06 by gtelly            #+#    #+#             */
/*   Updated: 2021/02/10 13:14:51 by gtelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_map_fill_uchar(t_uchar ***t, char ***map, t_uchar row, t_uchar col)
{
	t_uchar		i;
	t_uchar		j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			(*t)[i][j] = (*map)[i][j];
			if ((*t)[i][j] == 3)
				(*t)[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_map_free_uchar(t_uchar ***t, t_uchar i)
{
	t_uchar		j;

	j = 0;
	if (i)
	{
		while (j < i)
		{
			free((*t)[j]);
			j++;
		}
	}
	free(*t);
}

int		ft_map_init_uchar(t_uchar ***t, char ***map, t_uchar row, t_uchar col)
{
	t_uchar		i;

	i = 0;
	if (!((*t) = malloc(sizeof(t_uchar *) * row)))
		return (0);
	while (i < row)
	{
		if (!((*t)[i] = malloc(sizeof(t_uchar) * col)))
		{
			ft_map_free_uchar(t, i + 1);
			return (0);
		}
		i++;
	}
	ft_map_fill_uchar(t, map, row, col);
	return (1);
}

void	ft_map_solve_uchar(t_uchar ***t, t_uchar *sol, t_uchar row, t_uchar col)
{
	t_uchar		side;
	t_uchar		i;
	t_uchar		j;

	side = 0;
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if ((*t)[i][j] > 0 && i > 0 && j > 0)
				(*t)[i][j] = ft_min_uchar((*t)[i - 1][j - 1],
				ft_min_uchar((*t)[i - 1][j], (*t)[i][j - 1])) + 1;
			side = ft_max_uchar((*t)[i][j], side);
			if (side > sol[0])
			{
				sol[0] = side;
				sol[1] = i + 1;
				sol[2] = j + 1;
			}
			j++;
		}
		i++;
	}
}

t_uchar	ft_max_square_uchar(char ***map, t_uchar row, t_uchar col)
{
	t_uchar		**t;
	t_uchar		sol[3];
	t_uchar		i;
	t_uchar		j;

	if (!(col && row) || !(ft_map_init_uchar(&t, map, row, col)))
		return (0);
	sol[0] = 0;
	ft_map_solve_uchar(&t, sol, row, col);
	ft_map_free_uchar(&t, row);
	if (sol[0] == 0)
		return (0);
	i = sol[1] - sol[0];
	while (i < sol[1])
	{
		j = sol[2] - sol[0];
		while (j < sol[2])
		{
			(*map)[i][j] = 2;
			j++;
		}
		i++;
	}
	return (sol[0]);
}
