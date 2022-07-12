/*
** EPITECH PROJECT, 2022
**
** TekPaint
**
*/

#include "tekpaint.h"

void	tekpaint_put_in_list(t_tekpaint *tekpaint,
			     t_button *new_button)
{
  t_buttons_list *new_node = malloc(sizeof(t_buttons_list));
  if (!new_node)
    exit(EXIT_FAILURE);
  new_node->button = new_button;  
  if (tekpaint->buttons_list == NULL)
    new_node->next = NULL;
  else
    new_node->next = tekpaint->buttons_list;      
  tekpaint->buttons_list = new_node;
}

void	tekpaint_add_button_in_list(t_tekpaint *tekpaint,
				    char *line)
{
  char *data[8];
  int i = 0;
  const char *delim = ",";
  char	*token = strtok(line, delim);
  while (token != NULL)
    {
      data[i++] = strdup(token);
      token = strtok(NULL, delim);
    }
  t_button *new_button = t_button_create
    ((sfIntRect){atoi(data[POS_X]),
       atoi(data[POS_Y]),
       atoi(data[WIDTH]),
       atoi(data[HEIGHT])},
     NULL, NULL);
  t_button_set_button_style
    (new_button,
     sfColor_fromInteger(strtol(data[MAIN_COLOR], NULL, 16)),
     sfColor_fromInteger(strtol(data[HOVER_COLOR], NULL, 16)),
     sfColor_fromInteger(strtol(data[BORDER_COLOR], NULL, 16)));
  t_button_set_text
    (new_button,
     tekpaint->font,
     sfColor_fromInteger(strtol(data[TEXT_COLOR], NULL, 16)),
     "test");
  tekpaint_put_in_list(tekpaint, new_button);
}

void	tekpaint_load_config(t_tekpaint *tekpaint)
{
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  tekpaint->buttons_list = NULL;
  fp = fopen("./conf/config.csv", "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);
  read = getline(&line, &len, fp);
  while ((read = getline(&line, &len, fp)) != -1) {
    tekpaint_add_button_in_list(tekpaint, line);
  }
  if (line)
    free(line);
}

void	tekpaint_init(t_tekpaint *tekpaint)
{
  tekpaint->width = 1280;
  tekpaint->height = 720;
  tekpaint->border = 5;
  tekpaint->window = window_init
    ("tekpaint", tekpaint->width, tekpaint->height, 32);
  if (!tekpaint->window)
    exit(EXIT_FAILURE);
  sfRenderWindow_setFramerateLimit(tekpaint->window, 60);
  tekpaint->ui = t_canvas_create(tekpaint->width,
				 tekpaint->height,
				 sfBlack);
  tekpaint_ui(tekpaint);
  tekpaint->font = sfFont_createFromFile("./res/Arial.ttf");
  tekpaint_load_config(tekpaint);
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

void	tekpaint_draw_buttons(t_tekpaint *tekpaint)
{
  t_buttons_list *tmp = tekpaint->buttons_list;

  while (tmp != NULL)
    {
      t_button_hover(tmp->button, tekpaint->window);
      t_button_draw(tmp->button, tekpaint->window);
      tmp = tmp->next;
    }
}

void	tekpaint_update(t_tekpaint *tekpaint)
{
  event_handler(tekpaint);
  t_canvas_draw(tekpaint->window, tekpaint->ui, 0, 0);
  tekpaint_draw_buttons(tekpaint);
}
