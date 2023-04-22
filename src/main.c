#include "bc.h"
#include "prototype.h"
#include "readkey.h"
#include "signals.h"
#include "term.h"
#include "term_gui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main ()
{
  sc_memoryInit ();
  for (int i = 3; i < 100; i += 2)
    {
      sc_memorySet (i, i * 2);
    }
  sc_regInit ();
  sc_regSet (FLAG_IGNORE, 1);
  sc_accumSet (9999);
  sc_countSet (0);
  sig_set ();

  rk_mytermsave ();
  rk_mytermregime (0, 0, 1, 0, 1);
  mt_clrscr ();
  g_interface ();
  rk_mytermrestore ();
  mt_clrscr ();
  return 0;
}