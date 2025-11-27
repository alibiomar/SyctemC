#include <systemc.h>

SC_MODULE(TD2022) 
{
sc_in_clk clock;
  sc_event  e1,e2;
  int cnt;

  SC_CTOR(TD2022)
{
   cnt = 0;
    SC_METHOD(do_test1);
      sensitive << clock.pos();
    //SC_CTHREAD(do_test2, clock.pos());
    SC_THREAD(do_test2);
	 sensitive << clock.pos();
    dont_intialize();
	
  }  

void do_test1();
  void do_test2();
}; 
