/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:55:01 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/25 07:46:43 by zimbo            ###   ########.fr       */
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

	while (str[i] != '\0')
	{

		write(1, &str[i], 1);
		i++;
	}
}
