/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:01:28 by dalba-de          #+#    #+#             */
/*   Updated: 2020/03/10 13:02:34 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_bzero(void *str, size_t n)
{
	char	*c;
	size_t	i;

	c = (char*)str;
	if (n != 0)
	{
		i = 0;
		while (i < n)
		{
			c[i] = '\0';
			i++;
		}
	}
}
