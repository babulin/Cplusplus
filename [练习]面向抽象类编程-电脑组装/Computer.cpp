#include "Computer.h"

Computer::Computer(ICpu* _cpu, IGpu* _graphics, IMemory* _memory)
{
	cout << "Computer()" << endl;
	cpu = _cpu;
	graphics = _graphics;
	memory = _memory;
}

Computer::~Computer()
{
	cout << "~Computer()" << endl;

	if (cpu != NULL)
		delete cpu;

	if (graphics != NULL)
		delete graphics;

	if (memory != NULL)
		delete memory;
}

void Computer::show()
{
	cout << "Computer::show()" << endl;
	cout << "================" << endl;
	cpu->showCPU();
	graphics->showGPU();
	memory->showMemory();
	cout << "================" << endl;
}
