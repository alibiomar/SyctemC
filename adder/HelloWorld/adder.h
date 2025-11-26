#include <systemc.h>

SC_MODULE(adder) {
    sc_in<int> a, b;      // Input ports
    sc_out<int> sum;      // Output port

    SC_CTOR(adder) {
        SC_METHOD(do_add);
        sensitive << a << b;
        dont_initialize();
    }

    void do_add() {
        int result = a.read() + b.read();
        sum.write(result);
        cout << sc_time_stamp() << " | a = " << a.read()
            << ", b = " << b.read()
            << ", sum = " << result << endl;
    }
};
