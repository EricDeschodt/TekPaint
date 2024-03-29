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
# include	<string.h>

# include	"tek_window.h"
# include	"tek_canvas.h"
# include	"tek_event.h"
# include	"tek_button.h"

typedef struct		s_buttons_list {
  t_button		*button;
  struct s_buttons_list	*next;
}t_buttons_list;


typedef struct		s_tekpaint {
  int			width;
  int			height;
  int			border;
  t_canvas		*ui;
  sfEvent		event;
  sfRenderWindow	*window;
  t_buttons_list	*buttons_list;
  sfFont		*font;
} t_tekpaint;


void			tekpaint_init(t_tekpaint *);
void			tekpaint_ui(t_tekpaint *);
void			tekpaint_update(t_tekpaint *);
void			tekpaint_load_config(t_tekpaint *);

#endif
