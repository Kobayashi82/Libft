/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:27:58 by vzurera-          #+#    #+#             */
/*   Updated: 2026/03/11 19:23:00 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static void	free_result(char **result, int j)
{
	while (j >= 0)
	{
		free(result[j]);
		j--;
	}
	free(result);
}

static char	*get_word(const char *str, int start, int end)
{
	char	*word;
	int		k;

	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	k = 0;
	while (k < end - start)
	{
		word[k] = str[start + k];
		k++;
	}
	word[k] = '\0';
	return (word);
}

static char	**init_result(const char *str, char c, int *i, int *j)
{
	*i = 0;
	*j = 0;
	if (!str)
		return (NULL);
	return (ft_calloc(count_words(str, c) + 1, sizeof(char *)));
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	int		start;
	int		i;
	int		j;

	result = init_result(str, c, &i, &j);
	if (!result)
		return (NULL);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			start = i;
			while (str[i] && str[i] != c)
				i++;
			result[j] = get_word(str, start, i);
			if (!result[j])
				return (free_result(result, j - 1), NULL);
			j++;
		}
	}
	return (result);
}
