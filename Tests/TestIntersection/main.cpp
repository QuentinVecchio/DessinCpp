#include <iostream>
#include <string>
#include <vector>
#include "../../source/Intersection.h"
#include "../../source/Rectangle.h"
#include "../../source/Vect.h"

using namespace std;

int main()
{
	//	Constructeur
	Intersection i1("intersection1");
	Rectangle *r1 = new Rectangle("rectangle1", 0, 2, 2, 0);
	i1.Add(r1);
	//	Constructeur par copie
	Intersection i2(i1);
	i2.SetName("intersection2");
	//	Surcharge du =
	Intersection i3 = i1;
	i3.SetName("intersection3");
	//	Méthode Add
	Rectangle *r2 = new Rectangle("rectangle2", 1, 5, 5, 0);
	i1.Add(r2);
	//	Surcharge du << et Print
	cout << i1 << endl;
	cout << i2 << endl;
	cout << i3 << endl;
	//	Méthode Move
	Vect p1(2,2);
	i1.Move(p1);
	cout << i1 << endl;
	//	Méthode IsIn
	Vect p3(4,3);
	Vect p4(15,2);
	if(i1.IsIn(p3))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	if(i1.IsIn(p4))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	//	Méthode Remove
	i1.Remove("rectangle2");
	i1.Remove("rectangle3");
	i1.Remove("rectangle1");
	cout << i1 << endl;
	cout << i2 << endl;
	cout << i3 << endl;
	return 0;
}