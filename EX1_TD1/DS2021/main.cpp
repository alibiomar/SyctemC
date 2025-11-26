#include "Ex1.h"

int sc_main(int argc, char* argv[]) 
{
  sc_clock clock("clock", 15, SC_NS);
  Ex1 my_Ex1("my_Ex1");
  my_Ex1.clk(clock);
  
  sc_start();
  return 0;
}
