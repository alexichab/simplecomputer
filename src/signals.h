#pragma once

#include "prototype.h"
#include <signal.h>
#include <unistd.h>

int sig_handle_reset ();
int sig_handle_alarm ();
int sig_set ();
