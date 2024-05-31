/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 16:37:01 by ferre         #+#    #+#                 */
/*   Updated: 2024/05/20 19:30:36 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# define AB 0
# define A 1
# define B 2
# define SWAP 0
# define PUSH 1
# define ROTATE 2
# define REVERSE_ROTATE 3

typedef struct s_vars
{
	t_list	*a;
	t_list	*b;
	int		operations;
	int		argc;
}				t_vars;
void			op(int operation, int stack, t_vars *vars);
t_list			*get_node(t_list *lst, int index);
int				get_node_val(t_list *lst, int index, int unit);
void			print_operation(int operation, int stack);
int				stacks_sorted(t_list *lst, int unit);
void			sort(t_vars *vars, int argc);
int				radix_sort(t_vars *vars, int unit, int argc);
int				is_num(const char *str);

#endif