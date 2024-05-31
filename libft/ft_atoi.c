/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:25:28 by fmolenbe      #+#    #+#                 */
/*   Updated: 2024/05/20 16:25:36 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *str)
{
	long	total;
	int		i;
	int		m;

	total = 0;
	i = -1;
	m = 1;
	while (str[++i])
		if (!((str[i] > 8 && str[i] < 14) || str[i] == 32))
			break ;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -1;
		else
			m = 1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		total *= 10;
		total += (str[i] - '0');
		i++;
	}
	return (total * m);
}
