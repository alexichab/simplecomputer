#include "prototype.h"

int sc_memory[MEMSIZE];
int sc_register;

int
sc_memoryInit () //инициализирует массив из 100 элементов
{
  memset (sc_memory, 0, MEMSIZE * sizeof (sc_memory[0]));
  return 0;
}

int
sc_memorySet(int address,
                 int value)// устанавливает значение блока памяти
{
    if (address < 0 || address >= MEMSIZE)
    {
      BIT_SET (sc_register, FLAG_WRONG_ADDRESS);
      return ERR_WRONG_ADDRESS;
    }
  sc_memory[address] = value;
  return 0;
}

int sc_memoryGet (int address, // gets the value of [address] memory unit and
                  int *value)//получает значение блока памяти и возвращет его в переменную
{
    if (address < 0 || address >= MEMSIZE)
    {
      BIT_SET (sc_register, FLAG_WRONG_ADDRESS);
      return ERR_WRONG_ADDRESS;
    }
  *value = sc_memory[address];
  return 0;
}

int sc_memorySave(char *filename)//сохраняет память в бинарный файл
{
    FILE *f = fopen (filename, "wb");
  if (!f)
    {
      return 1;
    }
  fwrite (sc_memory, sizeof (int), sizeof (sc_memory) / sizeof (int), f);
  fclose (f);
  return 0;
}

int sc_memoryLoad(char *filename)//загружает оперативную память из файла
{
  FILE *f = fopen (filename, "rb");
    if (!f)
    {
      return 1;
    }
  fread (sc_memory, sizeof (int), sizeof (sc_memory) / sizeof (int), f);
  fclose (f);
  return 0;
}

int sc_regInit(void)//инициализирует регистр флагов с 0
{
  sc_register = 0;
  return 0; 
}

int sc_regSet(int reg,
              int value)//устанавливает значение регистра флага #define-s используются для номера регистров, если неверный номер регистра то ошибка
{
    if (reg < 0 || reg > 5)
    {
      return ERR_WRONG_FLAG;
    }
  if (!value)
    {
      BIT_DEL (sc_register, reg);
      return 0;
    }
  if (value != 1)
    {
      BIT_SET (sc_register, FLAG_OVERFLOW);
      return ERR_WRONG_VALUE;
    }
  BIT_SET (sc_register, reg);
  return 0;
}

int sc_regGet(int reg,
              int *value)//получает значение флага, если неверный регистр, то ошибка
{
    if (reg < 0 || reg > 5)
    {
      return ERR_WRONG_FLAG;
    }
  *value = BIT_GET (sc_register, reg);
  return 0;
}

int sc_commandEncode (int command,
                      int operand,
                      int *value)//кодирует команду с определенным номером и операндом, помещает результат в значение, если он неправильный то команда или операнд выдают ошибку,значение не меняется.
{
  // commands list: 0x10, 0x11, 0x20, 0x21, 0x30, 0x31, 0x32, 0x33, 0x40, 0x41,
  // 0x42, 0x43, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x60,
  // 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x70, 0x71, 0x72,
  // 0x73, 0x74, 0x75, 0x76
  if (((command > 0x76) || (command < 0x10)) || ((command > 0x11) & (command < 0x20))
      || ((command > 0x21) & (command > 0x30)) || ((command > 0x33) & (command < 0x40))
      || ((command > 0x43) & (command < 0x51)))
    {
      sc_regSet (FLAG_WRONG_COMMAND, 1);
      return ERR_WRONG_COMMAND;
    }
  if (operand < 0 || operand > 127)
    {
      sc_regSet (FLAG_WRONG_OPERAND, 1);
      return ERR_WRONG_OPERAND;
    }
  int encoded = 0b0000000000000000 | command;
  encoded <<= 7;
  encoded |= operand;
  *value = encoded;
  return 0;
}

int sc_commandDecode (int value,
                      int *command,
                      int *operand)//декодирует значение как комнаду sc,если декодировавние невозможно устанавливает команду error и возвразает ошибку.  
{
  if ((value & (1 << 14)) != 0)
    {
      sc_regSet (FLAG_WRONG_COMMAND, 1);
      return ERR_WRONG_COMMAND;
    }
  *command = (value >> 7);
  value -= (*command << 7);
  *operand = value;
  return 0;
}