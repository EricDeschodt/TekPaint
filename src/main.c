/*
** EPITECH PROJECT, 2022
**
** TekPaint
**
*/

#include "tekpaint.h"

int			main()
{
  t_tekpaint		tekpaint;

  tekpaint_init(&tekpaint);
  while (sfRenderWindow_isOpen(tekpaint.window))
    {
      event_handler(tekpaint.window, &tekpaint.event);
      t_canvas_draw(tekpaint.window, tekpaint.ui, 0, 0);
      sfRenderWindow_display(tekpaint.window);
    }
  window_close(tekpaint.window);
  return EXIT_SUCCESS;
}
