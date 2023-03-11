#include "term.h"
#include <stdio.h>

int
term_test ()
{
  mt_clrscr ();
  printf ("Терминал по умолчанию\n");
  getchar ();

  mt_clrscr ();
  mt_setbgcolor (BLUE);
  printf (" Синий фон для вывода текста\n");
  getchar ();

  mt_setbgcolor (GREEN);
  mt_clrscr ();
  mt_setfgcolor (BLACK);
  printf ("Зеленый фон для всего\n");
  getchar ();

  mt_clrscr ();
  printf("\E[H\E[2J\033[0m\033[39m");
  return 0;
}
