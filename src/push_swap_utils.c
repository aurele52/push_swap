/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:18:53 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/15 19:50:17 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*ft_setlist(char *str, t_all *all)
{
	int	i;

	i = 0;
	while (str[i])
	{
		all->a->end = ft_lstnew(
				ft_mallocint(ft_atoi(&str[i]), all->free), all->a, all->free);
		if (all->a->end == 0)
			return (0);
		while (str[i] != 0 && str[i] != ' ')
			i++;
		if (str[i] == ' ')
			i++;
	}
	return (all);
}

int	ft_correct(t_all *all)
{
	t_list	*i;

	if (*all->b->size != 0)
		return (0);
	i = all->a->start;
	while (i != all->a->end)
	{
		if (*i->content > *i->next->content)
			return (0);
		i = i->next;
	}
	return (1);
}
