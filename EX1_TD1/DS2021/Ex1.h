#include<systemc.h>
SC_MODULE(Ex1) 
{
  sc_in_clk clk;
  sc_event my_event;
  int count;
void event_filled() 
{
	//S1: thread sans dont_initialize
	//S2: CTHREAD ou thread avec dont_initialize
  my_event.notify(2,SC_NS);// S1 s'exécute à 0s  par le compilateur//S2 à 0s car front à 0s
  wait();// S1: s'exécute à 0s par le compilateur //S2: à 0s car front à 0s
  cout<<" @P1 "<<sc_time_stamp()<<" count= "<<count<<endl; //S1:s'exécute à 0s car front à 0s// S2: 15 ns 2 eme front
  count++;//S1: exec à 0s count = 1//S2: exec à 15 ns count =2
  my_event.notify(2+count,SC_NS);//S1 à 0s//S2:exec à 15ns le déclenchement de my_event à 19 ns
  wait();//S1: 0s//S2 15 ns
  cout<<" @P1 "<<sc_time_stamp()<<" count= "<<count<<endl;// S1: exec 15 ns 2 eme front// S2: exec 30 ns 3 eme front
 // sc_stop();   // S1: exec 15 ns // S2: exec 30 ns 
}

void monitor() 
{
	while(true)
	{
wait(my_event);// S1: 1 ere exec à 0s & 2éme exec à 5ns//S2:1 ere exec à 0s & 2éme exec à 19ns & 3éme exec à 22ns
cout<<" @P2 "<<sc_time_stamp()<<" count= "<<count<<endl;// S1 exec à 2 ns// S2:1 ere exec à 2 ns & 2éme exec à 19ns
wait(3,SC_NS);  //S1: exec à 2 ns // S2:1 ere exec à 2 ns & 2éme exec à 19ns
count++;//S1:exec 5ns// S2:1 ere exec à 5 ns count = 2& 2éme exec à 22ns count =3
cout<<" @P2 "<<sc_time_stamp()<<" count= "<<count<<endl;//S1: exec à 5 ns // S2:1 ere exec à 5 ns count = 2& 2éme exec à 22ns count =3
	}
}


  SC_CTOR(Ex1): count(0)
  {
    SC_THREAD(event_filled);
    sensitive<<clk.pos();
	//dont_initialize();
	 // SC_CTHREAD(event_filled, clk.pos());// equivaut un Thread clocké avec dont_initialize()
    SC_THREAD(monitor);  
  }
};
