#include <systemc.h>
#include "events.h"
int sc_main (int argc,char* argv[]){
	sc_clock clock("myclock",2,SC_NS);
	events object("events");
	object.clock (clock);
	sc_start();
	return 0;
}