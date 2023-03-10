#include "term.h"
#include <stdio.h>

int
term_test ()
{
  mt_clrscr ();
  printf ("Привет, это терминал по умолчанию\n");
  getchar ();

  mt_clrscr ();
  mt_setbgcolor (GREEN);
  printf ("Привет, это зеленый фон для вывода текста\n");
  getchar ();

  mt_setbgcolor (DEFAULT);
  mt_clrscr ();
  mt_setfgcolor (RED);
  printf ("Привет, это красный фон для всего\n");
  getchar ();

  mt_clrscr ();
  return 0;
}
