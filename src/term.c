#include "term.h"

int
mt_clrscr (void) // очищает экран и перемещает курсор в верхний левый угол
{
  if (write (STDOUT_FILENO, CLEAR, strlen (CLEAR))
      < sizeof (char) * strlen (CLEAR))
    {
      return -1;
    }
  return 0;
}

int
mt_gotoXY (
    int x,
    int y) // перемещает курсор к введенным координатам (x, y) = (row, col)
{
  char go[30];
  sprintf (go, "\E[%d;%dH", x, y);
  if (write (STDOUT_FILENO, go, strlen (go)) < sizeof (char) * strlen (go))
    {
      return -1;
    }
  return 0;
}

int
mt_getscreensize (int *rows, int *cols) // получает размер экрана терминала
                                        // (количество строк и столбцов)
{
  struct winsize ws;
  if (ioctl (1, TIOCGWINSZ, &ws))
    {
      return -1;
    }
  *rows = ws.ws_row;
  *cols = ws.ws_col;
  return 0;
}

int
mt_setfgcolor (enum colors color) // устанавливает цвет фона для всех строк и
                                  // столбцов всего терминала
{
  char foreground[30];
  sprintf (foreground, "\E[38;5;%dm", color);
  if (write (STDOUT_FILENO, foreground, strlen (foreground))
      < sizeof (char) * strlen (foreground))
    {
      return -1;
    }
  return 0;
}

int
mt_setbgcolor (enum colors color) //устанавливает цвет фона только для
                                  //предстоящих символов
{
  char background[30];
  sprintf (background, "\E[48;5;%dm", color);
  if (write (STDOUT_FILENO, background, strlen (background))
      < sizeof (char) * strlen (background))
    {
      return -1;
    }
  return 0;
}
