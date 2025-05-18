/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:52:37 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/18 03:28:30 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

int main(void)
{
	ft_print_comb2();
	write(1, "\n", 1);
	return (0);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			char	i1;
			char	i2;
			char	j1;
			char	j2;

			i1 = i / 10 + '0';
			i2 = i % 10 + '0';
			j1 = j / 10 + '0';
			j2 = j % 10 + '0';

			write(1, &i1, 1);
			write(1, &i2, 1);
			write(1, " ", 1);
			write(1, &j1, 1);
			write(1, &j2, 1);

			if (!(i == 98 && j == 99 ))
			{
				write (1, ", ", 2);
			}
			j++;
		}
		i++;
	}
}
