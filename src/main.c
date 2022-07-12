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

  ;tekpaint_init(&tekpaint);
  while (sfRenderWindow_isOpen(tekpaint.window))
    {
      tekpaint_update(&tekpaint);
      sfRenderWindow_display(tekpaint.window);
    }
  window_close(tekpaint.window);
  return EXIT_SUCCESS;
}
