#include <iostream>
#include <string>
#include <vector>
#include "../../source/Vect.h"
#include "../../source/Rectangle.h"

using namespace std;

int main()
{
	//	premier constructeur
	Rectangle r1("rectangle1", 0, 5, 5, 0);
	//	second constructeur
	Vect p1(5,5);
	Vect p2(10,0);
	Rectangle r2("rectangle2", p1, p2);
	//	constructeur par copie
	Rectangle r3(r2);
	r3.SetName("rectangle3");
	//	surcharge du =
	Rectangle r4 = r3;
	r4.SetName("rectangle4");
	//	surcharge du << et Print
	cout << r1 << endl; 
	cout << r2 << endl; 
	cout << r3.Print() << endl; 
	cout << r4 << endl;
	//	méthode IsIn
	Vect p3(2,2);
	Vect p4(6,8);
	if(r1.IsIn(p3))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	if(r2.IsIn(p4))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	//	méthode Move
	Vect p5(1,1);
	r3.Move(p5);
	cout << r3 << endl;
	//	méthode GetWeight
	cout << r1.GetWeight() << endl;
	//	méthode GetLength
	cout << r3.GetLength() << endl;
	//	méthode Copy
	Rectangle *r5 = r1.Copy();
	cout << *r5 << endl;
	delete r5;
	return 0;
}