/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 20:40:25 by aledru            #+#    #+#             */
/*   Updated: 2018/01/26 21:25:29 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract_thread		*create_fract_thread(t_thread_p *thread, t_fractol *fract)
{
	t_fract_thread	*fract_thread;

	if (!(fract_thread = (t_fract_thread*)ft_memalloc(sizeof(t_fract_thread))))
			malloc_error();
	fract_thread->thread = thread;
	fract_thread->fract = fract;
	fract_thread->start_x = 0;
	return (fract_thread);
}
