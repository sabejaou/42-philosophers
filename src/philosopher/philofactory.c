/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philofactory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:01 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 13:45:13 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	ft_philoassembly(t_env *table, int i, int nph)
{
	while (i < nph)
	{
		(table->philo[i])->pos = i + 1;
		*(table->philo[i])->left = 1;
		table->philo[i]->phect = 0;
		if (i == nph - 1)
		{
			(table->philo[i])->right = (table->philo[0])->left;
			(table->philo[i])->forkr = (table->philo[0])->forkl;
		}
		else
		{
			(table->philo[i])->right = table->philo[i + 1]->left;
			(table->philo[i])->forkr = table->philo[i + 1]->forkl;
		}
		if (i % 2 == 0)
			(table->philo[i])->hungry = 1;
		else
			(table->philo[i])->hungry = 0;
		table->philo[i]->hthinked = 0;
		i++;
	}
}

void	ft_philofactory(int nph, t_env *table)
{
	int		i;

	i = 0;
	table->philo = malloc(sizeof(t_philo *) * nph);
	table->dead = malloc(sizeof(int));
	*table->dead = 0;
	while (i < nph)
	{
		(table->philo[i]) = malloc(sizeof(t_philo));
		table->philo[i]->left = malloc(sizeof(int));
		table->philo[i]->forkl = malloc(sizeof(pthread_mutex_t));
		table->philo[i]->table = malloc(sizeof(t_env));
		i++;
	}
	i = 0;
	ft_philoassembly(table, i, nph);
}
