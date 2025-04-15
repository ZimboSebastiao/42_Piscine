/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:38:26 by zimbo             #+#    #+#             */
/*   Updated: 2025/04/15 17:43:02 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	int i;

	i = 0 + '0';

	while (i <= '9')
	{
		write(1, &i, 1);
		i++;
	}
}

// int main(void)
// {
// 	ft_print_numbers();
// 	return (0);
// }