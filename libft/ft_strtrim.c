/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 07:56:19 by skalkan           #+#    #+#             */
/*   Updated: 2024/11/01 16:29:59 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trm;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]) != 0)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]) != 0)
		end--;
	len = end - start;
	trm = malloc(sizeof(char) * (len + 1));
	if (!trm)
		return (NULL);
	ft_strlcpy(trm, s1 + start, len + 1);
	return (trm);
}
