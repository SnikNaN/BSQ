/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:58:48 by gtelly            #+#    #+#             */
/*   Updated: 2021/02/10 23:33:06 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define EMPT eof[0]
# define OBST eof[1]
# define FULL eof[2]

# define MAX_UINT 4294967295
# define USHRT_MAX 65535
# define UCHAR_MAX 255
# define MAX_UINT_LEN 10
# define MIN_RULES 4

typedef	unsigned int	t_uint;
typedef unsigned char	t_uchar;
typedef unsigned short	t_ushort;

typedef struct			s_list
{
	struct s_list	*next;
	char			c;
}						t_list;

char					*ft_list_to_str(t_list *list);
void					ft_list_clear(t_list **begin_list);
t_uint					ft_list_size(t_list *begin_list);
void					ft_list_push_back(t_list **begin_list, char data);
t_list					*ft_create_elem(char c);

void					ft_error_msg(char *str);

char					**ft_process_map(int fd, char *eof, int *map_full);
void					ft_clean_map(char ***map);
int						ft_get_lines(char ***map, int fd,
												t_uint size, t_uint height);
char					*ft_next_line(int fd, t_uint size);
char					*ft_first_line(int fd, t_uint *len);
int						ft_map_rules(int fd, char *eof, t_uint *height);
int						ft_define_eof(char *eof, char **nbr);
int						ft_validate_eof(char *eof);
int						ft_validate_line(char *str, t_uint len, char *eof);
int						ft_validate_map(char ***map, char *eof, t_uint len);
void					ft_print_map(char ***map);
void					ft_put_res(char ***map, char *eof);
void					ft_full_map(char ***map, char *eof);

void					ft_putchar(char c);
void					ft_putstr(char *str);
t_uint					ft_strlen(char *str);
char					*ft_strdup(char *src);

t_uint					ft_atoi(char *str);

t_uint					ft_max_square_uint(char ***map, t_uint len,
														t_uint height);
t_uint					ft_max_uint(t_uint a, t_uint b);
t_uint					ft_min_uint(t_uint a, t_uint b);

t_ushort				ft_max_square_ushort(char ***map, t_ushort len,
														t_ushort height);

t_ushort				ft_max_ushort(t_ushort a, t_ushort b);
t_ushort				ft_min_ushort(t_ushort a, t_ushort b);

t_uchar					ft_max_square_uchar(char ***map, t_uchar len,
														t_uchar height);
t_uchar					ft_max_uchar(t_uchar a, t_uchar b);
t_uchar					ft_min_uchar(t_uchar a, t_uchar b);

t_uint					ft_solve(char ***map, t_uint height, t_uint len);

int						ft_open(char *filename);
int						ft_close(int fd);

#endif
