/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:51:38 by rgrigore          #+#    #+#             */
/*   Updated: 2018/02/02 12:51:39 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			validate_file(char **line, int nr_col)
{
	int		i;
	int		j;
	int		w_count;
	char	**temp;

	w_count = 0;
	i = -1;
	while (line[++i])
	{
		w_count++;
		temp = ft_strsplit(line[i], ',');
		j = -1;
		while (temp[++j])
			if (!ft_ishexa(temp[j]) && !ft_isnum(temp[j]))
				return (0);
		free(temp);
	}
	if (w_count != nr_col)
		return (0);
	return (1);
}
