/*
** EPITECH PROJECT, 2022
**
** TekPaint
**
*/

#include "tekpaint.h"

void event_handler(sfRenderWindow *window, sfEvent *event)
{
  while (sfRenderWindow_pollEvent(window, event))
    {
      if (event->type == sfEvtClosed)
	window_close(window);
    }
}
