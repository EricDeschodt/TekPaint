/*
** EPITECH PROJECT, 2022
**
** TekPaint
**
*/

#include "tekpaint.h"

t_canvas	*t_canvas_create(int width, int height, sfColor color)
{
  t_canvas	*new_canvas;

  new_canvas = malloc(sizeof(t_canvas));
  new_canvas->sprite = sfSprite_create();
  new_canvas->texture = sfTexture_create(width, height);
  new_canvas->image = sfImage_createFromColor(width, height, color);
  new_canvas->width = width;
  new_canvas->height = height;
  sfTexture_updateFromImage(new_canvas->texture, new_canvas->image, 0, 0);
  sfSprite_setTexture(new_canvas->sprite, new_canvas->texture, sfTrue);
  return (new_canvas);
}

t_canvas        *t_canvas_createFromFile(char *src)
{
    t_canvas    *new_canvas;

    new_canvas = malloc(sizeof(t_canvas));
    new_canvas->sprite = sfSprite_create();
    new_canvas->image = sfImage_createFromFile(src);
    new_canvas->width = sfImage_getSize(new_canvas->image).x;
    new_canvas->height = sfImage_getSize(new_canvas->image).y;
    new_canvas->texture = sfTexture_create(new_canvas->width, new_canvas->height);
    sfTexture_updateFromImage(new_canvas->texture, new_canvas->image, 0, 0);
    sfSprite_setTexture(new_canvas->sprite, new_canvas->texture, sfTrue);
    return (new_canvas);
}

void		t_canvas_draw(sfRenderWindow *window,
			      t_canvas *canvas,
			      int x,
			      int y)
{
  sfVector2f	pos;

  pos.x = x;
  pos.y = y;
  sfTexture_updateFromImage(canvas->texture, canvas->image, 0, 0);
  sfSprite_setPosition(canvas->sprite, pos);
  sfRenderWindow_drawSprite(window, canvas->sprite, NULL);
}
