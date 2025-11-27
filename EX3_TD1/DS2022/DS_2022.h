// Ds_2022.h
#include <systemc.h>

SC_MODULE(DS2022) 
{
  sc_event my_event;
  sc_in_clk clk;
 sc_signal<int> my_count, better_count;
 int count;

  SC_CTOR(DS2022): my_count(0), better_count(0), count(0)
  {
    SC_THREAD(process1);
    sensitive<<better_count;
    SC_THREAD(process2);  
	 sensitive<<clk.pos();
	 SC_METHOD(process3);  
	 sensitive<<clk.pos();
  }
  
  void process1();
  void process2();
  void process3();
  
};
