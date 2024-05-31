/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 16:36:57 by ferre         #+#    #+#                 */
/*   Updated: 2024/05/22 17:22:51 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	print(void	*str)
//{
//	ft_printf("%s ", str);
//}
//void	print_stacks(t_vars *vars)
//{
//	ft_printf("a: ");
//	ft_lstiter(vars->a, print);
//	ft_printf("\nb: ");
//	ft_lstiter(vars->b, print);
//	ft_printf("\n");
//}

int	clean(t_vars *vars, char **args, int argc, int i)
{
	if (vars)
	{
		ft_lstclear(&(vars->a), free);
		ft_lstclear(&(vars->b), free);
		free(vars);
	}
	if (argc == 2 && args)
	{
		while (--i >= 0)
			free(args[i]);
		free(args);
	}
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	stacks_sorted(t_list *lst, int unit)
{
	int	num;
	int	index;

	num = 0;
	index = ft_lstsize(lst);
	while (--index >= 0)
	{
		if (unit == -1)
		{
			if (get_node_val(lst, index, -1) < num)
				return (0);
			num = get_node_val(lst, index, -1);
		}
		else
		{
			if (get_node_val(lst, index, unit) != 1)
				return (0);
		}
	}
	return (1);
}

int	radix_sort(t_vars *vars, int unit, int argc)
{
	if (stacks_sorted(vars->a, -1))
		return (1);
	while (--argc >= 0)
	{
		if (get_node_val(vars->a, -1, unit) == 0)
			op(PUSH, B, vars);
		else
			op(ROTATE, A, vars);
	}
	while (ft_lstsize(vars->b) > 0)
		op(PUSH, A, vars);
	return (0);
}

int	convert_stack(t_vars *vars, int argc, char **args)
{
	int	i;
	int	j;
	int	index;
	int	duplicate;

	i = argc;
	vars->operations = 0;
	while (--i >= 0)
	{
		if (!is_num(args[i]))
			return (0);
		j = -1;
		index = 0;
		duplicate = 0;
		while (++j < argc)
			if (ft_atoi(args[j]) < ft_atoi(args[i]))
				index++;
		else if (ft_atoi(args[j]) == ft_atoi(args[i]) && duplicate++ > 0)
			return (0);
		if (i == argc - 1)
			vars->a = ft_lstnew(ft_itoa(index));
		else
			ft_lstadd_back(&vars->a, ft_lstnew(ft_itoa(index)));
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	char	**args;
	int		i;

	if (argc < 2)
		return (1);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = ++argv;
	i = 0;
	while (*(args + i))
		i++;
	if (i == 0)
		return (clean(NULL, args, argc, i));
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (clean(vars, args, argc, i));
	if (!convert_stack(vars, i, args))
		ft_printf("Error\n");
	else
		sort(vars, i);
	return (clean(vars, args, argc, i));
}
//print_stacks(vars);
//ft_printf("Solved %d in: %d operations!\n", 
//    stacks_sorted(vars->a, -1), vars->operations);