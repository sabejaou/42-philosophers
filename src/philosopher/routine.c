/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:01 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/10 13:45:13 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	ft_isdying(t_env *table)
{
	if (time_ms(&table->mphilo->etime, &table->mphilo->end) \
		> (unsigned long)table->set->ttd)
		ft_writertn(table, DIE);
	if (time_ms(&table->mphilo->etime, &table->mphilo->end)
		>= (unsigned long)table->set->ttd / 2)
		table->mphilo->hungry = 1;
	usleep(400);
}

void	ft_wait(t_env *table, int event)
{
	if (event == 1)
		ft_sleep(table->set->tte, table);
	else if (event == 2)
	{
		ft_sleep(table->set->tts, table);
		ft_writertn(table, THINK);
	}
	else if (event == 3)
		table->mphilo->hthinked = 1;
}

void	ft_writertn(t_env *table, int event)
{
	pthread_mutex_lock(table->write);
	if (!*table->dead)
	{
		if (event == 5)
		{
			printf("%lli %i has taken a fork\n", time_ms(&table->start, \
				&table->mphilo->end), table->mphilo->pos);
		}
		else if (event == 2)
		{
			gettimeofday(&table->mphilo->stime, NULL);
			printf("%lli %i is sleeping\n", time_ms(&table->start, \
				&table->mphilo->end), table->mphilo->pos);
		}
		else if (event == 3 || event == 4 || event == 1)
			ft_triche(table, &event);
		pthread_mutex_unlock(table->write);
		if (event >= 1 && event < 3)
			ft_wait(table, event);
	}
	else
		pthread_mutex_unlock(table->write);
}

void	ft_eat(t_env *table)
{
	if (table->mphilo->forkr != table->mphilo->forkl)
	{
		pthread_mutex_lock(table->mphilo->forkr);
		pthread_mutex_lock(table->mphilo->forkl);
		if (table->mphilo->left == table->mphilo->right
			&& !table->mphilo->myforkl)
		{
			*table->mphilo->left = 0;
			table->mphilo->myforkl = 1;
			ft_writertn(table, FRK);
		}
		else if (table->mphilo->left && *table->mphilo->right)
		{
			ft_isdying(table);
			if (!*table->dead && *table->mphilo->left)
				ft_triche2(table);
			if (!*table->dead && table->mphilo->right)
				ft_triche3(table);
			else
				ft_doubleunlock(table);
		}
		if (!table->mphilo->hthinked)
			ft_writertn(table, THINK);
	}
}

void	*ft_routine(void *tmp)
{
	t_philo			*tpm;
	t_env			*table;

	tpm = (t_philo *)tmp;
	table = tpm->table;
	table->mphilo = tpm;
	while (1)
	{
		ft_isdying(table);
		if (*table->dead)
			return (NULL);
		else if (!*table->dead && (table->mphilo->hungry
				|| table->mphilo->hthinked))
			ft_eat(table);
		else if (!*table->dead && !table->mphilo->hthinked)
			ft_writertn(table, THINK);
		ft_isdying(table);
		if (table->set->ect && table->mphilo->phect >= table->set->ect)
			return (NULL);
	}
	return (NULL);
}
