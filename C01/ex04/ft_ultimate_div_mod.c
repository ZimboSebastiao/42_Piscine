/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:47:32 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/23 09:53:55 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

// int main()
// {
// 	int a = 10;
// 	int b = 6;
	
// 	ft_ultimate_div_mod(&a, &b);
// 	printf("a = %d\nb = %d\n", a, b);
// 	return (0);
// }

void	ft_ultimate_div_mod(int *a, int *b)
{
	int c;
	int d;

	c = *a;
	d = *b;

	*a = (c / d);
	*b = (c % d);
}