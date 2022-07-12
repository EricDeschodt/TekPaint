/*
** EPITECH PROJECT, 2022
**
** Tekpaint
**
*/

#ifndef		TEKPAINT_H_
# define	TEKPAINT_H_

# include	<SFML/Audio.h>
# include	<SFML/Graphics.h>
# include	<SFML/System.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<math.h>
# include	<stdio.h>

# include	"tek_window.h"
# include	"tek_canvas.h"
# include	"tek_event.h"
# include	"tek_button.h"

typedef struct		s_tekpaint {
  int			width;
  int			height;
  int			border;
  t_canvas		*ui;
  sfEvent		event;
  sfRenderWindow	*window;
  t_button		*button;
} t_tekpaint;

void			tekpaint_init(t_tekpaint *);
void			tekpaint_ui(t_tekpaint *);
void			tekpaint_update(t_tekpaint *);

#endif
