/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aurele_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:15:39 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/09 16:33:21 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_threesort(t_all *all)
{
	t_list	*mem;
	int		nbr;

	nbr = 0;
	mem = all->a->start;
	while (mem != mem->pos->end)
	{
		if (ft_voidtoint(mem->content) < ft_voidtoint(mem->next->content))
			nbr++;
		mem = mem->next;
	}
	if (ft_voidtoint(mem->content) < ft_voidtoint(mem->next->content))
		nbr++;
	if (nbr == 1)
		ft_sa(all);
	if (ft_voidtoint(all->a->start->content) > ft_voidtoint(all->a->start->next->content))
		ft_ra(all);
	if (ft_voidtoint(all->a->start->next->content) > ft_voidtoint(all->a->start->next->next->content))
		ft_rra(all);
}

void	ft_transfer(t_all *all)
{
	t_list	*median;
	t_list	*max;
	t_list	*min;

	max = ft_lstmax(all->a);
	median = ft_lstmedian(all->a);
	min = ft_lstmin(all->a);
	while (*all->a->size > 3)
	{
		if (all->a->start != median
			&& all->a->start != max && all->a->start != min)
		{
			ft_pb(all);
			if (ft_voidtoint(all->b->start->content) < ft_voidtoint(median->content))
				ft_rb(all);
		}
		else
			ft_ra(all);
	}
}

int	ft_moverra(t_all *all, t_list *list)
{
	int		nbr;
	t_list	*mem;

	nbr = 0;
	mem = all->a->start;
	while (!(ft_voidtoint(list->content) < ft_voidtoint(mem->content)
			&& ft_voidtoint(list->content) > ft_voidtoint(mem->back->content)))
	{
		mem = mem->back;
		nbr++;
	}
	return (nbr);
}

int	ft_movera(t_all *all, t_list *list)
{
	int		nbr;
	t_list	*mem;

	nbr = 0;
	mem = all->a->start;
	while (!(ft_voidtoint(list->content) < ft_voidtoint(mem->content)
			&& ft_voidtoint(list->content) > ft_voidtoint(mem->back->content)))
	{
		mem = mem->next;
		nbr++;
	}
	return (nbr);
}
