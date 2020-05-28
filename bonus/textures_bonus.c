/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 18:55:12 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/10 17:34:00 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

void	enemy_level(t_cub *cub)
{
	if (cub->level == 2)
	{
		cub->enemy[0].img = mlx_xpm_file_to_image(cub->mlx_ptr,
		"./textures/demon0.xpm", &cub->enemy[0].w, &cub->enemy[0].h);
		cub->enemy[1].img = mlx_xpm_file_to_image(cub->mlx_ptr,
		"./textures/demon1.xpm", &cub->enemy[1].w, &cub->enemy[1].h);
		cub->enemy[2].img = mlx_xpm_file_to_image(cub->mlx_ptr,
		"./textures/demon2.xpm", &cub->enemy[2].w, &cub->enemy[2].h);
		cub->enemy[3].img = mlx_xpm_file_to_image(cub->mlx_ptr,
		"./textures/demon3.xpm", &cub->enemy[3].w, &cub->enemy[3].h);
	}
	else if (cub->level == 1)
	{
		cub->enemy[0].img = mlx_xpm_file_to_image(cub->mlx_ptr,
		"./textures/enemy00.xpm", &cub->enemy[0].w, &cub->enemy[0].h);
		cub->enemy[1].img = mlx_xpm_file_to_image(cub->mlx_ptr,
		"./textures/enemy01.xpm", &cub->enemy[1].w, &cub->enemy[1].h);
		cub->enemy[2].img = mlx_xpm_file_to_image(cub->mlx_ptr,
		"./textures/enemy02.xpm", &cub->enemy[2].w, &cub->enemy[2].h);
		cub->enemy[3].img = mlx_xpm_file_to_image(cub->mlx_ptr,
		"./textures/enemy03.xpm", &cub->enemy[3].w, &cub->enemy[3].h);
	}
}

int		load_enemy_text(t_cub *cub)
{
	int i;

	enemy_level(cub);
	i = 0;
	while (i < 4)
	{
		if (!(cub->enemy[i].img))
			exit_error(-11);
		cub->enemy[i].data = (int *)mlx_get_data_addr(cub->enemy[i].img,
		&cub->enemy[i].bpp, &cub->enemy[i].sl, &cub->enemy[i].endian);
		i++;
	}
	return (0);
}

int		load_weapon_text(t_cub *cub)
{
	cub->weap[0].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/weapon0.xpm", &cub->weap[0].w, &cub->weap[0].h);
	cub->weap[1].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/weapon1.xpm", &cub->weap[1].w, &cub->weap[1].h);
	cub->weap[2].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/weapon2.xpm", &cub->weap[2].w, &cub->weap[2].h);
	if (!(cub->weap[0].img) || !(cub->weap[1].img) ||
	!(cub->weap[2].img))
		exit_error(-11);
	cub->weap[0].data = (int *)mlx_get_data_addr(cub->weap[0].img,
	&cub->weap[0].bpp, &cub->weap[0].sl, &cub->weap[0].endian);
	cub->weap[1].data = (int *)mlx_get_data_addr(cub->weap[1].img,
	&cub->weap[1].bpp, &cub->weap[1].sl, &cub->weap[1].endian);
	cub->weap[2].data = (int *)mlx_get_data_addr(cub->weap[2].img,
	&cub->weap[2].bpp, &cub->weap[2].sl, &cub->weap[2].endian);
	return (0);
}

int		load_more_tex_2(t_cub *cub)
{
	int i;

	cub->txt[12].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/ic_knife.xpm", &cub->txt[12].w, &cub->txt[12].h);
	cub->txt[13].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/ic_pistol.xpm", &cub->txt[13].w, &cub->txt[13].h);
	cub->txt[14].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/life.xpm", &cub->txt[14].w, &cub->txt[14].h);
	cub->txt[15].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/statue.xpm", &cub->txt[15].w, &cub->txt[15].h);
	cub->txt[16].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/gargola.xpm", &cub->txt[16].w, &cub->txt[16].h);
	cub->txt[17].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/tree.xpm", &cub->txt[17].w, &cub->txt[17].h);
	cub->txt[18].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/blood.xpm", &cub->txt[18].w, &cub->txt[18].h);
	i = 11;
	while (++i < 19)
	{
		if (!(cub->txt[i].img))
			exit_error(-11);
		cub->txt[i].data = (int *)mlx_get_data_addr(cub->txt[i].img,
		&cub->txt[i].bpp, &cub->txt[i].sl, &cub->txt[i].endian);
	}
	return (0);
}

int		load_more_tex(t_cub *cub)
{
	int i;

	cub->txt[6].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/floor.xpm", &cub->txt[6].w, &cub->txt[6].h);
	cub->txt[7].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/door.xpm", &cub->txt[7].w, &cub->txt[7].h);
	cub->txt[8].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/ceil.xpm", &cub->txt[8].w, &cub->txt[8].h);
	cub->txt[9].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/marbface.xpm", &cub->txt[9].w, &cub->txt[9].h);
	cub->txt[10].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/fond1.xpm", &cub->txt[10].w, &cub->txt[10].h);
	cub->txt[11].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	"./textures/marine.xpm", &cub->txt[11].w, &cub->txt[11].h);
	i = 6;
	while (i < 12)
	{
		if (!(cub->txt[i].img))
			exit_error(-11);
		cub->txt[i].data = (int *)mlx_get_data_addr(cub->txt[i].img,
		&cub->txt[i].bpp, &cub->txt[i].sl, &cub->txt[i].endian);
		i++;
	}
	load_more_tex_2(cub);
	return (0);
}
