/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:56:01 by skalkan           #+#    #+#             */
/*   Updated: 2024/11/01 16:32:37 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	lastindex;

	i = 0;
	lastindex = 0;
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			lastindex = i;
		i++;
	}
	if (s[lastindex] == (unsigned char)c)
		return ((char *)&s[lastindex]);
	return (NULL);
}
