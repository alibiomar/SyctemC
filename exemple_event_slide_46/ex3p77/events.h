#include <systemc.h>
SC_MODULE(events) {
	sc_in_clk clock;
	sc_event e1;
	sc_event e2;
	int x;
	void do_test1(){
		while(true) {
	        wait();//0s
			cout <<"@" << sc_time_stamp() <<" starting test" <<endl;// 2 ns
			wait();// 2 ns
			cout <<"@" << sc_time_stamp() <<" triggering e1" <<endl;//4 ns
			 x++;// 4 ns, x= 1
			e1.notify(5,SC_NS);// 4 ns, e1 sera déclenché à 4+5=9 ns
			cout <<"@" << sc_time_stamp() <<" bonjour" <<endl;// 4 ns
			wait();// 4 ns
			wait(e2);// 6 ns
			cout <<"@" << sc_time_stamp() <<" got triggere2" <<endl;//14 ns
			wait();
			cout <<"@" << sc_time_stamp() <<" terminating simulation"<<endl;// 16 ns
			sc_stop();
		}
	}
	void do_test2(){
		while(true) {
		  cout <<"@" << sc_time_stamp() <<" start process 2" <<endl;//0s // 14 ns
			wait(e1);// 0s
			cout <<"@" << sc_time_stamp() <<" got trigger e1" <<endl;// 9 ns
			cout <<"@" << sc_time_stamp() <<" x=" <<x<<endl;// 9 ns
			//wait(1,SC_NS);
			wait(3);//9 ns attente de 3 changements sur la liste de sensibilité statique içi clock
			cout <<"@" << sc_time_stamp() <<" triggering e2" <<endl;//14 ns
			e2.notify();//14 ns
		}
	}
	SC_CTOR(events): x(0){ 
		SC_THREAD(do_test1);
		//SC_CTHREAD(do_test1,clock.pos());
		//SC_CTHREAD= c'est un THREAD clocké + dont_intialize()
		sensitive<<clock.pos();
		dont_initialize();
		SC_THREAD(do_test2);
		sensitive<<clock.pos();
		dont_initialize();
	}
};
