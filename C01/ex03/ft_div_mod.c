/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:26:04 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/25 07:02:43 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

// int	main()
// {

// 	int	*div, *mod;

// 	ft_div_mod(10, 6, div, mod);
// 	printf("Divisão: %d\n Resto: %d\n", *div, *mod);
// 	return (0);
// }

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = (a / b);
	*mod = (a % b);
}