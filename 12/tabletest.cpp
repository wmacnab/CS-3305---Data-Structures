#include <iostream>
#include "table1.h"
#include "tractor.cpp"

using namespace std;
using namespace wmacnab_12;

int main()
{
	table<tractor> lot;
	tractor t1 { .key = 15, .cost = 2499.99, .horsepower = 50 };
	lot.insert(t1);
}
