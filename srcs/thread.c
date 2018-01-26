/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:23:16 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 18:11:32 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_thread_p		*create_thread_p(void)
{
	t_thread_p	*thread_p;

	if (!(thread_p = (t_thread_p*)ft_memalloc(sizeof(t_thread_p))))
		malloc_error();
	thread_p->params = create_params(thread_p);
	return (thread_p);
}
