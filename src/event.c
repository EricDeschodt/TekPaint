/*
** EPITECH PROJECT, 2022
**
** TekPaint
**
*/

#include "tek_event.h"


void	event_handler(t_tekpaint *tekpaint)
{
  while (sfRenderWindow_pollEvent(tekpaint->window, &tekpaint->event))
    {
      if (tekpaint->event.type == sfEvtClosed)
	window_close(tekpaint->window);
    }
}
