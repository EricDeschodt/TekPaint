/*
** EPITECH PROJECT, 2022
**
** TekPaint
**
*/

#include "tekpaint.h"

sfRenderWindow		*window_init(char *name,
				     int width,
				     int height,
				     int color)
{
  sfVideoMode		mode = {width, height, color};
  
  return (sfRenderWindow_create(mode, name, sfResize | sfClose, NULL));
}

void			window_close(sfRenderWindow *window)
{
  sfRenderWindow_close(window);
}
  
void			window_destroy(sfRenderWindow *window)
{
  sfRenderWindow_destroy(window);
}
