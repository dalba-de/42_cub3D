/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:53:39 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/28 13:20:51 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	verify_texture(t_cub *cub)
{
	if (!(cub->txt[0].img) || !(cub->txt[1].img) ||
	!(cub->txt[2].img) || !(cub->txt[3].img) || !(cub->txt[4].img))
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
	else if (line[i] == '1' || cub->err_map == 1 || line[i] == '0')
		cub->err_num = check_map(line, cub);
	else if (line[i] != '\0')
		exit_error(-19);
	return (cub->err_num < 0 ? exit_error(cub->err_num) : 0);
}

int	parser(t_cub *cub, char *argv)
{
	int		fd;
	char	*line;
	int		ret;

	ret = 1;
	first_lecture(cub, argv);
	cub->mlx_ptr = mlx_init();
	fd = open(argv, O_RDONLY);
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
	(cub->bmp == 0) ? cub->win =
	mlx_new_window(cub->mlx_ptr, cub->width, cub->height, "Cub3D") : 0;
	cub->img_ptr = mlx_new_image(cub->mlx_ptr, cub->width, cub->height);
	cub->data = mlx_get_data_addr(cub->img_ptr,
	&cub->bpp, &cub->sizeline, &cub->endian);
	cub->spr = list_sprites(cub);
	return (0);
}
