/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoitest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <audreyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:52:52 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/09 14:53:24 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoitest2(const char *str)
{
	int		i;
	int		moin;
	long	res;

	i = 0;
	res = 0;
	moin = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			moin = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0' && str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res * moin > 2147483647 || res * moin < -2147483648)
		return (1);
	else
		return (0);
}

int	ft_atoitest(char *str)
{
	int	i;
	int	mod;

	i = 0;
	mod = 0;
	while (str[i] && mod < 12)
	{
		if ((str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			&& (i == 0 || !((str[i - 1] <= '9'
						&& str[i - 1] >= '0') || str[i -1] == '-')))
			if (ft_atoitest2(&str[i]) == 1)
				mod = 14;
		if ((str[i] >= '0' && str[i] <= '9') || mod > 12)
			mod++;
		else
			mod = 0;
		i++;
	}
	if (mod > 12)
		return (1);
	return (0);
}
