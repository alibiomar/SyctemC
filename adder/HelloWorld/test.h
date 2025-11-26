#include <systemc.h>

SC_MODULE(test) {
    sc_out<sc_uint<8>> a, b;   // Outputs that drive the adder inputs
    sc_in<sc_uint<8>>sum;     // Input to observe adder output
    sc_in <bool> overFlow;

    SC_CTOR(test) {
        SC_THREAD(run);
    }

    void run() {

        // Apply test vectors
        a.write(2); b.write(3);
        wait(150,SC_NS);
        cout << sc_time_stamp() << " | Test: 2 + 3 = " << sum.read() << endl;
        cout << sc_time_stamp() << " | overFlow=  " << overFlow << endl;


        a.write(7); b.write(4);
        wait(150, SC_NS);
        cout << sc_time_stamp() << " | Test: 7 + 4 = " << sum.read() << endl;
        cout << sc_time_stamp() << " | overFlow=  " << overFlow << endl;


        a.write(60); b.write(200);
        wait(150, SC_NS);
        cout << sc_time_stamp() << " | Test: 60 + 200 = " << sum.read() << endl;
        cout << sc_time_stamp() << " | overFlow=  " << overFlow << endl;


        sc_stop(); // End simulation
    }
};