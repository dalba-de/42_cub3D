/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:57:15 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/28 13:10:32 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>

# define BUFFER_SIZE 32
# define ESC 65307
# define E 101
# define W 119
# define S 115
# define D 100
# define A 97
# define LEFT 65361
# define RIGHT 65363
# define SPACE 32
# define SHIFT 65505
# define M_LEFT 1

/*
** DEFINE STRUCT
*/

typedef struct		s_ints
{
	int				i;
	int				j;
	int				k;
}					t_ints;

typedef	struct		s_score
{
	int				x;
	int				y;
	int				i;
	int				rest;
	int				score;
	int				frame;
}					t_score;

typedef	struct		s_health
{
	int				x;
	int				y;
	int				i;
	int				health;
	int				life;
	int				frame;
}					t_health;

typedef struct		s_point
{
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				x;
	int				y;
}					t_point;

typedef struct		s_floor
{
	int				y;
	int				x;
	float			raydirx0;
	float			raydiry0;
	float			raydirx1;
	float			raydiry1;
	int				p;
	float			posz;
	float			rowdistance;
	float			stepx;
	float			stepy;
	float			floorx;
	float			floory;
	int				cellx;
	int				celly;
	int				tx;
	int				ty;
}					t_floor;

typedef struct		s_minimap
{
	void			*img_ptr;
	int				*data;
	int				sizel;
	int				bpp;
	int				endian;
	int				color;
	int				start;
}					t_minimap;

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
	char			c;
	int				life;
	int				hit;
	int				rip;
	unsigned int	v;
	int				getshot;
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
	char			c;
	int				bmp;
	int				width;
	int				height;
	unsigned int	floor;
	unsigned int	ceiling;
	int				err_num;
	int				err_map;
	int				err_pos;
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
	int				*txt_data;
	int				text_sl;
	int				text_h;
	int				text_x;
	double			zbuffer[4000];
	int				*sprorder;
	int				pid;
	int				score;
	int				step_shoot;
	int				shoot;
	int				sp_state;
	int				life;
	int				ammo;
	int				level;
	int				mouse;
	t_ray			ray;
	t_minimap		minimap;
	t_txt			txt[19];
	t_spr			*spr;
	t_spr			*sorted_spr;
	t_floor			f;
	t_txt			weap[3];
	t_txt			knife[3];
	t_txt			enemy[4];
	t_txt			lifebar[6];
	t_txt			num_pick[6];
	t_txt			numeros;
	t_txt			hud;
}					t_cub;

/*
** SPRITE FUNCTIONS
*/

void				draw_sprite(t_sprtools *stools, t_cub *cub, t_txt *txt);
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

void				floor_casting(t_cub *cub);
void				draw_floor(t_cub *cub);
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

int					ft_bonus_close(t_cub *cub);
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
void				rotate(t_cub *cub, double i);
int					ft_key_release(int key, t_cub *cub);
int					ft_key_press(int key, t_cub *cub);
int					ft_mouse(int x, int y, t_cub *cub);
int					ft_mouse_press(int button, int x, int y, t_cub *cub);
int					ft_mouse_release(int button, int x, int y, t_cub *cub);

/*
** BONUS TEXTURE FUNCTIONS
*/

void				west_text(t_cub *cub);
void				east_text(t_cub *cub);
void				south_text(t_cub *cub);
void				north_text(t_cub *cub);
int					load_numeros(t_cub *cub);
int					load_knife_text(t_cub *cub);
int					load_more_tex(t_cub *cub);
int					load_weapon_text(t_cub *cub);
int					load_enemy_text(t_cub *cub);
int					load_life_text(t_cub *cub);
int					load_num_text(t_cub *cub);

/*
** BONUS ENEMY FUNCTIONS
*/

void				get_shot(t_cub *cub, t_spr *spr);
void				shoot_animation(t_cub *cub);
void				hit_sprite(t_cub *cub, int i);
void				on_shoot(t_cub *cub, t_sprtools *stools, int i);
int					anim_text(t_spr *spr);
void				draw_sprite_enemy(t_sprtools *stools, t_cub *cub, int i);

/*
** BONUS FUNCTIONS
*/

void				draw_percent(t_cub *cub);
void				draw_marine(t_cub *cub);
void				draw_score(t_cub *cub);
void				draw_ammo(t_cub *cub);
void				draw_health(t_cub *cub);
void				draw_hud(t_cub *cub);
void				draw_sky(t_cub *cub);
void				check_pick(t_cub *cub);
void				ft_reset(t_cub *cub);
void				draw_weapon(t_cub *cub);
int					check_win(t_cub *cub);
int					ft_pick(t_cub *cub);
void				score(t_cub *cub);
void				draw_square(t_cub *cub, int x, int y, int color);
void				ft_open(t_cub *cub);
void				minimap(t_cub *cub);

/*
** MAIN AND INIT FUNCTIONS
*/

int					first_lecture(t_cub *cub, char *argv);
int					bitmap(t_cub *cub, char *argv);
void				init_map(t_cub *cub, char *argv);
void				init_ray(t_cub *cub);
int					main(int argc, char **argv);

#endif
