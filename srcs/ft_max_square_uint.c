/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_square_uint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:09:06 by gtelly            #+#    #+#             */
/*   Updated: 2021/02/10 20:46:26 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_map_fill_uint(t_uint ***t, char ***map, t_uint row, t_uint col)
{
	t_uint		i;
	t_uint		j;

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

void	ft_map_free_uint(t_uint ***t, t_uint i)
{
	t_uint		j;

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

int		ft_map_init_uint(t_uint ***t, char ***map, t_uint row, t_uint col)
{
	t_uint		i;

	i = 0;
	if (!((*t) = malloc(sizeof(t_uint *) * row)))
		return (0);
	while (i < row)
	{
		if (!((*t)[i] = malloc(sizeof(t_uint) * col)))
		{
			ft_map_free_uint(t, i + 1);
			return (0);
		}
		i++;
	}
	ft_map_fill_uint(t, map, row, col);
	return (1);
}

void	ft_map_solve_uint(t_uint ***t, t_uint *sol, t_uint row, t_uint col)
{
	t_uint		side;
	t_uint		i;
	t_uint		j;

	side = 0;
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if ((*t)[i][j] > 0 && i > 0 && j > 0)
				(*t)[i][j] = ft_min_uint((*t)[i - 1][j - 1],
				ft_min_uint((*t)[i - 1][j], (*t)[i][j - 1])) + 1;
			side = ft_max_uint((*t)[i][j], side);
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

t_uint	ft_max_square_uint(char ***map, t_uint row, t_uint col)
{
	t_uint		**t;
	t_uint		sol[3];
	t_uint		i;
	t_uint		j;

	if (!(col && row) || !(ft_map_init_uint(&t, map, row, col)))
		return (0);
	sol[0] = 0;
	ft_map_solve_uint(&t, sol, row, col);
	ft_map_free_uint(&t, row);
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
