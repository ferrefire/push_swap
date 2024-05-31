/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 16:36:52 by ferre         #+#    #+#                 */
/*   Updated: 2024/05/20 20:12:37 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*last;
	t_list	*lastminone;
	int		size;

	size = ft_lstsize(*stack);
	if (size < 2)
		return ;
	last = ft_lstlast(*stack);
	lastminone = get_node(*stack, -2);
	get_node(*stack, -3)->next = last;
	last->next = lastminone;
	lastminone->next = NULL;
	if (size == 2)
		*stack = last;
}

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*last;

	if (ft_lstsize(*stack_1) == 0)
		return ;
	last = ft_lstlast(*stack_1);
	if (ft_lstsize(*stack_2) == 0)
		*stack_2 = last;
	else
		ft_lstlast(*stack_2)->next = last;
	if (ft_lstsize(*stack_1) == 1)
		*stack_1 = NULL;
	else
		get_node(*stack_1, -2)->next = NULL;
}

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*lastminone;

	last = ft_lstlast(*stack);
	lastminone = get_node(*stack, -2);
	last->next = *stack;
	lastminone->next = NULL;
	*stack = last;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;

	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	op(int operation, int stack, t_vars *vars)
{
	if (operation == SWAP && ft_printf("s") && (stack == A || stack == AB))
		swap(&vars->a);
	if (operation == SWAP && (stack == B || (stack == AB && ft_printf("s"))))
		swap(&vars->b);
	if (operation == PUSH && ft_printf("p") && (stack == A))
		push(&vars->b, &vars->a);
	if (operation == PUSH && (stack == B))
		push(&vars->a, &vars->b);
	if (operation == ROTATE && ft_printf("r") && (stack == A || stack == AB))
		rotate(&vars->a);
	if (operation == ROTATE && (stack == B || (stack == AB && ft_printf("r"))))
		rotate(&vars->b);
	if (operation == REVERSE_ROTATE && ft_printf("rr")
		&& (stack == A || stack == AB))
		reverse_rotate(&vars->a);
	if (operation == REVERSE_ROTATE
		&& (stack == B || (stack == AB && ft_printf("r"))))
		reverse_rotate(&vars->b);
	if ((stack == A && ft_printf("a")) || (stack == B && ft_printf("b")) || 1)
		ft_printf("\n");
	vars->operations++;
}
