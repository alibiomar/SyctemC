#include "adder.h"
#include "test.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<int> sig_a, sig_b, sig_sum;
    sc_clock clk("clk", 10, SC_NS);

    // Instantiate modules
    adder my_adder("my_adder");
    test my_test("my_test");

    // Connect signals
    my_adder.a(sig_a);
    my_adder.b(sig_b);
    my_adder.sum(sig_sum);

    my_test.a(sig_a);
    my_test.b(sig_b);
    my_test.sum(sig_sum);
    my_test.clk(clk);

    // Start simulation
    sc_start();

    return 0;
}
