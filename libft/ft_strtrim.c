/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 15:46:49 by fmolenbe      #+#    #+#                 */
/*   Updated: 2023/08/28 16:21:10 by fmolenbe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	a[100000];
	int		i;
	int		j;
	int		k;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (s1[j] && ft_strchr(set, s1[j]))
		j--;
	i--;
	j++;
	k = -1;
	while (s1[++i] && i < j)
		a[++k] = s1[i];
	a[++k] = '\0';
	p = ft_strdup(a);
	return (p);
}
