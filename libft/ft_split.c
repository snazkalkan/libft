/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:20:07 by skalkan           #+#    #+#             */
/*   Updated: 2024/11/01 12:42:18 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_words(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (words[i])
			free(words[i]);
		i++;
	}
	free(words);
}

static int	count_words(const char *s, char delimiter)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != delimiter && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == delimiter)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*extract_word(const char **s, char delimiter)
{
	const char	*start;
	size_t		len;

	while (**s && **s == delimiter)
		(*s)++;
	start = *s;
	len = 0;
	while ((*s)[len] && (*s)[len] != delimiter)
		len++;
	*s += len;
	return (ft_substr(start, 0, len));
}

char	**ft_split(const char *s, char delimiter)
{
	char	**result;
	size_t	word_count;
	size_t	i;

	if (!s)
		return (NULL);
	word_count = count_words(s, delimiter);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		result[i] = extract_word(&s, delimiter);
		if (!result[i])
		{
			free_words(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
