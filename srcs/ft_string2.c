/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:49:19 by eshana            #+#    #+#             */
/*   Updated: 2021/02/10 20:01:55 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_error_msg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int		ft_validate_eof(char *eof)
{
	if (!eof)
		return (0);
	if (EMPT == OBST || EMPT == FULL || OBST == FULL)
		return (0);
	if (EMPT < 32 || EMPT > 126 || OBST < 32 || OBST > 126
			|| FULL < 32 || FULL > 126)
		return (0);
	return (1);
}

int		ft_validate_line(char *str, t_uint len, char *eof)
{
	t_uint	i;
	int		full[2];

	full[1] = 3;
	full[0] = 2;
	if (!str || !eof || len != ft_strlen(str) || (str[len] != '\n'))
		return (0);
	i = 0;
	while (i < len)
	{
		if (str[i] == OBST)
		{
			str[i] = 3;
			full[0] = 1;
		}
		else if (str[i] == EMPT)
		{
			str[i] = 1;
			full[1] = 1;
		}
		else
			return (0);
		i++;
	}
	return (full[1] < full[0] ? full[0] : full[1]);
}

int		ft_validate_map(char ***map, char *eof, t_uint len)
{
	t_uint	i;
	int		full;
	int		empty;
	int		val;

	full = 3;
	empty = 2;
	i = 0;
	while ((*map)[i])
	{
		if (!(val = ft_validate_line((*map)[i], len, eof)))
			return (0);
		if (val != 2)
			empty = 1;
		if (val != 3)
			full = 0;
		i++;
	}
	if (full)
		return (0);
	return (empty);
}
