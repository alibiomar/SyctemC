
#include "DS_2022.h"

int sc_main(int argc, char* argv[]) 
{
  sc_clock clock("clock", 2, SC_NS);
  DS2022 my_DS2022("my_DS2022");
   my_DS2022.clk (clock);
  sc_start(12,SC_NS);
  
  return 0;
}
