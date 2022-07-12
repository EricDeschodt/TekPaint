/*
** EPITECH PROJECT, 2022
**
** Tekpaint
**
*/

#ifndef		TEK_CANVAS_H_
# define	TEK_CANVAS_H_

# include	<SFML/Audio.h>
# include	<SFML/Graphics.h>
# include	<SFML/System.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<math.h>
# include	<stdio.h>

typedef struct	s_canvas {
  int		width;
  int		height;
  sfSprite	*sprite;
  sfTexture	*texture;
  sfImage	*image;
}t_canvas;

t_canvas	*t_canvas_create(int, int, sfColor);
t_canvas	*t_canvas_create_from_file(char *);
void		t_canvas_draw(sfRenderWindow *, t_canvas *, int, int);
void		t_canvas_putpixel(t_canvas *, int, int, sfColor);

#endif
