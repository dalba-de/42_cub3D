/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:44:15 by dalba-de          #+#    #+#             */
/*   Updated: 2020/05/19 18:30:01 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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

char	*append_line(char *l, t_cub *cub)
{
	char	*str;
	t_ints	e;

	e.i = 0;
	e.j = 0;
	if (!(str = malloc(sizeof(char) * cub->map_x + 1)))
		return (NULL);
	while (l[e.i])
	{
		if (l[e.i] == '0' || l[e.i] == '1' || l[e.i] == 'N' || l[e.i] == 'S'
		|| l[e.i] == 'E' || l[e.i] == 'W' || l[e.i] == '2' || l[e.i] == 'D'
		|| l[e.i] == 'O' || l[e.i] == 'T' || l[e.i] == 'X' || l[e.i] == 'L'
		|| l[e.i] == 'B' || l[e.i] == 'H' || l[e.i] == '3'
		|| l[e.i] == '4' || l[e.i] == '5' || l[e.i] == ' ')
			str[e.j++] = l[e.i];
		if (l[e.i] == '2' || l[e.i] == 'T' || l[e.i] == 'B' || l[e.i] == 'H'
		|| l[e.i] == '3' || l[e.i] == '4' || l[e.i] == '5')
			cub->map_spr++;
		e.i++;
	}
	str[e.j] = '\0';
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
