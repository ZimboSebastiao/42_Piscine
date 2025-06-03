/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:34:32 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/26 10:32:28 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

// int main()
// {
	
// 	int i = 0;
// 	int size = 7;
// 	int tab[] = {1, 2, 3, 4, 5, 6, 7};
	
// 	ft_rev_int_tab(tab, size);
// 	while (i < size)
// 	{
// 		printf("%d", tab[i]);
// 		i++;

// 	}

	
// 	return (0);
// }

void	ft_rev_int_tab(int *tab, int size)
{

	int i;
	int j;
	int temp;

	i = 0;
	j = size - 1;

	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;

		i++;
		j--;
	}
}


