#include <iostream>
#include <string>
#include <vector>
#include "../../source/Dessin.h"
#include "../../source/Rectangle.h"
#include "../../source/Point.h"

using namespace std;

int main()
{
	//	Constructeur
	Dessin d1("dessin1");
	Rectangle *r1 = new Rectangle("rectangle1", 0, 2, 2, 0);
	d1.Add(r1);
	//	Constructeur par copie
	Dessin d2(d1);
	d2.SetName("dessin2");
	//	Surcharge du =
	Dessin d3 = d1;
	d3.SetName("dessin3");
	//	Méthode Add
	Rectangle *r2 = new Rectangle("rectangle2", 0, 5, 5, 0);
	d1.Add(r2);
	//	Surcharge du << et Print
	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	//	Méthode Move
	Point p1(2,2);
	d1.Move(p1);
	cout << d1 << endl;
	//	Méthode Move 2
	Point p2(2,2);
	d1.MoveFigure("rectangle2",p2);
	cout << d1 << endl;
	//	Méthode IsIn
	Point p3(3,2);
	Point p4(15,2);
	cout << d1.IsIn(p3) << endl;
	cout << d1.IsIn(p4) << endl;
	//	Méthode IsIn 2
	Point p5(2,1);
	Point p6(8,6);
	cout << d1.IsInFigure("rectangle1",p5) << endl;
	cout << d1.IsInFigure("rectangle2",p6) << endl;
	//	Méthode Remove
	cout << d1.Remove("rectangle2") << endl;
	cout << d1.Remove("rectangle3") << endl;
	cout << d1.Remove("rectangle1") << endl;
	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	//	Méthode Save
	//	Méthode Load
	//	Méthode Undo
	//	Méthode Redo
	return 0;
}