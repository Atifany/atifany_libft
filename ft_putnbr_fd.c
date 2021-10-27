/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:16:02 by atifany           #+#    #+#             */
/*   Updated: 2021/10/13 14:16:03 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	negativeHandler_helper(char *isNeg, int n, long *n1)
{
	*isNeg = 0;
	*n1 = (long)n;
	if (*n1 < 0)
	{
		*isNeg = '-';
		*n1 *= -1;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[11];
	int		i;
	char	isNeg;
	long	n1;

	if (n == 0)
		write(fd, "0", 1);
	negativeHandler_helper(&isNeg, n, &n1);
	ft_bzero(buf, 11);
	i = 10;
	while (n1 > 0)
	{
		buf[i--] = n1 % 10 + '0';
		n1 /= 10;
	}
	buf[i] = isNeg;
	if (buf[i] == 0)
		i += 1;
	write(fd, &buf[i], 11 - i);
}
