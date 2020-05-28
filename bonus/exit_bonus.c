/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:26:48 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/19 18:31:22 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int	bad_map(t_cub *cub)
{
	if (cub->err_map)
		return (exit_error(-17));
	return (0);
}

int	ft_bonus_close(t_cub *cub)
{
	mlx_destroy_window(cub->mlx_ptr, cub->win);
	exit(0);
	return (1);
}

int	ft_close(t_cub *cub)
{
	mlx_destroy_window(cub->mlx_ptr, cub->win);
	system("killall aplay");
	exit(0);
	return (1);
}

int	exit_error(int err)
{
	(err == -1) ? ft_putstr("Error: Invalid number of arguments\n") : 0;
	(err == -2) ? ft_putstr("Error: Argument invalid\n") : 0;
	(err == -3) ? ft_putstr("Error: can´t open map\n") : 0;
	(err == -4) ? ft_putstr("Error: Invalid map\n") : 0;
	(err == -5) ? ft_putstr("Error: Wrong resolution\n") : 0;
	(err == -6) ? ft_putstr("Error: Color previosly define\n") : 0;
	(err == -7) ? ft_putstr("Error: Color invalid\n") : 0;
	(err == -8) ? ft_putstr("Error: Texture previosly define\n") : 0;
	(err == -9) ? ft_putstr("Error: Memory allocation fail\n") : 0;
	(err == -10) ? ft_putstr("Error: Invalid texture\n") : 0;
	(err == -11) ? ft_putstr("Error: Error loading textures\n") : 0;
	(err == -12) ? ft_putstr("Map error: (unknown element)\n") : 0;
	(err == -13) ? ft_putstr("Map error: No Sprites\n") : 0;
	(err == -14) ? ft_putstr("Map error: Bad position\n") : 0;
	(err == -15) ? ft_putstr("Map error: Not surrounded by walls\n") : 0;
	(err == -16) ? ft_putstr("Error: no color found\n") : 0;
	(err == -17) ? ft_putstr("Error: incorrect line inside map\n") : 0;
	system("killall aplay");
	exit(-1);
	return (-1);
}
