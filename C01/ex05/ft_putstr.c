/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:55:01 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/23 10:18:19 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

// int	main()
// {

// 	ft_putstr("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.");
// 	write(1, "\n", 1);
// 	return (0);
// }

void	ft_putstr(char *str)
{
	int i;
	
	i = 0;

	while (i <= str[i] || str[i] != '\0')
	{

		write(1, &str[i], 1);
		i++;
	}
}

// Nesse trecho do código "write(1, &str[i], 1);" o endereço que estamos a passar é da variavel "i" ou do ponteiro? porque se iterassemos usando o próprio ponteiro "while(str)", poderiamos simplesmente fazer desse jeito "write(1, str, 1);", sem usar o caracterer "&". Por que?
// Por que a variavel i não consegue ir até ao final da string str sem especificarmos que ela precisa ir até encontrar o "\n"? por que assim não funciona com string longas? ex: "while (i <= str[i])"?