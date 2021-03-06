/*************************************************************************
                           Fonctions  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/

//-----------------------------------------------------------------------
//	Ce fichier contient des fonctions utilisées dans notre projet
//-----------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Dessin.h"
#include "Vect.h"
    
//---------------------------- Fonctions --------------------------------
int Parseur(const string & donnees, const char separateur, string *tab, const int taille);
bool interpreteCommande(string commande, Dessin **dessin, UndoRedo *pile, map<string,Figure*> *exclu, map<string,Dessin*> *dessinExclu, bool callByUndoRedo);
string getCommande(string commande);
int getNbParametre(string commande);
string getParametre(string commande, int n);