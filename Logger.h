#ifndef LOGGER_H
#define LOGGER_H

#include "pso.h"

void wyczysc_plik_logu(char *nazwa_pliku);

void zapisz_pozycje(char *nazwa_pliku, grupa *roj, int iteracja);

#endif