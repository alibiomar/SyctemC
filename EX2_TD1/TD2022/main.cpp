#include "TD_2022.h"

int sc_main (int argc, char* argv[]) {
  sc_clock clock("clock",1,SC_NS);

  TD2022 votreTD("votreTD1");
    votreTD.clock (clock);

cout <<"Starting simulation" <<endl;
sc_start(); 

  return 0;
}
