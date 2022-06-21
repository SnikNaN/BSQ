/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:22:07 by eshana            #+#    #+#             */
/*   Updated: 2021/02/10 23:02:43 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_define_eof(char *eof, char **nbr)
{
	t_uint i;
	t_uint len;

	len = ft_strlen(*nbr);
	if (len < MIN_RULES)
		return (0);
	i = 0;
	while (i < (MIN_RULES - 1))
	{
		eof[2 - i] = (*nbr)[len - 1 - i];
		(*nbr)[len - 1 - i] = '\0';
		i++;
	}
	if (ft_validate_eof(eof))
		return (1);
	return (0);
}

int		ft_map_rules(int fd, char *eof, t_uint *height)
{
	char			c;
	ssize_t			ctl;
	t_list			*list;
	char			*nbr;

	nbr = NULL;
	list = NULL;
	while ((ctl = read(fd, &c, 1)) > 0)
	{
		if (c != '\n')
			ft_list_push_back(&list, c);
		else
			break ;
	}
	if (ctl != -1 && c == '\n' && (nbr = ft_list_to_str(list))
			&& ft_define_eof(eof, &nbr) && (*height = ft_atoi(nbr)))
	{
		ft_list_clear(&list);
		free(nbr);
		return (1);
	}
	ft_list_clear(&list);
	free(nbr);
	return (0);
}

char	*ft_first_line(int fd, t_uint *len)
{
	ssize_t	ctl;
	t_list	*list;
	char	*line;
	char	c;

	list = NULL;
	line = NULL;
	*len = 0;
	while ((ctl = read(fd, &c, 1)) > 0)
	{
		ft_list_push_back(&list, c);
		if (c == '\n')
			break ;
		(*len)++;
	}
	if (ctl != -1 && c == '\n' && (line = ft_list_to_str(list)))
	{
		ft_list_clear(&list);
		return (line);
	}
	ft_list_clear(&list);
	if (line)
		free(line);
	return (NULL);
}

int		ft_get_lines(char ***map, int fd, t_uint size, t_uint height)
{
	t_uint	i;
	char	c;
	ssize_t ctl;

	i = 1;
	ctl = 0;
	while (i < height)
	{
		if (!((*map)[i] = ft_next_line(fd, size)))
			break ;
		i++;
	}
	if (i == height)
		if ((fd == 0) || ((ctl = read(fd, &c, 1)) == 0))
		{
			(*map)[i] = NULL;
			return (1);
		}
	(*map)[i] = NULL;
	return (0);
}

char	**ft_process_map(int fd, char *eof, int *map_full)
{
	char	**map;
	t_uint	height;
	t_uint	len;
	t_uint	i;

	i = 1;
	len = 0;
	height = 0;
	*map_full = 1;
	if (!ft_map_rules(fd, eof, &height) || !height ||
			!(map = (char **)malloc(sizeof(char *) * (height + 1))))
		return (NULL);
	if (!(map[0] = ft_first_line(fd, &len)))
	{
		free(map);
		return (NULL);
	}
	if (ft_get_lines(&map, fd, len, height))
		if (((*map_full = ft_validate_map(&map, eof, len)) == 2) ||
				(*map_full == 1 && ft_solve(&map, height, len)))
			return (map);
	ft_clean_map(&map);
	return (NULL);
}
