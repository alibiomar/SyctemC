#include <systemc.h>
#include "HelloWorld.h"
int sc_main(int argc, char* argv[])
{
	Hello_world hello("Hello");
	hello.say_hello();
	return(0);
}
