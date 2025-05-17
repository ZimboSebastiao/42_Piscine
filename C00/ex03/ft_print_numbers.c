/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:38:26 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/17 00:30:37 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);

int main(void)
{
	ft_print_numbers();
	write(1, "\n", 1);
	return (0);
}

void	ft_print_numbers(void)
{
	char i;

	i = '0';

	while (i <= '9')
	{
		write(1, &i, 1);
		i++;
	}
}
