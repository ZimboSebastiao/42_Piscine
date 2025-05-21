/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:29:37 by zimbo             #+#    #+#             */
/*   Updated: 2025/05/21 06:37:17 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

int main()
{
	ft_putnbr(836);
	write(1, "\n", 1);
	return (0);
}

void	ft_putnbr(int nb)
{
	char	c;

		if (nb == -2147483648)
		{
			write (1, "-2147483648", 11);
			return;
		}

		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
		}
		c = nb % 10 + '0';
		write(1, &c, 1);

}
