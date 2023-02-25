#pragma once

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMSIZE 100

// флаги
#define FLAG_WRONG_COMMAND 5
#define FLAG_WRONG_OPERAND 4
#define FLAG_WRONG_ADDRESS 3
#define FLAG_DIV_BY_ZERO 2
#define FLAG_OVERFLOW 1


// ошибки 
#define ERR_WRONG_ADDRESS -1
#define ERR_WRONG_FLAG -2
#define ERR_WRONG_VALUE -3
#define ERR_WRONG_COMMAND -4
#define ERR_WRONG_OPERAND -5

// битовые операции 
#define BIT_SET(X, Y) X = X | (1 << (Y - 1))
#define BIT_DEL(X, Y) X = X & (~(1 << (Y - 1)))
#define BIT_GET(X, Y) X >> (Y - 1) & 0x1

int sc_memoryInit (); // инициализация массива из 100 элементов

int sc_memorySet (int address, 
                  int value); // устанавливает значение блока памяти

int sc_memoryGet (int address, int *value); // получает значение блока памяти и 
                                            // возвращает его в значение var

int sc_memorySave (char *filename); // сохраняет память в бинарный файл 

int sc_memoryLoad (char *filename); // загружает оперативную память из файла

int sc_regInit (void); // инициализирует регистр флагов с нуля

int sc_regSet (
    int reg,
    int value); //устанаввливает флаг значение регистра #define-s используется
                // для номеров регистров если неверный номер - то ошибка.

int sc_regGet (
    int reg,
    int *value); //получает значение флага, если неправильный регистр то ошибка

int sc_commandEncode (
    int command, int operand, 
    int *value); // кодирует команду с определенным номером и  операндом
                 // помещает результат в значение если он неправильная  команда
                 // или операнд - ошибка, значение не меняется

int sc_commandDecode (int value, int *command,
                      int *operand); // декодирует значение как команду sc если
                                     // декодировние невозможно  устанавливает
                                     // команду ошибки и возвращает ошибку.
