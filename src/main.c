/*
** EPITECH PROJECT, 2022
**
** TekPaint
**
*/

#include "tekpaint.h"

int			main()
{
  sfRenderWindow	*window;
  sfEvent		event;
  t_canvas		*canvas;

  canvas = t_canvas_createFromFile("res/doge.png");
  if ((window = window_init("tekpaint", 1280, 720, 32)) == NULL)
    return EXIT_FAILURE;
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfWhite);
      event_handler(window, &event);
      t_canvas_draw(window, canvas, 100, 100);
      sfRenderWindow_display(window);
    }
  window_close(window);
  return EXIT_SUCCESS;
}
