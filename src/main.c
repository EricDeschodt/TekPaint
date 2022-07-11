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

  if ((window = window_init("tekpaint", 1280, 720, 32)) == NULL)
    return EXIT_FAILURE;
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_display(window);
    }
  window_close(window);
  return EXIT_SUCCESS;
}
