/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:32:55 by eshana            #+#    #+#             */
/*   Updated: 2021/02/10 19:36:21 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_next_line(int fd, t_uint size)
{
	ssize_t		ctl;
	char		*line;

	if (!(line = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ctl = read(fd, line, size + 1);
	if (ctl == (size + 1))
		return (line);
	free(line);
	return (NULL);
}

void	ft_clean_map(char ***map)
{
	t_uint i;

	i = 0;
	if (*map)
	{
		while ((*map)[i])
		{
			free((*map)[i]);
			i++;
		}
		free(*map);
	}
}

void	ft_put_res(char ***map, char *eof)
{
	t_uint i;
	t_uint j;

	i = 0;
	if (*map)
	{
		while ((*map)[i])
		{
			j = 0;
			while ((*map)[i][j] != '\n')
			{
				if ((*map)[i][j] == 1)
					(*map)[i][j] = EMPT;
				else if ((*map)[i][j] == 3)
					(*map)[i][j] = OBST;
				else if ((*map)[i][j] == 2)
					(*map)[i][j] = FULL;
				j++;
			}
			i++;
		}
	}
	ft_print_map(map);
}

void	ft_print_map(char ***map)
{
	t_uint i;

	i = 0;
	while ((*map)[i])
	{
		ft_putstr((*map)[i]);
		i++;
	}
	ft_clean_map(map);
}

void	ft_full_map(char ***map, char *eof)
{
	t_uint i;
	t_uint j;

	i = 0;
	while ((*map)[i])
	{
		j = 0;
		while ((*map)[i][j] != '\n')
			(*map)[i][j++] = EMPT;
		i++;
	}
	i = 0;
	while ((*map)[i] && (*map)[0][i] != '\n')
	{
		j = 0;
		while ((*map)[j] && (*map)[i][j] != '\n')
		{
			(*map)[i][j] = FULL;
			j++;
		}
		i++;
	}
	ft_print_map(map);
}
