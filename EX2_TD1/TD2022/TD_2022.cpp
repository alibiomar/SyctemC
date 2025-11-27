#include "TD_2022.h"
void TD2022:: do_test1() 
{ switch (cnt) {
      case 0 : cout << "@" << sc_time_stamp() <<" cnt= "<< cnt << endl;
               next_trigger(e1);
               break;
      case 1 : cout << "@" << sc_time_stamp() <<" cnt= "<< cnt << endl;
               next_trigger(10, SC_NS);
               break;
      case 2 : cout << "@" << sc_time_stamp() <<" cnt= "<< cnt << endl;
               next_trigger(e1 | e2);
               break;
      case 3 : cout << "@" << sc_time_stamp() <<" cnt= "<< cnt << endl;
		       //next_trigger();
               break;
      default : cout << "@" << sc_time_stamp() <<" cnt= "<< cnt << endl;
               break;
    }
    cnt ++;
 } 

void TD2022::do_test2() 
{
while (true) {
      wait(2);// 0s attendre 2 fronts revenir à 2 ns
      cout << "@" << sc_time_stamp() <<" Triggering e1"<<endl;// 2 ns
      e1.notify();// 2 ns
      wait(20);// 2 ns attendre 20 fronts revenir à 22 ns
      cout << "@" << sc_time_stamp() <<" Triggering e2"<<endl;// 22 ns
      e2.notify();// 22 ns
      wait(2); // 22 ns attendre 2 fronts revenir à 24 ns
      cout << "@" << sc_time_stamp() <<" Terminating simulation"<<endl;
      sc_stop(); 
    }
} 
