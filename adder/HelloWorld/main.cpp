#include "adder.h"
#include "test.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<sc_uint<8>> sig_a, sig_b, sig_sum;
    sc_signal<bool> sig_overFlow;

    // Instantiate modules
    EightBitAdder my_adder("my_adder");
    test my_test("my_test");

    // Connect signals
    my_adder.a(sig_a);
    my_adder.b(sig_b);
    my_adder.sum(sig_sum);
    my_adder.overFlow(sig_overFlow);

    my_test.a(sig_a);
    my_test.b(sig_b);
    my_test.sum(sig_sum);
    my_test.overFlow(sig_overFlow);

    // Start simulation
    sc_start();

    return 0;
}