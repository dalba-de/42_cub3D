/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:51:04 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/28 12:22:48 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		if (cub->height != 0 || cub->width != 0)
			return (-18);
		while (!ft_isdigit(line[i]))
			i++;
		cub->width = ft_atoi(line, &i);
		while (!ft_isdigit(line[i]))
			i++;
		cub->height = ft_atoi(line, &i);
	}
	if ((cub->width) < 200 || (cub->height) < 200)
		return (-5);
	if ((cub->width) > 1920)
		cub->width = 1920;
	if ((cub->height) > 1080)
		cub->height = 1080;
	return (1);
}

void	loop_color(char *line, t_cub *cub)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (cub->r != -1 || cub->g != -1 || cub->b != -1)
			exit_error(-7);
		while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		cub->r = ft_atoi(line, &i);
		while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		if (line[i] == '\0')
			break ;
		cub->g = ft_atoi(line, &i);
		while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		if (line[i] == '\0')
			break ;
		cub->b = ft_atoi(line, &i);
	}
}

int		fill_color(unsigned int *color, char *line, t_cub *cub)
{
	bad_map(cub);
	if (*color > 0)
		return (-6);
	loop_color(line, cub);
	if (cub->r > 255 || cub->r < 0 || cub->g > 255 ||
	cub->g < 0 || cub->b > 255 || cub->b < 0)
		return (-7);
	*color = cub->r * 256 * 256 + cub->g * 256 + cub->b;
	cub->r = -1;
	cub->g = -1;
	cub->b = -1;
	return (0);
}
