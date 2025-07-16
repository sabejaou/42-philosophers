/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triche.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:01 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 13:45:13 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	ft_doubleunlock(t_env *table)
{
	pthread_mutex_unlock(table->mphilo->forkr);
	pthread_mutex_unlock(table->mphilo->forkl);
}

void	ft_sleep(int ms, t_env *table)
{
	gettimeofday(&table->mphilo->stime, NULL);
	while (time_ms(&table->mphilo->stime,
			&table->mphilo->end) <= (unsigned long)ms && !*table->dead)
	{
		usleep(10);
		ft_isdying(table);
	}
}

void	ft_triche(t_env *table, int *event)
{
	if (*event == 1)
	{
		gettimeofday(&table->mphilo->etime, NULL);
		table->mphilo->phect++;
		printf("%lli %i is eating\n", \
			time_ms(&table->start, &table->mphilo->end), table->mphilo->pos);
	}
	else if (*event == 3)
	{
		printf("%lli %i is thinking\n", time_ms(&table->start, \
			&table->mphilo->end), table->mphilo->pos);
		table->mphilo->hthinked = 1;
		table->mphilo->hungry = 1;
	}
	else if (*event == 4)
	{
		*table->dead = 1;
		printf("%lli %i died\n", time_ms(&table->start, \
			&table->mphilo->end), table->mphilo->pos);
	}
}

void	ft_triche2(t_env *table)
{
	*table->mphilo->left = 0;
	table->mphilo->myforkl = 1;
	ft_writertn(table, FRK);
	*table->mphilo->right = 0;
	table->mphilo->myforkr = 1;
	ft_writertn(table, FRK);
}

void	ft_triche3(t_env *table)
{
	table->mphilo->hthinked = 0;
	ft_writertn(table, EAT);
	*table->mphilo->left = 1;
	table->mphilo->myforkl = 0;
	*table->mphilo->right = 1;
	table->mphilo->myforkr = 0;
	pthread_mutex_unlock(table->mphilo->forkr);
	pthread_mutex_unlock(table->mphilo->forkl);
	ft_writertn(table, SLEEP);
}
