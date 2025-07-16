/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:01 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 13:45:13 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	ft_errac(int ac)
{
	if (ac >= 6)
	{
		dprintf(2, "ERROR(1B)\nToo much Args\n");
		exit(-1);
	}
	dprintf(2, "ERROR(1A)\nMissing Arg(s)\n");
	if (ac <= 4)
		dprintf(2, " Time to sleep");
	if (ac <= 3)
		dprintf(2, ", Time to eat");
	if (ac <= 2)
		dprintf(2, ", Time to die");
	if (ac == 1)
		dprintf(2, ", Number of philosophers");
	write(2, "\n", 1);
	exit(-1);
}

void	ft_erravdigit(int avi, int bool)
{
	if (!bool)
		dprintf(2, "ERROR(2A)\nNot Digit Arg\n");
	else
		dprintf(2, "ERROR(2B)\nNegative Arg\n");
	if (avi == 1)
		dprintf(2, " ARG 1 : Number of philosophers");
	if (avi == 2)
		dprintf(2, " ARG 2 : Time to die");
	if (avi == 3)
		dprintf(2, " ARG 3 : Time to eat");
	if (avi == 4)
		dprintf(2, " ARG 4 : Time to die");
	if (avi == 5)
		dprintf(2, " ARG 5 : number_of_times_philosopher_eat");
	write(2, "\n", 1);
	exit(-2);
}

void	ft_erravnull(int avi)
{
	dprintf(2, "ERROR(3)\nNULL Arg\n");
	if (avi == 1)
		dprintf(2, " ARG 1 : Number of philosophers");
	if (avi == 2)
		dprintf(2, " ARG 2 : Time to die");
	if (avi == 3)
		dprintf(2, " ARG 3 : Time to eat");
	if (avi == 4)
		dprintf(2, " ARG 4 : Time to die");
	if (avi == 5)
		dprintf(2, " ARG 5 : number_of_times_philosopher_eat");
	write(2, "\n", 1);
	exit(-3);
}

void	ft_verifav(int ac, char **av)
{
	int		i;
	int		j;

	if (ac <= 4 || ac > 6)
		ft_errac(ac);
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (!av[i][j])
			ft_erravnull(i);
		while (av[i][j])
		{
			if (av[i][j] && (!ft_isdigit(av[i][j]) && av[i][0] != '+'
			&& av[i][0] != '-'))
				ft_erravdigit(i, 0);
			if (av[i][0] == '-')
				ft_erravdigit(i, 1);
			j++;
		}
		i++;
	}
}

t_params	*ft_parse(int ac, char **av)
{
	t_params	*prm;

	ft_verifav(ac, av);
	prm = malloc(sizeof(t_params));
	prm->nph = atoi(av[1]);
	prm->ttd = atoi(av[2]);
	prm->tte = atoi(av[3]);
	prm->tts = atoi(av[4]);
	if (ac == 6)
		prm->ect = atoi(av[5]);
	else
		prm->ect = 0;
	return (prm);
}
