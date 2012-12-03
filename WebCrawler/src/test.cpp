
#define _RUNTEST_
#ifdef  _RUNTEST_



#include "URL_Resolver.h"
#include <iostream>

int main(int argc, char * args[]){


	URL_Resolver * ures = new URL_Resolver();
	bool success = true;
	success = ures->Test(cout);

	if(success)
	cout << "All Tests Passed" << endl;
	else
	cout << "Failed One or More Tests" << endl;

	return 0;

}
#endif
