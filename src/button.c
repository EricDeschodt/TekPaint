/*
** EPITECH PROJECT, 2022
**
** TekPaint
**
*/

#include "tek_button.h"

t_button	*t_button_create(sfIntRect hitbox,
				 sfFont *font,
				 void (*fct)(void *))
{
  t_button *new_button = malloc(sizeof(t_button));
  new_button->hitbox = hitbox;
  new_button->text = sfText_create();
  new_button->fct = fct;
  new_button->canvas = t_canvas_create(hitbox.width, hitbox.height, sfRed);
  t_button_set_button_style(new_button,
			    sfWhite,
			    sfColor_fromRGB(0xBD,0xBD,0xBD),
			    sfBlack);
  t_button_set_text(new_button,
		    font,
		    sfBlack,
		    "");
  new_button->is_hover = false;
  return (new_button);
}

void		t_button_set_text(t_button *button,
				  sfFont *font,
				  sfColor color,
				  const char *text)
{
  sfText_setFont(button->text, font);
  sfText_setColor(button->text, color);
  sfText_setString(button->text, text);
}

void		t_button_set_button_style(t_button *button,
					  sfColor main,
					  sfColor hover,
					  sfColor border)
{
  button->main = main;
  button->hover = hover;
  button->border = border;
  t_button_update_state(button);
}

void		t_button_update_state(t_button *button)
{
  int		i = 0;
  int		j = 0;

  while (i < button->hitbox.width)
    {
      j = 0;
      while (j < button->hitbox.height)
	{
	  if (i < 2 || j < 2
	      || i > button->hitbox.width - 3
	      || j > button->hitbox.height - 3)
	    t_canvas_putpixel(button->canvas, i, j, button->border);
	  else
	    t_canvas_putpixel(button->canvas, i, j,
			      button->is_hover == true ?
			      button->hover : button->main);
	  j++;
	}   
      i++;
    }
}

void		t_button_draw(t_button *button, sfRenderWindow *window)
{
  t_canvas_draw(window, button->canvas,
		button->hitbox.left,
		button->hitbox.top);
}

void		t_button_hover(t_button *button, sfRenderWindow *window)
{
  sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
  if (sfIntRect_contains(&button->hitbox, mouse.x, mouse.y))
    {
      if (button->is_hover == false)
	{
	  button->is_hover = true;
	  t_button_update_state(button);
	  printf("IN\n");
	}
    }
  else
    {
      if (button->is_hover == true)
	{
	  button->is_hover = false;
	  t_button_update_state(button);
      	  printf("OUT\n");
	}
    }
}
