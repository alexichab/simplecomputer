#include "prototype.h"
#include "term.h"
#include "term_gui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main ()
{
  mt_clrscr ();
  sc_memoryInit ();
  for (int i = 3; i < 100; i *= 3)
    {
      sc_memorySet (i, i);
    }
  sc_regInit ();
  sc_regSet (1, 1);
  sc_regSet (2, 1);
  sc_regSet (3, 1);
  sc_regSet (4, 1);
  sc_regSet (5, 1);
  out_GUI ();
  term_test();
  printf("\E[H\E[2J\033[0m\033[39m");
  return 0;
}