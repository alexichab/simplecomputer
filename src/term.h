#pragma once

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define CLEAR "\E[H\E[2J"

enum colors
{
  BLACK,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE,
  UNKNOWN,
  DEFAULT
};

int mt_clrscr (void); // очищает экран и перемещает курсор в верхний левый угол
int mt_gotoXY (
    int x,
    int y); // перемещает курсор к введенным координатам (x, y) = (row, col)
int mt_getscreensize (int *rows, int *cols); //получает размер экрана терминала
                                             //(количество строк и столбцов)
int mt_setfgcolor (enum colors color); // устанавливает цвет фона для всех и
                                       // столбцов всего терминала
int mt_setbgcolor (enum colors color); // устанавливает цвет фона только для
                                       // предстоящих символов
