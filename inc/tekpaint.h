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

sfRenderWindow	*window_init(char *, int, int, int);
void		window_close(sfRenderWindow *);
void		window_destroy(sfRenderWindow *);


#endif
