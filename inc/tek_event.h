/*
** EPITECH PROJECT, 2022
**
** Tekpaint
**
*/

#ifndef		TEK_EVENT_H_
# define	TEK_EVENT_H_

# include	<SFML/Audio.h>
# include	<SFML/Graphics.h>
# include	<SFML/System.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<math.h>
# include	<stdio.h>

# include	"tekpaint.h"

typedef struct s_tekpaint t_tekpaint;

void            event_handler(t_tekpaint *);

#endif
