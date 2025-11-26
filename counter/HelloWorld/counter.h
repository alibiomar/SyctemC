#include <systemc.h>
SC_MODULE(counter) {
	sc_in_clk clk1;
	int count;
	SC_CTOR(counter) : count(0)
	{
		SC_METHOD(do_count);
		sensitive<< clk1.pos();
		dont_initialize();

	}
	void do_count()
	{
		count++;

		cout << sc_time_stamp() << " count = " << count << endl;
	}
};