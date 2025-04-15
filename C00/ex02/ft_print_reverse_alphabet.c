/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:27:37 by zimbo             #+#    #+#             */
/*   Updated: 2025/04/15 17:36:33 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

void	ft_print_reverse_alphabet(void)
{
	int i;

	i = 0 + 'z';

	while (i >= 'a')
	{
		write(1, &i, 1);
		i--;
	}
}

// int main(void)
// {
// 	ft_print_reverse_alphabet();
// 	return (0);
// }