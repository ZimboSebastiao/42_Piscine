/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:34:32 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/23 11:10:00 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int main()
{
	int i = 0;
	int size = 6;
	int tab[] = {1, 3,4,5,6,8};
	ft_rev_int_tab(tab, size);

	while(i <= size)
	{
		printf("%d", tab[i]);
		printf("\n");
		i++;
	}

	return (0);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	while(i <= tab[size])
	{
		j = 0;
		while(j <= tab[size])
		{
			tab[size] = tab[size];
			j--;
		}
		i++;
	}
}