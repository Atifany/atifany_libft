/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:12:02 by atifany           #+#    #+#             */
/*   Updated: 2021/10/08 16:12:03 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cleaner(char **arr, int wordsToClear)
{
	while (wordsToClear > 0)
		free(arr[wordsToClear--]);
	free(arr);
}

static char	**createZero(char **arr, int isClearing, int wordsToClear)
{
	if (isClearing == 1)
		cleaner(arr, wordsToClear);
	arr = ft_calloc(1, sizeof(char *));
	if (arr)
		arr[0] = NULL;
	return (arr);
}

static int	countWords(char const *s, char c)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if ((s[i] == c || s[i] == 0) && s[i - 1] != c)
		count++;
	return (count);
}

static char	**arrFill(int wordsCount, char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;
	char			**arr;

	i = 1;
	j = 0;
	start = 0;
	arr = ft_calloc(wordsCount + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			arr[j++] = ft_substr(s, start, i - start);
		if (s[i] != c && s[i - 1] == c)
			start = i;
		if (j > 0 && !arr[j - 1])
			return (createZero(arr, 1, j - 2));
		i++;
	}
	if ((s[i] == c || s[i] == 0) && s[i - 1] != c)
		arr[j] = ft_substr(s, start, i - start);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		wordsCount;
	char	**arr;

	if (!s || ft_strlen(s) == 0)
		return (createZero(NULL, 0, 0));
	wordsCount = countWords(s, c);
	arr = arrFill(wordsCount, s, c);
	if (!arr)
		return (createZero(NULL, 0, 0));
	if (!arr[wordsCount - 1])
		return (createZero(arr, 1, wordsCount - 2));
	arr[wordsCount] = NULL;
	return (arr);
}
