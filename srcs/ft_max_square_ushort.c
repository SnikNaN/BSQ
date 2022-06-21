/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_square_ushort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:09:06 by gtelly            #+#    #+#             */
/*   Updated: 2021/02/10 20:29:08 by gtelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		ft_map_fill_ushort(t_ushort ***t, char ***map, t_ushort row,
t_ushort col)
{
	t_ushort		i;
	t_ushort		j;

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

void		ft_map_free_ushort(t_ushort ***t, t_ushort i)
{
	t_ushort		j;

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

int			ft_map_init_ushort(t_ushort ***t, char ***map, t_ushort row,
t_ushort col)
{
	t_ushort		i;

	i = 0;
	if (!((*t) = malloc(sizeof(t_ushort *) * row)))
		return (0);
	while (i < row)
	{
		if (!((*t)[i] = malloc(sizeof(t_ushort) * col)))
		{
			ft_map_free_ushort(t, i + 1);
			return (0);
		}
		i++;
	}
	ft_map_fill_ushort(t, map, row, col);
	return (1);
}

void		ft_map_solve_ushort(t_ushort ***t, t_ushort *sol, t_ushort row,
		t_ushort col)
{
	t_ushort		side;
	t_ushort		i;
	t_ushort		j;

	side = 0;
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if ((*t)[i][j] > 0 && i > 0 && j > 0)
				(*t)[i][j] = ft_min_ushort((*t)[i - 1][j - 1],
				ft_min_ushort((*t)[i - 1][j], (*t)[i][j - 1])) + 1;
			side = ft_max_ushort((*t)[i][j], side);
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

t_ushort	ft_max_square_ushort(char ***map, t_ushort row, t_ushort col)
{
	t_ushort		**t;
	t_ushort		sol[3];
	t_ushort		i;
	t_ushort		j;

	if (!(col && row) || !(ft_map_init_ushort(&t, map, row, col)))
		return (0);
	sol[0] = 0;
	ft_map_solve_ushort(&t, sol, row, col);
	ft_map_free_ushort(&t, row);
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
