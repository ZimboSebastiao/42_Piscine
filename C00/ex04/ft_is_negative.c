/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:49:13 by zimbo             #+#    #+#             */
/*   Updated: 2025/04/15 18:01:42 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	if ( n < 0)
	{
		write(1, "N", 1);
	}
	else
	{
		write(1, "P", 1);
	}
}

// int main()
// {
// 	ft_is_negative(0);
// 	write(1, "\n", 1);
// 	return (0);
// }