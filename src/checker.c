/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:22:03 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/09 15:36:06 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fonction_tab(int emp, t_all *all, t_pos *garbage)
{
	if (emp != 0 && emp != 3 && emp != 6 && emp != 9 && emp != 13
		&& emp != 17 && emp != 21
		&& emp != 24 && emp != 27 && emp != 30 && emp != 33)
		ft_exit(garbage, "Error");
	if (emp == 0 || emp == 6)
		ft_rotate(all->a);
	if (emp == 3 || emp == 6)
		ft_rotate(all->b);
	if (emp == 9 || emp == 17)
		ft_rotate_reverse(all->a);
	if (emp == 13 || emp == 17)
		ft_rotate_reverse(all->b);
	if (emp == 21)
		ft_push(all->b, all->a, garbage);
	if (emp == 24)
		ft_push(all->a, all->b, garbage);
	if (emp == 27 || emp == 33)
		ft_swap(all->a);
	if (emp == 30 || emp == 33)
		ft_swap(all->b);
}

char	*ft_space(char *str, t_all *all, t_pos *garbage)
{
	char	*ret;
	int		i;

	i = 0;
	if (ft_strlen(str) != 3 && (ft_strlen(str) != 4))
		ft_exit(garbage, "Error");
	ret = ft_malloc(sizeof(char *) * (ft_strlen(str) + 3), all->free);
	if (ret == 0)
		ft_exit(garbage, "Error");
	ret[i++] = ' ';
	ret[i++] = str[0];
	ret[i++] = str[1];
	if (ft_strlen(str) == 4)
		ret[i++] = str[2];
	ret[i++] = ' ';
	ret[i++] = 0;
	return (ret);
}

int	ft_checker(char *liste, t_pos *garbage)
{
	char	*str;
	t_all	*all;
	char	*allinstruction;

	allinstruction = " ra rb rr rra rrb rrr pa pb sa sb ss ";
	all = 0;
	all = ft_init(liste, garbage);
	if (all == 0 || ft_checkall(all) == 1)
		ft_exit(garbage, "Error");
	str = get_next_line(0, garbage);
	while (str != 0)
	{
		ft_fonction_tab(ft_strstr(allinstruction,
				ft_space(str, all, garbage)), all, garbage);
		str = get_next_line(0, garbage);
	}
	if (ft_correct(all) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pos	*garbage;

	if (argc != 2)
		ft_exit(0, 0);
	if (ft_test(argv[1]) == 1 || ft_atoitest(argv[1]))
		ft_exit(0, "Error");
	garbage = ft_setpos(0);
	if (ft_checker(argv[1], garbage) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_exit(garbage, 0);
}
