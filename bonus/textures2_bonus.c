/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 18:54:11 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/07 18:54:14 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int	load_numeros(t_cub *cub)
{
	cub->numeros.img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/numeros.xpm", &cub->numeros.w, &cub->numeros.h);
	cub->hud.img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/hud.xpm", &cub->hud.w, &cub->hud.h);
	cub->numeros.data = (int *)mlx_get_data_addr(cub->numeros.img,
	&cub->numeros.bpp, &cub->numeros.sl, &cub->numeros.endian);
	cub->hud.data = (int *)mlx_get_data_addr(cub->hud.img,
	&cub->hud.bpp, &cub->hud.sl, &cub->hud.endian);
	return (0);
}

int	load_knife_text(t_cub *cub)
{
	cub->knife[0].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/cuchillo0.xpm", &cub->knife[0].w, &cub->knife[0].h);
	cub->knife[1].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/cuchillo1.xpm", &cub->knife[1].w, &cub->knife[1].h);
	cub->knife[2].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/cuchillo2.xpm", &cub->knife[2].w, &cub->knife[2].h);
	if (!(cub->knife[0].img) || !(cub->knife[1].img) ||
	!(cub->knife[2].img))
		exit_error(-11);
	cub->knife[0].data = (int *)mlx_get_data_addr(cub->knife[0].img,
	&cub->knife[0].bpp, &cub->knife[0].sl, &cub->knife[0].endian);
	cub->knife[1].data = (int *)mlx_get_data_addr(cub->knife[1].img,
	&cub->knife[1].bpp, &cub->knife[1].sl, &cub->knife[1].endian);
	cub->knife[2].data = (int *)mlx_get_data_addr(cub->knife[2].img,
	&cub->knife[2].bpp, &cub->knife[2].sl, &cub->knife[2].endian);
	return (0);
}
