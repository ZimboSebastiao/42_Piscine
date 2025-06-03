/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:36:01 by zimbo             #+#    #+#             */
/*   Updated: 2025/06/03 12:22:40 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main()
{
	int i = 0;
	int	size = 9;
	int array[] = {3,1,2,8,9,5,6,7,0};
	ft_sort_int_tab(array, size);

	while(i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
	return (0);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int temp;

	i = 0;
	temp = 0;
	
	while(i < size - 1)
	{
		j  = 0;
		while (j < size - i - 1)
		{
			if(tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}

}