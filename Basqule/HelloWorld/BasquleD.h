#include <systemc.h>
SC_MODULE(DFF) {
	sc_in<sc_logic> D;
	sc_in_clk H;
	sc_out<sc_logic> Q;
	void do_dff()
	{
		Q.write(D.read());
	}
	SC_CTOR(DFF) {
		SC_METHOD(do_dff)
			sensitive << H.pos();
}
};
