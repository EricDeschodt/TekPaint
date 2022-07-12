/*
** EPITECH PROJECT, 2022
**
** Tekpaint
**
*/

#ifndef		TEK_BUTTON_H_
# define	TEK_BUTTON_H_

# include	<SFML/Audio.h>
# include	<SFML/Graphics.h>
# include	<SFML/System.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<math.h>
# include	<stdio.h>
# include	<stdbool.h>

# include	"tek_canvas.h"

typedef enum {
  POS_X = 0,
  POS_Y = 1,
  WIDTH = 2,
  HEIGHT = 3,
  MAIN_COLOR = 4,
  HOVER_COLOR = 5,
  BORDER_COLOR = 6,
  TEXT_COLOR = 7
}button_data;

typedef struct	s_button {
  sfIntRect	hitbox;
  t_canvas	*canvas;
  sfText	*text;
  void		(*fct)(void *);
  sfColor	main;
  sfColor	hover;
  sfColor	border;
  bool		is_hover;
}t_button;

t_button	*t_button_create(sfIntRect, sfFont *,  void(*)(void *));
void		t_button_set_text(t_button *, sfFont *, sfColor, const char *);
void		t_button_set_button_style(t_button *,
					  sfColor, sfColor, sfColor);
void		t_button_draw(t_button *, sfRenderWindow *);
void		t_button_update_state(t_button *);
void		t_button_hover(t_button *, sfRenderWindow *);

#endif
