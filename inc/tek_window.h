/*
** EPITECH PROJECT, 2022
**
** Tekpaint
**
*/

#ifndef		TEK_WINDOW_H_
# define	TEK_WINDOW_H_

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
