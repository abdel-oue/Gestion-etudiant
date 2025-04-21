#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

struct Module
{
	char NomModule[30];
	float Note;
	bool Check;
};
struct Semestre
{
	Module *M;
	int NombreModules;	
};
struct Student
{
    int NU;
    char Nom[20];
    int Age;
    struct 
    {
    	int Day;
	    int Month;
	    int Year;	
	} Date;
    Semestre *S;
};


void LoadModulesDefault(Student *&t,int x);

int Recherche(Student *t,int Nbr , int Numero)
{
	int i;
	for(i=0;i<Nbr;i++)
	{
		if(t[i].NU == Numero)
		{
			return i;
		}
	}
	return -1;
}
void Ajouter(Student *&t, int &Nbr)
{
	int S,i;
	
	if(Nbr==0)
	{
		t=(Student*)malloc(sizeof(Student));
	}
	else
	{
		realloc(t,sizeof(Student)*(Nbr + 1));
	}
		printf("Saisir le nom : ");
		scanf("%s",t[Nbr].Nom);
		printf("Saisir l'\xB6ge : ");
		scanf("%d",&t[Nbr].Age);
	if(Nbr==0)
	{
		printf("Sasir le numero unique : ");
		scanf("%d",&t[Nbr].NU);
	}
	else
	{
		do
		{
			printf("Sasir le numero unique : ");
			scanf("%d",&t[Nbr].NU);
			S=0;
			for(i=0;i<Nbr;i++)
			{
				if(t[Nbr].NU == t[i].NU)
				{
					S = 1;
				}
			}
		}while(S!=0);
	}	
		do
		{
			printf("Entrez le jour de naissance : ");
    		scanf("%d", &t[Nbr].Date.Day);
		}while(t[Nbr].Date.Day < 1 || t[Nbr].Date.Day > 31);
		do
		{
			printf("Entrez le mois de naissance : ");
	    	scanf("%d", &t[Nbr].Date.Month);
		}while(t[Nbr].Date.Month < 1 || t[Nbr].Date.Month > 12);
    	
    	do
    	{
    		printf("Entrez l'ann%ce de naissance : ",130);
    		scanf("%d", &t[Nbr].Date.Year);
		}while(t[Nbr].Date.Year > 2021 || t[Nbr].Date.Year < 1930);
		
		LoadModulesDefault(t,Nbr);
		Nbr++;
		
		// LoadModulesDefault(t,Nbr-1);
}
void Modifier(Student *t, int Nbr , int Numero)
{
	int pos;
	if(Nbr == 0)
	{
		printf("Tableau Vide !");
	}
	else
	{
		pos = Recherche(t,Nbr,Numero);
		
		if(pos == -1)
		{
			printf("\x82l\x82ment Introuvable");
		}
		else
		{
			printf("Saisir le nouveaux nom : ");
			scanf("%s",t[pos].Nom);
			printf("Saisir le nouvel \xB6ge : ");
			scanf("%d",&t[pos].Age);
			
			printf("Entrez le nouveaux jour de naissance : ");
	    	scanf("%d", &t[pos].Date.Day);
	    	printf("Entrez le nouveaux mois de naissance : ");
	    	scanf("%d", &t[pos].Date.Month);
			printf("Entrez la nouvelle ann%ce de naissance : ",130);
	    	scanf("%d", &t[pos].Date.Year);
		}	
	}	
}
void Supprimer(Student *&t,int &Nbr,int Numero)
{
	int i,Pos;
	if(Nbr == 0)
	{
		printf("Tableau Vide ! \n");
	}
	else if (Nbr == 1)
	{
		if(t[0].NU == Numero)
		{
			Nbr = 0;
			free(t);
		}
		else
		{
			printf("\x90tudiant introuvable \n");
		}
	}
	else
	{
		Pos = Recherche(t,Nbr,Numero);
		if(Pos != -1)
			{
				for(i=Pos;i<Nbr-1;i++)
				{
					t[i] = t[i+1];
				}
				realloc(t,sizeof(Student)*(Nbr - 1));
				Nbr--;
				printf("Supprim\x82 avec succ\x8As \n");
			}
			else
			{
				printf("\x90tudiant introuvable \n");
			}
	    }
}
void Lister(Student *t,int Nbr)
{
	int i;
	for(i=0;i<Nbr;i++)
	{
		printf("Nom : %s, NU : %d, \xB6ge : %d, Date : %d/%d/%d\n",t[i].Nom,t[i].NU,t[i].Age,t[i].Date.Day,t[i].Date.Month,t[i].Date.Year);
	}
}

