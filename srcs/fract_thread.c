/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 20:40:25 by aledru            #+#    #+#             */
/*   Updated: 2018/01/29 12:41:38 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract_thread		*create_fract_thread(t_thread_p *thread, t_fractol *fract,
	int x, int y)
{
	t_fract_thread	*fract_thread;

	if (!(fract_thread = (t_fract_thread*)ft_memalloc(sizeof(t_fract_thread))))
		malloc_error();
	fract_thread->thread = thread;
	fract_thread->fract = fract;
	fract_thread->coord = create_point(x, y);
	return (fract_thread);
}

void				free_fract_thread(t_fract_thread *f_t)
{
	ft_memdel((void*)&f_t->coord);
	ft_memdel((void*)&f_t);
}
