/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 23:19:20 by bvautour          #+#    #+#             */
/*   Updated: 2017/11/27 16:30:00 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

int	resolution_sudoku(char **argv, int pos)
{
	char	number;

	if (pos == 81)
		return (1);
	if (argv[pos / 9][pos % 9] != '.')
		return (resolution_sudoku(argv, pos + 1));
	number = '1';
	while (number <= '9')
	{
		if (check_number_in_pos(argv, pos, number))
		{
			argv[pos / 9][pos % 9] = number;
			if (resolution_sudoku(argv, pos + 1))
				return (1);
			argv[pos / 9][pos % 9] = '.';
		}
		number = number + 1;
	}
	return (0);
}

int	is_valid(int argc, char **argv)
{
	int	pos;
	int	i;

	if (argc != 10)
		return (0);
	pos = 0;
	while (pos <= 80)
	{
		if (((argv[pos / 9][pos % 9] >= '0' &&
						argv[pos / 9][pos % 9] <= '9') ||
					argv[pos / 9][pos % 9] == '.') == 0)
			return (0);
		pos++;
	}
	i = 0;
	while (i < 9)
	{
		if (argv[i][9] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	argv = argv + 1;
	if (is_valid(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (resolution_sudoku(argv, 0) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	resolution_sudoku(argv, 0);
	print_sudoku(argv);
	return (0);
}
