/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:57:15 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/28 12:53:55 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE 32
# define ESC 65307
# define M 109
# define T 116
# define W 119
# define S 115
# define D 100
# define A 97
# define LEFT 65361
# define RIGHT 65363

/*
** DEFINE STRUCT
*/

typedef	struct		s_txt
{
	char			*path;
	void			*img;
	int				*data;
	int				w;
	int				h;
	int				sl;
	int				bpp;
	int				endian;
}					t_txt;

typedef struct		s_ray
{
	int				x;
	int				l;
	double			x_pos;
	double			y_pos;
	double			x_dir;
	double			y_dir;
	double			a_dir;
	double			old_dir_x;
	double			old_plane_x;
	double			x_plane;
	double			y_plane;
	double			rot_speed;
	double			move_speed;
	double			cam;
	double			raydir_x;
	double			raydir_y;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			walldist;
	double			wall_x;
	int				hit;
	int				side;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
	char			walldir;
	double			zbuffer[4000];
}					t_ray;

typedef	struct		s_sprite
{
	double			x;
	double			y;
	double			d;
}					t_spr;

typedef struct		s_sprtools
{
	double			sp_x;
	double			sp_y;
	double			invdet;
	double			transf_x;
	double			transf_y;
	int				screen;
	int				height;
	int				width;
	int				drawstart_y;
	int				drawend_y;
	int				drawstart_x;
	int				drawend_x;
	int				x;
	int				y;
	int				d;
	int				tex_x;
	int				tex_y;
}					t_sprtools;

typedef struct		s_cub
{
	int				bmp;
	int				width;
	int				height;
	unsigned int	floor;
	unsigned int	ceiling;
	int				r;
	int				g;
	int				b;
	int				err_num;
	int				err_map;
	int				err_pos;
	int				err_f;
	int				err_c;
	int				err_r;
	int				map_x;
	int				map_y;
	char			**map;
	int				map_spr;
	void			*mlx_ptr;
	void			*img_ptr;
	void			*win;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				key_up;
	int				key_down;
	int				key_left;
	int				key_right;
	int				rot_left;
	int				rot_right;
	int				key_text;
	int				key_map;
	int				*txt_data;
	int				text_sl;
	int				text_h;
	int				text_x;
	double			zbuffer[4000];
	int				*sprorder;
	t_ray			ray;
	t_txt			txt[5];
	t_spr			*spr;
	t_spr			*sorted_spr;
}					t_cub;

/*
** PARSER FUNCTIONS
*/

void				ft_sprite(t_cub *cub);
t_spr				*list_sprites(t_cub *cub);

/*
** PARSER FUNCTIONS
*/

int					locate_pos(t_cub *cub);
int					check_map(char *line, t_cub *cub);
int					init_textures(t_cub *cub, int dir);
int					fill_texture(char *line, char **text_path,
					t_cub *cub, int dir);
int					fill_color(unsigned int *color, char *line, t_cub *cub);
int					check_res(char *line, t_cub *cub);
int					parser(t_cub *cub, char *argv);

/*
** TOOLS FUNCTIONS
*/

void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_spaceskip(char *line, int *i);
int					ft_atoi(char *line, int *i);
int					ft_isdigit(int c);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_strcmp(char *str1, char *str2);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					get_next_line(int fd, char **line);

/*
** RAYCAST FUNCTIONS
*/

void				draw_dot(t_cub *cub, int x, int y, int color);
void				pix_img(t_cub *cub, int color);
int					draw(t_cub *cub);
void				check_x_text(t_cub *cub);
void				select_texture(t_cub *cub);
void				lengthline(t_cub *cub);
void				draw_wall(int x, int start, int end, t_cub *cub);
void				fill_img(t_cub *cub);
void				color_wall(t_cub *cub);
int					raycast(t_cub *cub);

/*
** EXIT FUNCTIONS
*/

int					bad_map(t_cub *cub);
int					ft_close(t_cub *cub);
int					exit_error(int err);

/*
** CHECK FUNCTIONS
*/

char				f_char(int x, int y, t_cub *cub);
void				map_error(t_cub *cub);
int					arg_check(char *argv, char *arg);
int					check_save(char **argv);

/*
** KEY FUNCTIONS
*/

void				key_up(t_cub *cub);
void				key_down(t_cub *cub);
void				move_lateral(t_cub *cub, char c);
void				rotate_left(t_cub *cub);
void				rotate_right(t_cub *cub);
int					ft_key_release(int key, t_cub *cub);
int					ft_key_press(int key, t_cub *cub);

/*
** MAIN AND INIT FUNCTIONS
*/

int					first_lecture(t_cub *cub, char *argv);
int					bitmap(t_cub *cub);
void				init_ray(t_cub *cub);
int					main(int argc, char **argv);

#endif
