/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:56:24 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/28 13:10:03 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int		ft_loop(t_cub *cub)
{
	mlx_destroy_image(cub->mlx_ptr, cub->img_ptr);
	cub->img_ptr = mlx_new_image(cub->mlx_ptr, cub->width, cub->height);
	if (cub->key_up == 1)
		key_up(cub);
	if (cub->key_down == 1)
		key_down(cub);
	if (cub->key_left == 1)
		move_lateral(cub, -1);
	if (cub->key_right == 1)
		move_lateral(cub, 1);
	if (cub->rot_left == 1)
		rotate(cub, -1);
	if (cub->rot_right == 1)
		rotate(cub, 1);
	check_win(cub);
	raycast(cub);
	shoot_animation(cub);
	draw_hud(cub);
	minimap(cub);
	draw_ammo(cub);
	draw_health(cub);
	draw_score(cub);
	draw_marine(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img_ptr, 0, 0);
	return (0);
}

void	init_ray(t_cub *cub)
{
	cub->ray.move_speed = 0.2;
	cub->ray.rot_speed = 0.1;
	cub->level = 1;
}

void	init_game(t_cub *cub, char *argv)
{
	cub->mlx_ptr = mlx_init();
	init_ray(cub);
	if (parser(cub, argv) == -1)
		ft_close(cub);
	cub->win = mlx_new_window(cub->mlx_ptr, cub->width, cub->height, "Cub3D");
	cub->img_ptr = mlx_new_image(cub->mlx_ptr, cub->width, cub->height);
	cub->data = mlx_get_data_addr(cub->img_ptr,
	&cub->bpp, &cub->sizeline, &cub->endian);
}

void	init_map(t_cub *cub, char *argv)
{
	int i;

	i = 0;
	cub->life = 100;
	cub->ammo = 5;
	while (i <= 9)
	{
		cub->txt[i].path = NULL;
		i++;
	}
	init_game(cub, argv);
}

int		main(int argc, char **argv)
{
	t_cub	cub;

	ft_bzero(&cub, (sizeof(cub)));
	cub.pid = -1;
	cub.pid = fork();
	if (argc == 2 && arg_check(argv[1], "cub"))
	{
		(cub.pid == 0) ? system("aplay ./bonus/sound/adrenaline.wav") : 0;
		(cub.pid != 0) ? init_map(&cub, argv[1]) : 0;
	}
	else if (argc == 3 && arg_check(argv[1], "cub") && check_save(argv))
		bitmap(&cub, argv[1]);
	else if (argc < 2 || argc > 3)
		exit_error(-1);
	else
		exit_error(-2);
	mlx_hook(cub.win, 2, 1L << 0, ft_key_press, &cub);
	mlx_hook(cub.win, 3, 1L << 1, ft_key_release, &cub);
	mlx_hook(cub.win, 4, 1L << 2, ft_mouse_press, &cub);
	mlx_hook(cub.win, 5, 1L << 3, ft_mouse_release, &cub);
	mlx_hook(cub.win, 6, 1L << 6, ft_mouse, &cub);
	mlx_hook(cub.win, 17, 0, ft_close, &cub);
	mlx_loop_hook(cub.mlx_ptr, ft_loop, &cub);
	mlx_loop(cub.mlx_ptr);
	return (0);
}
