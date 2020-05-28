/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:51:04 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/09 20:36:11 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int		init_textures(t_cub *cub, int dir)
{
	if (dir == 0)
		cub->txt[0].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	cub->txt[0].path, &cub->txt[0].w, &cub->txt[0].h);
	else if (dir == 1)
		cub->txt[1].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	cub->txt[1].path, &cub->txt[1].w, &cub->txt[1].h);
	else if (dir == 2)
		cub->txt[2].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	cub->txt[2].path, &cub->txt[2].w, &cub->txt[2].h);
	if (dir == 3)
		cub->txt[3].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	cub->txt[3].path, &cub->txt[3].w, &cub->txt[3].h);
	else if (dir == 4)
		cub->txt[4].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	cub->txt[4].path, &cub->txt[4].w, &cub->txt[4].h);
	else if (dir == 5)
		cub->txt[5].img = mlx_xpm_file_to_image(cub->mlx_ptr,
	cub->txt[5].path, &cub->txt[5].w, &cub->txt[5].h);
	return (0);
}

int		fill_texture(char *line, char **text_path, t_cub *cub, int dir)
{
	int		i;
	int		j;
	int		k;

	bad_map(cub);
	i = 2;
	j = 0;
	if (*text_path != NULL)
		return (-8);
	ft_spaceskip(line, &i);
	k = i;
	while (line[i++])
		j++;
	if (!(*text_path = malloc(sizeof(char) * j + 1)))
		return (-9);
	j = 0;
	while (line[k])
		(*text_path)[j++] = line[k++];
	(*text_path)[j] = '\0';
	if (!arg_check(*text_path, "xpm"))
		return (-10);
	init_textures(cub, dir);
	free(*text_path);
	return (0);
}

int		check_res(char *line, t_cub *cub)
{
	int i;

	bad_map(cub);
	i = 0;
	while (line[i])
	{
		while (!ft_isdigit(line[i]))
			i++;
		cub->width = ft_atoi(line, &i);
		while (!ft_isdigit(line[i]))
			i++;
		cub->height = ft_atoi(line, &i);
	}
	if ((cub->width) < 200 || (cub->height) < 200)
		return (-5);
	else if ((cub->width) > 2560)
		cub->width = 2560;
	else if ((cub->height) > 1400)
		cub->width = 1400;
	return (1);
}

int		fill_color(unsigned int *color, char *line, t_cub *cub)
{
	int r;
	int g;
	int b;
	int i;

	bad_map(cub);
	i = 0;
	if (*color > 0)
		return (-6);
	while (line[i])
	{
		while ((line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		r = ft_atoi(line, &i);
		while ((line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		g = ft_atoi(line, &i);
		while ((line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		b = ft_atoi(line, &i);
	}
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		return (-7);
	*color = r * 256 * 256 + g * 256 + b;
	return (0);
}
