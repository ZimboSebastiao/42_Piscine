/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:27:37 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/18 02:11:59 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

// int main(void)
// {
// 	ft_print_reverse_alphabet();
// 	write(1, "\n", 1);
// 	return (0);
// }

void	ft_print_reverse_alphabet(void)
{
	int i;

	i = 122;

	while (i >= 97)
	{
		write(1, &i, 1);
		i--;
	}
}
