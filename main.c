/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:56:24 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/28 12:50:38 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		check_save(char **argv)
{
	if (ft_strcmp(argv[2], "--save") > 0 ||
	ft_strlen(argv[2]) != ft_strlen("--save"))
	{
		exit_error(-2);
	}
	return (1);
}

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
		rotate_left(cub);
	if (cub->rot_right == 1)
		rotate_right(cub);
	raycast(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img_ptr, 0, 0);
	return (0);
}

void	init_ray(t_cub *cub)
{
	cub->ray.move_speed = 0.17;
	cub->ray.rot_speed = 0.05;
}

void	init_map(t_cub *cub, char *argv)
{
	cub->r = -1;
	cub->g = -1;
	cub->b = -1;
	cub->key_text = 1;
	init_ray(cub);
	if (parser(cub, argv) == -1)
		ft_close(cub);
}

int		main(int argc, char **argv)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(cub));
	if (argc == 2 && arg_check(argv[1], "cub"))
		init_map(&cub, argv[1]);
	else if (argc == 3 && arg_check(argv[1], "cub") && check_save(argv))
	{
		cub.bmp = 1;
		init_map(&cub, argv[1]);
		bitmap(&cub);
	}
	else if (argc < 2 || argc > 3)
		exit_error(-1);
	else
		exit_error(-2);
	mlx_hook(cub.win, 2, 1L << 0, ft_key_press, &cub);
	mlx_hook(cub.win, 3, 1L << 1, ft_key_release, &cub);
	mlx_hook(cub.win, 17, 1L << 17, ft_close, &cub);
	mlx_loop_hook(cub.mlx_ptr, ft_loop, &cub);
	mlx_loop(cub.mlx_ptr);
	return (0);
}
