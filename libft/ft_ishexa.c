/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:04:21 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/31 19:04:23 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishexa(char *str)
{
	int		i;

	i = 1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!(str[0] == '0' && (str[1] == 'x' || str[1] == 'X')))
		return (0);
	while (str[++i])
	{
		if (!((str[i] >= 48 && str[i] <= 57) ||
		((str[i] >= 65 && str[i] <= 70) || (str[i] >= 97 && str[i] <= 102))))
			return (0);
	}
	return (1);
}
