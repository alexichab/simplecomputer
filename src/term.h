#pragma once

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define CLEAR "\E[H\E[2J"
#define RESETCOLOR "\033[0m"
#define RESETCOLORF "\033[39m"

enum colors
{
  LIGHT_GREY = 247,
  GREY = 237,
  BLACK = 16,
  RED = 124,
  GREEN = 41,
  BLUE = 20,
  YELLOW = 184,
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
