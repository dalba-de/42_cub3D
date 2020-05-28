/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:53:39 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/28 13:13:39 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	verify_texture(t_cub *cub)
{
	if (!(cub->txt[0].img) || !(cub->txt[1].img) ||
	!(cub->txt[2].img) || !(cub->txt[3].img) || !(cub->txt[4].img)
	|| !(cub->txt[5].img))
		exit_error(-11);
	return (0);
}

int	data_texture(t_cub *cub)
{
	verify_texture(cub);
	cub->txt[0].data = (int *)mlx_get_data_addr(cub->txt[0].img,
	&cub->txt[0].bpp, &cub->txt[0].sl, &cub->txt[0].endian);
	cub->txt[1].data = (int *)mlx_get_data_addr(cub->txt[1].img,
	&cub->txt[1].bpp, &cub->txt[1].sl, &cub->txt[1].endian);
	cub->txt[2].data = (int *)mlx_get_data_addr(cub->txt[2].img,
	&cub->txt[2].bpp, &cub->txt[2].sl, &cub->txt[2].endian);
	cub->txt[3].data = (int *)mlx_get_data_addr(cub->txt[3].img,
	&cub->txt[3].bpp, &cub->txt[3].sl, &cub->txt[3].endian);
	cub->txt[4].data = (int *)mlx_get_data_addr(cub->txt[4].img,
	&cub->txt[4].bpp, &cub->txt[4].sl, &cub->txt[4].endian);
	cub->txt[5].data = (int *)mlx_get_data_addr(cub->txt[5].img,
	&cub->txt[5].bpp, &cub->txt[5].sl, &cub->txt[5].endian);
	return (0);
}

int	parser_bridge(char *line, t_cub *cub)
{
	int i;

	i = 0;
	ft_spaceskip(line, &i);
	if (line[i] == 'R' && line[i + 1] == ' ')
		cub->err_num = check_res(line, cub);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		cub->err_num = fill_color(&cub->floor, line, cub);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		cub->err_num = fill_color(&cub->ceiling, line, cub);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		cub->err_num = fill_texture(line, &cub->txt[0].path, cub, 0);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		cub->err_num = fill_texture(line, &cub->txt[1].path, cub, 1);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		cub->err_num = fill_texture(line, &cub->txt[2].path, cub, 2);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		cub->err_num = fill_texture(line, &cub->txt[3].path, cub, 3);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		cub->err_num = fill_texture(line, &cub->txt[4].path, cub, 4);
	else if (line[i] == 'T' && line[i + 1] == ' ')
		cub->err_num = fill_texture(line, &cub->txt[5].path, cub, 5);
	else if (line[i] == '1' || cub->err_map == 1 || line[0] == '0')
		cub->err_num = check_map(line, cub);
	return (cub->err_num < 0 ? exit_error(cub->err_num) : 0);
}

int	parser(t_cub *cub, char *argv)
{
	int		fd;
	char	*line;
	int		ret;

	ret = 1;
	first_lecture(cub, argv);
	if ((fd = open(argv, O_RDONLY)) < 0)
		exit_error(-3);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		parser_bridge(line, cub);
		free(line);
	}
	close(fd);
	locate_pos(cub);
	map_error(cub);
	data_texture(cub);
	load_more_tex(cub);
	load_weapon_text(cub);
	load_knife_text(cub);
	load_enemy_text(cub);
	load_numeros(cub);
	cub->spr = list_sprites(cub);
	return (0);
}
