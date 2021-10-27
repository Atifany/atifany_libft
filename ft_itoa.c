/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:12 by atifany           #+#    #+#             */
/*   Updated: 2021/10/08 17:07:13 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ansHandler(int i, char *buf)
{
	char	*ans;

	ans = (char *)ft_calloc(12 - i, sizeof(char));
	if (ans)
		ft_strlcpy(ans, &buf[i], (12 - i) * sizeof(char));
	return (ans);
}

static void	negativeHandler(char *isNeg, int n, long *n1)
{
	*isNeg = 0;
	*n1 = (long)n;
	if (*n1 < 0)
	{
		*isNeg = '-';
		*n1 *= -1;
	}
}

char	*ft_itoa(int n)
{
	char	buf[12];
	int		i;
	char	isNeg;
	long	n1;

	ft_bzero(buf, 12);
	buf[10] = '0';
	buf[11] = '\0';
	if (n == 0)
		return (ansHandler(10, buf));
	negativeHandler(&isNeg, n, &n1);
	i = 10;
	while (n1 > 0)
	{
		buf[i--] = n1 % 10 + '0';
		n1 /= 10;
	}
	buf[i] = isNeg;
	if (buf[i] == 0)
		i += 1;
	return (ansHandler(i, buf));
}
