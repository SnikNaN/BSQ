/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 00:28:35 by eshana            #+#    #+#             */
/*   Updated: 2021/02/10 19:19:15 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		*ft_list_to_str(t_list *list)
{
	char	*str;
	t_uint	size;
	t_uint	i;

	size = ft_list_size(list);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = list->c;
		list = list->next;
		i++;
	}
	str[i] = '\n';
	return (str);
}

void		ft_list_clear(t_list **begin_list)
{
	t_list	*tmp;

	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = tmp;
	}
	*begin_list = NULL;
}

t_uint		ft_list_size(t_list *begin_list)
{
	t_uint i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

void		ft_list_push_back(t_list **begin_list, char data)
{
	t_list	*list;

	if (*begin_list)
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

t_list		*ft_create_elem(char c)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->c = c;
		tmp->next = NULL;
	}
	return (tmp);
}
