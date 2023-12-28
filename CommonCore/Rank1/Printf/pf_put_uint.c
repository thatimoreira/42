/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:30:01 by tsoares-          #+#    #+#             */
/*   Updated: 2023/12/28 16:32:43 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pf_put_uint(unsigned int num)
{
}

int	main(void)
{
	unsigned int	n;
	int		count;

	n = 56;
	count = 0;
	count = pf_put_uint(n);
	printf("n = %u\n", count);
	return (0);
}
