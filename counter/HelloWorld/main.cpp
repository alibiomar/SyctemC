#include "test.h"
#include "counter.h"
int sc_main(int argc, char* argv[])
{
	counter my_counter("my_counter");
	sc_clock clock("clock", 10, SC_MS,0.5,5,SC_MS,true);

	my_counter.clk1(clock);
	sc_start(200, SC_MS);

	return 0;
}
