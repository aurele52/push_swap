/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:41:00 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/09 16:34:18 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*ft_init(char *str, t_pos *free)
{
	t_all	*all;
	t_pos	*posa;
	t_pos	*posb;

	all = ft_malloc(sizeof(*all), free);
	if (all == 0)
		return (0);
	posa = ft_setpos(free);
	if (posa == 0)
		return (0);
	posb = ft_setpos(free);
	if (posb == 0)
		return (0);
	all->a = posa;
	all->b = posb;
	all->free = free;
	all = ft_setlist(str, all);
	return (all);
}

void	ft_aurelesort(t_all *all)
{
	t_list	*min;

	ft_transfer(all);
	ft_threesort(all);
	while (*all->b->size != 0)
	{
		if (ft_movebest(all, ft_best(all)) == 0)
			return ;
	}
	min = ft_lstmin(all->a);
	if (ft_lstrange(min) < *min->pos->size / 2)
		while (all->a->start != min)
			ft_rra(all);
	else
		while (all->a->start != min)
			ft_ra(all);
}

int	ft_test(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == ' ')
			return (1);
		if ((str[i] == ' ' && (str[i + 1] == 0 || str[i + 1] == ' '))
			|| (str[i] == '-' && (str[i + 1] == 0
					|| str[i + 1] == '-' || str[i + 1] == ' ')))
			return (1);
		if (!((str[i] >= '0' && str[i] <= '9')
				|| str[i] == ' ' || str[i] == '-'))
			return (1);
		i++;
	}
	return (0);
}
