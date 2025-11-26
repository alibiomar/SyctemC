#include "test.h"
#include "BasquleD.h"
int sc_main(int argc, char* argv[])
{
	DFF DFF1("DFF1");
	test test1("test1");
	sc_clock clock("clock", 15, SC_NS);
	sc_signal<sc_logic> D_sig, Q_sig;

	DFF1.D(D_sig);
	test1.tD(D_sig);

	DFF1.Q(Q_sig);
	test1.tQ(Q_sig);

	DFF1.H(clock);

	sc_start(900, SC_NS);
	return 0;
}
