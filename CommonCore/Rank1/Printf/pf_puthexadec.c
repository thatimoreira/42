/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthexadec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 06:10:20 by tsoares-          #+#    #+#             */
/*   Updated: 2023/12/28 07:04:57 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pf_puthexadec(unsigned int num, format)
{
	int	i;
	int	remainder;
	int     args_amount;
	char	rev_num[20];

	i = 0;
	remainder = 0;
	args_amount = 0;
	if (num == 0)
		args_amount = write(1, "0", 1);
	else
	{
		while (num)
		{
			num /= 16;
			remainder = num % 16;
			if (remainder <= 9)
				num_rev[i] = remainder;
			else
			{
				if (format == 'x')
					num_rev[i++] = remainder - 10 + 'a';
				if (format == 'X')
					num_rev[i++] = remainder - 10 + 'A';
			}
	}
	return (args_amount);
}
