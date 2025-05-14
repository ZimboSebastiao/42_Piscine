/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:53:25 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/14 03:03:38 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

int main(void)
{
	ft_print_alphabet();
	write(1, "\n", 1);
	return (0);
}

void	ft_print_alphabet(void)
{
	int	i;

	i = 0 + 'a';

    while (i >= 'a' && i <= 'z')
    {
        write(1, &i, 1);
		i++;
    }
}
