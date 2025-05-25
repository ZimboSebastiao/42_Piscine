/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:35:50 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/23 09:46:08 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_swap(int *a, int *b);

// int main()
// {
// 	int a = 2;
// 	int b = 4;
// 	ft_swap(&a, &b);
// 	printf("a = %d\nb = %d\n", a, b);
// 	return (0);
// }

void	ft_swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
// Nessa parte do código "ft_swap(&a, &b);", por que que passar simplesmente os endereços das variaveis deu certo? tipo, a função não está aguardando por um ponteiro? o endereço serviu como ponteiro?