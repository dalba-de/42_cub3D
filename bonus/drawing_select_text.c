/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_select_text.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:09:19 by dalba-de          #+#    #+#             */
/*   Updated: 2020/04/10 17:12:11 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

void	west_text(t_cub *cub)
{
	if (cub->ray.walldir == 'W' && (cub->c == '1' || cub->c == 'X'))
	{
		cub->txt_data = cub->txt[3].data;
		cub->text_sl = cub->txt[3].sl;
		cub->text_h = cub->txt[3].h;
	}
	else if (cub->ray.walldir == 'W' && cub->c == 'D')
	{
		cub->txt_data = cub->txt[7].data;
		cub->text_sl = cub->txt[7].sl;
		cub->text_h = cub->txt[7].h;
	}
	else if (cub->ray.walldir == 'W' && cub->c == 'L')
	{
		cub->txt_data = cub->txt[9].data;
		cub->text_sl = cub->txt[9].sl;
		cub->text_h = cub->txt[9].h;
	}
}

void	east_text(t_cub *cub)
{
	if (cub->ray.walldir == 'E' && (cub->c == '1' || cub->c == 'X'))
	{
		cub->txt_data = cub->txt[2].data;
		cub->text_sl = cub->txt[2].sl;
		cub->text_h = cub->txt[2].h;
	}
	else if (cub->ray.walldir == 'E' && cub->c == 'D')
	{
		cub->txt_data = cub->txt[7].data;
		cub->text_sl = cub->txt[7].sl;
		cub->text_h = cub->txt[7].h;
	}
	else if (cub->ray.walldir == 'E' && cub->c == 'L')
	{
		cub->txt_data = cub->txt[9].data;
		cub->text_sl = cub->txt[9].sl;
		cub->text_h = cub->txt[9].h;
	}
}

void	south_text(t_cub *cub)
{
	if (cub->ray.walldir == 'S' && (cub->c == '1' || cub->c == 'X'))
	{
		cub->txt_data = cub->txt[1].data;
		cub->text_sl = cub->txt[1].sl;
		cub->text_h = cub->txt[1].h;
	}
	else if (cub->ray.walldir == 'S' && cub->c == 'D')
	{
		cub->txt_data = cub->txt[7].data;
		cub->text_sl = cub->txt[7].sl;
		cub->text_h = cub->txt[7].h;
	}
	else if (cub->ray.walldir == 'S' && cub->c == 'L')
	{
		cub->txt_data = cub->txt[9].data;
		cub->text_sl = cub->txt[9].sl;
		cub->text_h = cub->txt[9].h;
	}
}

void	north_text(t_cub *cub)
{
	if (cub->ray.walldir == 'N' && (cub->c == '1' || cub->c == 'X'))
	{
		cub->txt_data = cub->txt[0].data;
		cub->text_sl = cub->txt[0].sl;
		cub->text_h = cub->txt[0].h;
	}
	else if (cub->ray.walldir == 'N' && cub->c == 'D')
	{
		cub->txt_data = cub->txt[7].data;
		cub->text_sl = cub->txt[7].sl;
		cub->text_h = cub->txt[7].h;
	}
	else if (cub->ray.walldir == 'N' && cub->c == 'L')
	{
		cub->txt_data = cub->txt[9].data;
		cub->text_sl = cub->txt[9].sl;
		cub->text_h = cub->txt[9].h;
	}
}
