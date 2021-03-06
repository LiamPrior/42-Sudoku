/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 23:18:05 by bvautour          #+#    #+#             */
/*   Updated: 2017/11/27 16:29:56 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col(char **argv, int pos, char number)
{
	int k;

	k = 0;
	while (k < 9)
	{
		if (argv[k][pos % 9] == number)
			return (0);
		k++;
	}
	return (1);
}

int	check_lin(char **argv, int pos, char number)
{
	int k;

	k = 0;
	while (k < 9)
	{
		if (argv[pos / 9][k] == number)
			return (0);
		k++;
	}
	return (1);
}

int	check_squ(char **argv, int pos, char number)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (argv[(((pos / 9) / 3) * 3) + i][(((pos % 9) / 3) * 3) + j] ==
					number)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_number_in_pos(char **argv, int pos, char number)
{
	if (check_col(argv, pos, number) && check_lin(argv, pos, number) &&
			check_squ(argv, pos, number))
		return (1);
	return (0);
}
