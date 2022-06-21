/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:01:44 by eshana            #+#    #+#             */
/*   Updated: 2021/02/10 20:59:28 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_open(char *filename)
{
	int fd;

	if ((fd = open(filename, O_DIRECTORY)) != -1)
	{
		ft_error_msg("map error\n");
		return (0);
	}
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_error_msg("map error\n");
		return (0);
	}
	return (fd);
}

int		ft_close(int fd)
{
	int ctl;

	if ((ctl = close(fd)) == -1)
	{
		ft_error_msg("map error\n");
		return (0);
	}
	return (1);
}
