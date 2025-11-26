#pragma once
#include <systemc.h>
SC_MODULE(Hello_world) {
	SC_CTOR(Hello_world) {}
	void say_hello() {
		cout << "hello world \n";
	}
};
