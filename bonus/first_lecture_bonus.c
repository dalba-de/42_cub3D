/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_lecture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:24:20 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/09 17:02:30 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int	find_map_error(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2' &&
		line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
		&& line[i] != ' ' && line[i] != 'D' && line[i] != 'X' && line[i] != 'T'
		&& line[i] != 'L' && line[i] != 'O' && line[i] != 'B' && line[i] != 'H'
		&& line[i] != '3' && line[i] != '4' && line[i] != '5')
			exit_error(-12);
		i++;
	}
	return (0);
}

int	find_map(char *line, t_cub *cub)
{
	int i;
	int count;

	i = 0;
	count = 0;
	ft_spaceskip(line, &i);
	count += i;
	if (line[i] == '1' || line[i] == '0' || line[i] == '2')
	{
		find_map_error(line);
		while (line[i++])
			count++;
	}
	if (cub->map_x < count)
		cub->map_x = count;
	return (0);
}

int	first_lecture(t_cub *cub, char *argv)
{
	int		ret;
	int		fd;
	char	*line;

	ret = 1;
	if ((fd = open(argv, O_RDONLY)) < 0)
		exit_error(-3);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		find_map(line, cub);
		free(line);
	}
	close(fd);
	return (0);
}
