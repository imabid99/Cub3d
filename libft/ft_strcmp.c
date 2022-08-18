/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:57:48 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/06/05 17:58:46 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	s1i;
	unsigned char	s2i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		s1i = s1[i];
		s2i = s2[i];
		if (s1i != s2i)
			return (s1i - s2i);
		i++;
	}
	return (0);
}
