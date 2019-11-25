#include <iostream>
#include "Computer.h"
#include "Intel.h"
#include "Nvidia.h"
#include "Kingston.h"
#include "Amd.h"

using namespace std;

int main() {

	//ICpu* cpu = new Intel();
	IGpu* nvi = new Nvidia();
	IMemory* mem = new Kingston();

	//¸ü»»CPU
	ICpu* aCpu = new Amd();

	Computer com1(aCpu, nvi, mem);
	com1.show();

}