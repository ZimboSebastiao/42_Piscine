/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:11:45 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/23 10:33:58 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strlen(char *str);

// int	main()
// {
// 	printf("%d\n", ft_strlen("Lorem ipsum"));
// 	return (0);
// }

int	ft_strlen(char *str)
{
	int i;

	i = 0;

	while (i < str[i] || str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// por que que com o write eu não consigo ver a quantidade de string e só consigo imprimir a string em si? 