/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:52:31 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/12 19:13:21 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_move
{
	struct s_list	*p;
	int				movenbr;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rrs;
	int				rs;
	int				upup;
	int				downdown;
	int				updown;
	int				downup;
}	t_move;

typedef struct s_all
{
	struct s_pos	*a;
	struct s_pos	*b;
	struct s_pos	*free;
}	t_all;

typedef void	(*t_tab)(t_all *all);

int		ft_atoitest(char *str);
void	push_swap(char *str, t_pos *free);
t_all	*ft_init(char *str, t_pos *free);
void	ft_push(t_pos *from, t_pos *to, t_pos *free);
void	ft_pb(t_all *all);
void	ft_pa(t_all *all);
void	ft_ps(t_all *all);
t_all	*ft_setlist(char *str, t_all *all);
void	*ft_free(t_all *all);
int		ft_correct(t_all *all);
void	ft_threesort(t_all *all);
void	ft_transfer(t_all *all);
int		ft_moverra(t_all *all, t_list *list);
int		ft_movera(t_all *all, t_list *list);
t_move	*ft_moveclean(t_move *move);
t_move	*ft_bestmove(t_all *all, t_list *list);
t_move	*ft_best(t_all *all);
int		ft_movebest(t_all *all, t_move *move);
void	ft_aurelesort(t_all *all);
void	ft_rra(t_all *all);
void	ft_rrb(t_all *all);
void	ft_rrs(t_all *all);
void	ft_rotate(t_pos *pos);
void	ft_rotate_reverse(t_pos *pos);
void	ft_ra(t_all *all);
void	ft_rb(t_all *all);
void	ft_rs(t_all *all);
void	ft_swap(t_pos *pos);
void	ft_sa(t_all *all);
void	ft_ss(t_all *all);
void	ft_sb(t_all *all);
int		ft_checkall(t_all *all);
int		ft_test(char *str);

#endif
