/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:20:32 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/21 17:37:17 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fivesort(t_all *all)
{
	while (*all->a->size != 3)
	{
		if (all->a->start == ft_lstmin(all->a))
			ft_pb(all);
		else if (all->a->end == ft_lstmin(all->a)
			|| all->a->end->back == ft_lstmin(all->a))
			ft_rra(all);
		else
			ft_ra(all);
	}
	ft_threesort(all);
	ft_pa(all);
	ft_pa(all);
}

void	push_swap(char *str, t_pos *garbage)
{
	t_all	*all;

	all = 0;
	all = ft_init(str, garbage);
	if (all == 0)
		ft_exit(garbage, "Error");
	if (ft_checkall(all) == 1)
		ft_exit(garbage, "Error");
	if (ft_correct(all) == 1)
		ft_exit(garbage, 0);
	if (*all->a->size == 5)
		ft_fivesort(all);
	else
		ft_aurelesort(all);
	ft_exit(garbage, 0);
}

int	ft_testargv(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j != argc)
	{
		if (ft_strlen(argv[j]) == 0)
			return (1);
		while (argv[j][i])
		{
			if (argv[j][i] == ' ')
				return (1);
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*str;
	t_pos	*garbage;

	if (argc == 1)
		return (0);
	if (ft_testargv(&argv[1], argc - 1) == 1)
		ft_exit(0, "Error");
	garbage = ft_setpos(0);
	if (garbage == 0)
		return (0);
	str = ft_unsplit(&argv[1], " ", garbage);
	if (str == 0)
		ft_exit(garbage, "Error");
	if (ft_test(str) == 1 || ft_atoitest(str) == 1)
		ft_exit(garbage, "Error");
	push_swap(str, garbage);
}
