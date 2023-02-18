#include "prototype.h"
#include <stdio.h>

int main ()
{
    printf("_______________________________________________________________________\n");
    sc_memoryInit ();
  printf ("Инициализация памяти\n");
  for (int i = 1; i < 4; i++)
    {
      int val = i * 3;
      sc_memorySet (i, val);
      printf ("Запись в массив sc_memory[%d] to %d\n", i, val);
    }
  for (int i = 1; i < 4; i++)
    {
      int val = 0;
      sc_memoryGet (i, &val);
      printf ("получение из массива sc_memory[%d] = %d\n", i, val);
    }
    printf("_______________________________________________________________________\n");
  char *memfile = "memory.mem";
  sc_memorySave (memfile);
  printf ("запись в файл memory -> %s\n", memfile);
  for (int i = 1; i < 4; i++)
    {
      int val = i * 3;
      sc_memorySet (i, val);
      printf ("Запись sc_memory[%d] to %d\n", i, val);
    }
    printf("_______________________________________________________________________\n");
  sc_memoryLoad (memfile);
  printf ("Загружаем файл memory <- %s\n", memfile);
  for (int i = 1; i < 4; i++)
    {
      int val = 0;
      sc_memoryGet (i, &val);
      printf ("Получаем sc_memory[%d] = %d\n", i, val);
    }
    printf("_______________________________________________________________________\n");
  sc_regInit ();
  printf ("инициализация register = 0\n");
  sc_regSet (FLAG_DIV_BY_ZERO, 1);
  int val = 0;
  sc_regGet (FLAG_DIV_BY_ZERO, &val);
  printf ("Получение FLAG_DIV_BY_ZERO = %d\n", val);
  sc_regGet (FLAG_OVERFLOW, &val);
  printf ("Получение FLAG_OVERFLOW = %d\n", val);
  sc_regSet (FLAG_DIV_BY_ZERO, 2); // пытаемся перегрузить бит)
  sc_regGet (FLAG_OVERFLOW, &val);
  printf ("Получение FLAG_OVERFLOW = %d\n", val);
  int command = 0x21; //команда
  int operand = 11;   //что записываешь в команду
  sc_commandEncode (command, operand, &val);
  printf ("Кодирование команды '%d' операнда '%d' = '%d' \n",
          command, operand, val);   
  sc_commandDecode (val, &command, &operand);
  printf ("Декодирование '%d' = команды '%d' операнда'%d'\n", val,
          command, operand);
  sc_commandEncode (0x0, 129, &val);     // пытаемся закодировать неправильную команду
  printf ("Кодирование value = %d\n", val); // ничего не меняется
  sc_regGet (FLAG_WRONG_COMMAND, &val);
  printf ("FLAG_WRONG_COMMAND = %d\n", val);
  printf("_______________________________________________________________________\n");
  //printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  // printf ("███████▓█████▓▓╬╬╬╬╬╬╬╬▓███▓╬╬╬╬╬╬╬▓╬╬▓█\n████▓▓▓▓╬╬▓█████╬╬╬╬╬╬███▓╬╬╬╬╬╬╬╬╬╬╬╬╬█\n███▓▓▓▓╬╬╬╬╬╬▓██╬╬╬╬╬╬▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█\n████▓▓▓╬╬╬╬╬╬╬▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█\n███▓█▓███████▓▓███▓╬╬╬╬╬╬▓███████▓╬╬╬╬▓█\n████████████████▓█▓╬╬╬╬╬▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬█\n███▓▓▓▓▓▓▓▓▓▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█\n████▓▓▓▓▓▓▓▓▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█\n███▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█\n█████▓▓▓▓▓▓▓▓█▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█\n█████▓▓▓▓▓▓▓██▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██\n█████▓▓▓▓▓████▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██\n████▓█▓▓▓▓██▓▓▓▓██╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██\n████▓▓███▓▓▓▓▓▓▓██▓╬╬╬╬╬╬╬╬╬╬╬╬█▓╬▓╬╬▓██\n█████▓███▓▓▓▓▓▓▓▓████▓▓╬╬╬╬╬╬╬█▓╬╬╬╬╬▓██\n█████▓▓█▓███▓▓▓████╬▓█▓▓╬╬╬▓▓█▓╬╬╬╬╬╬███\n██████▓██▓███████▓╬╬╬▓▓╬▓▓██▓╬╬╬╬╬╬╬▓███\n███████▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬████\n███████▓▓██▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓████\n████████▓▓▓█████▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█████\n█████████▓▓▓█▓▓▓▓▓███▓╬╬╬╬╬╬╬╬╬╬╬▓██████\n██████████▓▓▓█▓▓▓▓▓██╬╬╬╬╬╬╬╬╬╬╬▓███████\n███████████▓▓█▓▓▓▓███▓╬╬╬╬╬╬╬╬╬▓████████\n██████████████▓▓▓███▓▓╬╬╬╬╬╬╬╬██████████\n███████████████▓▓▓██▓▓╬╬╬╬╬╬▓███████████\n");
  // printf ("\t IM ALWAYS COME BACK\n");
    return 0;
}