/*
** EPITECH PROJECT, 2022
**
** TekPaint
**
*/

#include "tekpaint.h"

void	tekpaint_init(t_tekpaint *tekpaint)
{
  tekpaint->width = 1280;
  tekpaint->height = 720;
  tekpaint->border = 5;
  if ((tekpaint->window =
       window_init("tekpaint", tekpaint->width, tekpaint->height, 32)) != NULL)
    sfRenderWindow_setFramerateLimit(tekpaint->window, 60);
  tekpaint->ui =
    t_canvas_create(tekpaint->width,
		    tekpaint->height,
		    sfColor_fromRGB(0xBD,0xBD,0xBD));
  tekpaint_ui(tekpaint);
  tekpaint->button = t_button_create((sfIntRect){100, 150, 200, 50}, NULL, NULL);  
}


void	tekpaint_ui(t_tekpaint *tekpaint)
{
  int	i = 0;
  int	j = 0;

  while (i < tekpaint->width)
    {
      j = 0;
      while (j < tekpaint->height)
	{
	  if (i < tekpaint->border || j < tekpaint->border
	      || i > tekpaint->width - tekpaint->border
	      || j > tekpaint->height - tekpaint->border
	      || (j > 30 + tekpaint->border && j < 30 + 2 * tekpaint->border))
	    t_canvas_putpixel(tekpaint->ui, i, j, sfWhite);
	  j++;
	}
      i++;
    }
}

void	tekpaint_update(t_tekpaint *tekpaint)
{
  event_handler(tekpaint->window, &tekpaint->event);
  t_canvas_draw(tekpaint->window, tekpaint->ui, 0, 0);
  t_button_hover(tekpaint->button, tekpaint->window);
  t_button_draw(tekpaint->button, tekpaint->window);

}
