/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:53:40 by eshana            #+#    #+#             */
/*   Updated: 2021/02/10 22:17:05 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_stdin(void)
{
	char	**res;
	char	eof[3];
	int		map_full;

	map_full = 1;
	if ((res = ft_process_map(0, eof, &map_full)))
		map_full == 2 ? ft_full_map(&res, eof) : ft_put_res(&res, eof);
	else
		(ft_error_msg("map error\n"));
}

int		main(int argc, char **argv)
{
	int		fd;
	int		count;
	char	**res;
	char	eof[3];
	int		map_full;

	map_full = 1;
	count = 1;
	if (argc == 1)
		ft_stdin();
	while (count < argc)
	{
		if ((fd = ft_open(argv[count])))
		{
			if ((res = ft_process_map(fd, eof, &map_full)))
				map_full == 2 ? ft_full_map(&res, eof) : ft_put_res(&res, eof);
			else
				(ft_error_msg("map error\n"));
		}
		if (fd)
			ft_close(fd);
		count++;
	}
	return (0);
}
