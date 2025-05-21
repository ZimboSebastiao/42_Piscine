/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:55:57 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/21 07:01:40 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);



// int main()
// {
// 	ft_print_combn(9);
// 	return (0);
// }

void	ft_print_combn(int n)
{
	int comb[10];
	int i;

	if (n < 1 || n > 9)
		return;

	// Inicializa a combinação com os menores dígitos
	i = 0;
	while (i < n)
	{
		comb[i] = i;
		i++;
	}

	while (1)
	{
		// Escreve os dígitos atuais
		i = 0;
		while (i < n)
		{
			char c = comb[i] + '0';
			write(1, &c, 1);
			i++;
		}

		// Verifica se é a última combinação
		if (comb[0] == 10 - n)
			break;

		write(1, ", ", 2);

		// Incrementa a combinação
		i = n - 1;
		while (i >= 0 && comb[i] == 9 - (n - 1 - i))
			i--;

		comb[i]++;
		while (++i < n)
			comb[i] = comb[i - 1] + 1;
	}
}

