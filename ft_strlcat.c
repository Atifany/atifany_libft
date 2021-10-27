/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:25:56 by atifany           #+#    #+#             */
/*   Updated: 2021/10/06 17:25:58 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstLen;

	dstLen = ft_strlen(dst);
	i = ft_strlen(dst);
	j = 0;
	while (i + 1 < dstsize && src[j])
		dst[i++] = src[j++];
	dst[i] = 0;
	if (dstsize > ft_strlen(dst))
		return (dstLen + ft_strlen(src));
	return (dstsize + ft_strlen(src));
}

int main()
{
	char	*dest = malloc(16);
	memset(dest, 'r', 15);
	char	*dest2 = malloc(16);
	memset(dest2, 'r', 15);
	size_t d = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
	size_t d2 = strlcat(dest2, "lorem ipsum dolor sit amet", 5);
	printf("%zu %zu \n",d,d2);


	//printf("%lu\t%lu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);

}