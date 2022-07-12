/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bazar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:16:57 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/22 22:12:48 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*ft_moveclean(t_move *mv)
{
	if (mv->upup <= mv->updown && mv->upup <= mv->downup
		&& mv->upup <= mv->downdown)
		ft_setintzerovaria(3, &mv->rra, &mv->rrb, &mv->rrs);
	else if (mv->downdown <= mv->updown && mv->downdown <= mv->downup
		&& mv->downdown <= mv->upup)
		ft_setintzerovaria(3, &mv->ra, &mv->rb, &mv->rs);
	else if (mv->updown <= mv->upup && mv->updown <= mv->downup
		&& mv->updown <= mv->downdown)
		ft_setintzerovaria(4, &mv->rra, &mv->rb, &mv->rrs, &mv->rs);
	else if (mv->downup <= mv->updown && mv->downup <= mv->upup
		&& mv->downup <= mv->downdown)
		ft_setintzerovaria(4, &mv->ra, &mv->rrb, &mv->rrs, &mv->rs);
	mv->movenbr = mv->ra + mv->rb + mv->rra + mv->rrb - mv->rrs - mv->rs;
	return (mv);
}

int	ft_checkall(t_all *all)
{
	t_list	*a;
	t_list	*b;

	a = all->a->start;
	b = 0;
	while (b == 0 || a != all->a->start)
	{
		b = a->next;
		while (b != all->a->start)
		{
			if (ft_voidtoint(b->content) == ft_voidtoint(a->content))
				return (1);
			b = b->next;
		}
		a = a->next;
	}
	return (0);
}
