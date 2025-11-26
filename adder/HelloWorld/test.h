#include <systemc.h>

SC_MODULE(test) {
    sc_out<int> a, b;   // Outputs that drive the adder inputs
    sc_in<int> sum;     // Input to observe adder output
    sc_in<bool> clk;    // Clock input

    SC_CTOR(test) {
        SC_THREAD(run);
        sensitive << clk.pos();
    }

    void run() {
        wait(); 

        // Apply test vectors
        a.write(2); b.write(3);
        wait();
        cout << sc_time_stamp() << " | Test: 2 + 3 = " << sum.read() << endl;

        a.write(7); b.write(4);
        wait();
        cout << sc_time_stamp() << " | Test: 7 + 4 = " << sum.read() << endl;

        a.write(10); b.write(15);
        wait();
        cout << sc_time_stamp() << " | Test: 10 + 15 = " << sum.read() << endl;

        sc_stop(); // End simulation
    }
};