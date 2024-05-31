/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 17:39:49 by ferre         #+#    #+#                 */
/*   Updated: 2024/05/22 17:24:34 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_node(t_list *lst, int index)
{
	int	i;

	if (!lst)
		return (NULL);
	i = 0;
	if (index < 0)
		index = ft_lstsize(lst) + index;
	while (i < index && lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

int	get_node_val(t_list *lst, int index, int unit)
{
	if (unit == -1)
		return (ft_atoi(get_node(lst, index)->content));
	return (((ft_atoi(get_node(lst, index)->content)) >> unit) & 1);
}

int	is_num(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (i == 0 && *(str + i) == '-')
			i++;
		if (!ft_isdigit(*(str + i)))
			return (0);
		if (ft_atoi(str) > 0 && 0 > __INT_MAX__ - ft_atoi(str))
			return (0);
		if (ft_atoi(str) < 0 && 0 > __INT_MAX__ + ft_atoi(str))
			return (0);
		i++;
	}
	return (1);
}

void	short_sort(t_vars *vars, int argc)
{
	if (stacks_sorted(vars->a, -1))
		return ;
	while (ft_lstsize(vars->a) > argc - 2)
		if (get_node_val(vars->a, -1, -1) < 2)
			op(PUSH, B, vars);
	else
		op(ROTATE, A, vars);
	while (get_node_val(vars->a, 0, -1) != argc - 1)
		op(ROTATE, A, vars);
	if (get_node_val(vars->a, -1, -1) != 2
		&& get_node_val(vars->b, -1, -1) != 1)
		op(SWAP, AB, vars);
	else if (get_node_val(vars->a, -1, -1) != 2)
		op(SWAP, A, vars);
	else if (get_node_val(vars->b, -1, -1) != 1)
		op(SWAP, B, vars);
	op(PUSH, A, vars);
	op(PUSH, A, vars);
}

void	sort(t_vars *vars, int argc)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	if (argc == 1)
		return ;
	if (argc <= 3)
	{
		while (get_node_val(vars->a, 0, -1) != argc - 1)
			op(ROTATE, A, vars);
		if (get_node_val(vars->a, -1, -1) != 0)
			op(SWAP, A, vars);
	}
	else if (argc >= 6)
	{
		while ((argc >> index) != 0)
			++index;
		while (radix_sort(vars, i, argc) == 0 && ++i < index)
			continue ;
	}
	else
		short_sort(vars, argc);
}
