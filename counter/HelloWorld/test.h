#include <systemc.h>

SC_MODULE(test) {
    sc_in<sc_logic> tQ;
    sc_out<sc_logic> tD;

    void stimulis() {
        while (true) {
            tD.write(SC_LOGIC_0);
            wait(100, SC_NS);

            tD.write(SC_LOGIC_1);
            wait(200, SC_NS);

            tD.write(SC_LOGIC_X);
            wait(70, SC_NS);

            tD.write(SC_LOGIC_Z);
            wait(300, SC_NS);
        }
    }

    void verif() {
        cout <<"@ "<< sc_time_stamp() << "Q = " << tQ << endl;
    }

    SC_CTOR(test) {
        SC_METHOD(verif);
        sensitive << tQ;
        dont_initialize();

        SC_THREAD(stimulis);
    }
};
