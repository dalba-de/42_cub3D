/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:44:15 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/18 13:52:59 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	complete_str(char *str, t_cub *cub)
{
	int len;

	len = ft_strlen(str);
	if (len < cub->map_x)
	{
		while (len < cub->map_x)
		{
			str[len] = '9';
			len++;
		}
		str[len] = '\0';
	}
}

char	*append_line(char *line, t_cub *cub)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * cub->map_x + 1)))
		return (NULL);
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
		|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
		|| line[i] == '2' || line[i == ' '])
			str[j++] = line[i];
		if (line[i] == '2')
			cub->map_spr++;
		i++;
	}
	str[j] = '\0';
	complete_str(str, cub);
	return (str);
}

int		check_map(char *line, t_cub *cub)
{
	char	**aux;
	int		k;

	k = 0;
	cub->err_map = 1;
	if (!(aux = malloc(sizeof(char *) * (cub->map_y + 1))))
		return (exit_error(-9));
	while (k < cub->map_y)
	{
		aux[k] = cub->map[k];
		k++;
	}
	if ((aux[cub->map_y] = append_line(line, cub)) == NULL)
		return (exit_error(-9));
	if (cub->map_y > 0)
		free(cub->map);
	cub->map = aux;
	cub->map_y++;
	return (0);
}
