/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:53:56 by dalba-de          #+#    #+#             */
/*   Updated: 2020/02/04 15:12:46 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0'
			&& str2[i] != '\0')
		i++;
	return ((unsigned char)str1[i] - str2[i]);
}
