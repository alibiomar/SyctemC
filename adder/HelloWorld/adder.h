#include <systemc.h>

SC_MODULE(EightBitAdder) {
    sc_in<sc_uint<8> > a, b;      // Input ports
    sc_out<sc_uint<8>> sum;      // Output port
    sc_out<bool> overFlow;
    void somme() {
        sum.write((a.read() + b.read()) & 255);
        overFlow.write(((a.read() + b.read()) & 256) != 0);
    }
    SC_CTOR(EightBitAdder) {
        SC_METHOD(somme);
        sensitive << a << b;
        dont_initialize();
    }
};
