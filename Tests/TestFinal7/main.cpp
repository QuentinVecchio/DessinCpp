/*************************************************************************
                           main.cpp  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>
#include "../../Source/Dessin.h"
#include "../../Source/Fonctions.h"
#include "../../Source/UndoRedo.h"
using namespace std;
//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//------------------------------------------------------------- Prototypes

//---------------------------------------------------------- Fonction main

int main()
{
	string commande = "";
	Dessin *d = new Dessin("Dessin");
	UndoRedo *pile = new UndoRedo(20);
	map<string,Figure*> *exclu = new map<string,Figure*>();
	bool stop = false;
	do
	{	cin.tie(0);
		if(getline(cin,commande))
		{	stop = interpretreCommande(commande, d, pile, exclu, false);
		}
		else
		{	stop = true;
		}
	}while(stop == false);
	delete pile;
	return 0;
}
