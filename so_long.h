/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:10:47 by minkim            #+#    #+#             */
/*   Updated: 2022/06/24 00:09:10 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

static const char * const positions[] = {
	"./images/coin1.xpm",
	"./images/coin2.xpm",
	"./images/coin3.xpm",
	"./images/coin4.xpm",
	"./images/coin5.xpm",
	"./images/coin6.xpm",
};

typedef struct s_param
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		collected;
	int		cnt;
	int		collect_cnt;
	char	**two_d_map;
	void	*tile;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*player;
	int		time;
}				t_param;

typedef struct s_check
{
	int		collect;
	int		exit;
	int		player;
	size_t	len;
}				t_check;

typedef struct s_args
{
	int	c;
	int	width;
	int	has_width;
	int	precision;
	int	has_precision;
}				t_args;

int		ft_printf(const char *format, ...);

void	initialize_args(t_args *args);
char	*read_args(t_args *args, char *itr);
char	*ft_strchrr(char *str, char c);
int		ft_put_conv(t_args *args, va_list ap);
int		ft_strlenn(char *s);


int		ft_printf(const char *format, ...);
int		ft_printchar(char c, int fd);
int		ft_print_u_nbr(unsigned int n);
int		ft_address2(unsigned long long num);
int		ft_hex_len(unsigned long num);
void	ft_pointer(unsigned long num);
int		ft_puthexadecimal(unsigned int n, const char c);
int		ft_printnbr(int n);
int		ft_printstr(char *s, int fd);
char	*ft_itoa(int n);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	**ft_split(char const *s, char c);

void	ft_error(int exit_code);
void	param_init(t_param *param, char *map);
void	move_w(t_param *param);
void	move_s(t_param *param);
void	move_a(t_param *param);
void	move_d(t_param *param);
void	check_init(t_check *check);
void	ft_render(t_param *param, char *map);
int		move_check(t_param *param, int y, int x);
int		key_press(int keycode, t_param *param);
int		is_invalid_char(char c, t_check *check);
int		is_invalid_line(char *line, t_check *check);
int		check_close(char *line, size_t len);
int		is_not_rectangular(char *line, size_t len);
int		line_not_full_walls(char *line, size_t len);
int		cnt_collect(char *map);
int		exit_game(t_param *param);
char	*check_cep(t_check *check, char *map);
char	*ft_str_free(char *line, char *map);
char	*check_map(int fd);
size_t	ft_strlen_n(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif
