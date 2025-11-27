// Ds_2022.cpp
#include "DS_2022.h"

void DS2022::process1() 
{
	while(true)
	{
  my_event.notify(3,SC_NS);  //0s my_event à 3 ns
  wait();//0s attendre chngt better_count
  cout<<" P1@ "<<sc_time_stamp()<<" better_count= "<<better_count<<endl;// 2 ns
  count++;// 2 ns count=2
  my_count.write(count);// 2 ns 
  my_event.notify(my_count,SC_NS);// 2 ns my_event à 2 ns car my_count=0
  wait(count,SC_NS);// 2 ns my_count=2 attendre 2 ns
  my_count.write(my_count.read()+1); // 4 ns 
  cout<<" P1@ "<<sc_time_stamp()<<" my_count= "<<my_count<<endl;// 4 ns
   my_event.notify(count,SC_NS);// 4 ns my_event declenché 7 ns
  wait();// 4 ns my_count=3
 cout<<" P1@ "<<sc_time_stamp()<<" better_count= "<<better_count<<endl;// 4 ns
  my_event.notify(better_count.read(),SC_NS);// 4 ns 
	}
}

void DS2022::process2() 
{
	while(true)
	{
		wait(2);//0s attendre 2 fronts( front1 à 0s front 2 à 2 ns) // 4 ns better_count=3 attendre 2 fronts
		cout<<" P2@ "<<sc_time_stamp()<<" my_count= "<<my_count<<endl;// 2 ns my count =0// 8 ns my count=3
		better_count.write(better_count.read()+1);//2 ns
		wait(my_event);// 2 ns  better_count = 1 
		better_count.write(better_count.read()+1);// 2ns better_count=1
        cout<<" P2@ "<<sc_time_stamp()<<" better_count= "<<better_count<<endl;// 2ns 
        wait();// 2 ns  attendre front montant better_count=2
		cout<<" P2@ "<<sc_time_stamp()<<" my_count= "<<my_count<<endl;// 4 ns
        better_count.write(better_count.read()+1);// 4 ns 
	}
}
void DS2022::process3() 
{
if(count<3)
	{
		next_trigger(my_event);//0s // 2 ns 
	cout << " P3@ "<<sc_time_stamp()<<" count= "<< count <<endl;//0s// 2 ns
	}
	else 
		{next_trigger();   // 7 ns    // 8 ns 
		cout <<" P3@ "<< sc_time_stamp()<<" count= "<< count <<endl;// 7 ns// 8ns
	}
count++;// 0s count=1// 2 ns count = 3// 7 ns count =4 // 8 ns count=5
}