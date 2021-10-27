/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:55:29 by atifany           #+#    #+#             */
/*   Updated: 2021/10/05 14:55:31 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	overLongHandler(int isNeg)
{
	if (isNeg == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long			i;
	long long			isNeg;
	unsigned long long	ans;

	i = 0;
	isNeg = 1;
	ans = 0;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isNeg *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans *= 10;
		ans += str[i++] - '0';
	}
	if (ans > 9223372036854775807)
		return (overLongHandler(isNeg));
	ans = (long long)ans;
	ans *= isNeg;
	return ((int)ans);
}
