/*************************************************************************
                           Fonctions  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/
#include "Fonctions.h"

//---------------------------- Fonctions --------------------------------
int Parseur(const string & donnees, const char separateur, string *tab, const int taille)
{
	int p = 0;
	string m = "";
	for(int i=0;i<donnees.length();i++)
	{	if(p< taille)
		{	if(donnees[i] != separateur)
			{	m +=  donnees[i];
			}
			else
			{	tab[p] = m;
				m = "";
				p++;
			}
		}
		else
		{	break;
		}
	}
	if(m != "" && p< taille)
	{	tab[p] = m;
		p++;
	}
	return p;
}

bool interpretreCommande(string commande, Dessin &dessin) 
	{
		string nomCommande = getCommande(commande);
		int nParam = getNbParametre(commande);
		if(nomCommande == "ADD")
		{	dessin.AddByCmd(commande);
		}
		else if(nomCommande == "MOVE" && nParam == 3)
		{	int x = atoi(getParametre(commande,2).c_str());
			int y = atoi(getParametre(commande,3).c_str());
			Vect p(x,y);
			dessin.IsInFigure(getParametre(commande,1),p);
		}
		else if(nomCommande == "LIST")
		{	cout << dessin << endl;
		}
		else if(nomCommande == "DELETE" && nParam >= 1)
		{	string name;
			for(int i=1;i<nParam;i++)
			{
				name = getParametre(commande,i);
				dessin.Remove(name);
			}
		}
		else if(nomCommande == "MOVE" && nParam == 3)
		{	int x = atoi(getParametre(commande,2).c_str());
			int y = atoi(getParametre(commande,3).c_str());
			Vect p(x,y);
			dessin.MoveFigure(getParametre(commande,1),p);
		}
		else if(nomCommande == "REDO" && nParam == 1)
		{	dessin.Redo();
		}
		else if(nomCommande == "UNDO" && nParam == 1)
		{	dessin.Undo();
		}
		else if(nomCommande == "SAVE" && nParam == 1)
		{	dessin.Save(getParametre(commande,1));
		}
		else if(nomCommande == "LOAD" && nParam == 1)
		{	dessin.Load(getParametre(commande,1));
		}
		else if(nomCommande == "CLEAR")
		{	dessin.RemoveAll();
		}
		else if(nomCommande == "EXIT")
		{	return true;
		}
		return false;
	}

string getCommande(string commande)
{
	string nomCommande = "";
	for(int i=0;i<commande.length();i++)
	{	if(commande[i] == ' ' || commande[i] == '\n')
		{	break;
		}
		nomCommande += commande[i];
	}
	return nomCommande;
}

int getNbParametre(string commande) 
{
	int nbParametre = 0;
	for(int i=0;i<commande.length();i++)
	{	if(commande[i] == ' ')
			nbParametre++;
	}
	return nbParametre;
}

string getParametre(string commande, int n)
{
	int numeroParam = 0;
	string param = "";
	for(int i=0;i<commande.length();i++)
	{	if(commande[i] == ' ')
		{	numeroParam++;
		}
		if(numeroParam == n)
		{	i++;
			while(commande[i] != ' ' && commande[i] != '\n' && commande[i] != '\0' )
			{	param += commande[i];
				i++;
			}
			break;
		}
	}
	return param;
}