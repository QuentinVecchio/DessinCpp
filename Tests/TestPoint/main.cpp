#include <iostream>
#include "../../source/Point.h"

using namespace std;

int main()
{
	Point P1 (10,5);
	Point P2 (14,7);
	P2 = P2 + P1*3 ;
	Point P3 (P2);
	P2 = P2 * 10;
	cout << P1.Print() << endl << P2 << P3 << endl;
	return 0;
}