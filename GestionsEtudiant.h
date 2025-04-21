#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date
{
	int Day;
	int Month;
	int Year;
};
struct Module
{
	char NomModule[30];
	float Note; // tableau note Note[0] = Note Controle , Note[1] = Note Partiel , Note[2] Note TP
	bool Check;
	// int Coeffi; // coefficient
	//char Enseig[30]; // Enseingeur
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
    Date Date;
    Semestre *S;
};


void LoadModulesDefault(Student *&t,int x,int option,int NbrSemestres);

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
void Ajouter(Student *&t, int &Nbr,bool Premierefois,int NbrSemestres)
{
	int S,i;
	int age,age1;
	Student *Temp=(Student*)malloc(sizeof(Student));
	
	if(Nbr==0)
	{
		t=(Student*)malloc(sizeof(Student));
	}
	else
	{
		t =(Student*)realloc(t,sizeof(Student)*(Nbr+1));
	}
		printf("Saisir le nom : ");
		scanf("%s",Temp[0].Nom);
		printf("Saisir l'\xB6ge : ");
		scanf("%d",&Temp[0].Age);
	if(Nbr==0)
	{
		printf("Sasir le numero unique : ");
		scanf("%d",&Temp[0].NU);
	}
	else
	{
		do
		{
			printf("Sasir le numero unique : ");
			scanf("%d",&Temp[0].NU);
			S=0;
			for(i=0;i<Nbr;i++)
			{
				if(Temp[0].NU == t[i].NU)
				{
					S = 1;
				}
			}
		}while(S!=0);
	}	
		do
		{
			printf("Entrez le jour de naissance : ");
    		scanf("%d",&Temp[0].Date.Day);
		}while(Temp[0].Date.Day < 1 || Temp[0].Date.Day > 31);
		do
		{
			printf("Entrez le mois de naissance : ");
	    	scanf("%d",&Temp[0].Date.Month);
		}while(Temp[0].Date.Month < 1 || Temp[0].Date.Month > 12);
    	
    	do
    	{
    		printf("Entrez l'ann%ce de naissance : ",130);
    		scanf("%d",&Temp[0].Date.Year);
		}while(Temp[0].Date.Year > 2021 || Temp[0].Date.Year < 1930);
		
		age = 2024 - Temp[0].Date.Year ;
		age1 = 2024 - Temp[0].Date.Year - 1;
		
		if(age1 != Temp[0].Age && age != Temp[0].Age)
		{
			printf("L'\xB6ge fourni ne correspond pas \x85 l'ann%ce de naissance. Veuillez r%cessayer.\n",130,130);
		}
		else
		{
			t[Nbr] = Temp[0];
			if(Premierefois == true)
			{
				LoadModulesDefault(t,Nbr,1,NbrSemestres);
				Premierefois = false;
			}
			else
			{
				LoadModulesDefault(t,Nbr,0,NbrSemestres);
			}
			Nbr++;
			printf("\xC9tudiant ajout\x82 avec succ\x8Es !\n");
		}
		free(Temp);
}
void Modifier(Student *t, int Nbr , int Numero)
{
	int pos,age,age1;
	Student *Temp=(Student*)malloc(sizeof(Student));

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
			Temp[0].NU = t[pos].NU;
			
			printf("Saisir le nom : ");
			scanf("%s",Temp[0].Nom);
			printf("Saisir l'\xB6ge : ");
			scanf("%d",&Temp[0].Age);
				do
			{
				printf("Entrez le jour de naissance : ");
	    		scanf("%d",&Temp[0].Date.Day);
			}while(Temp[0].Date.Day < 1 || Temp[0].Date.Day > 31);
			do
			{
				printf("Entrez le mois de naissance : ");
		    	scanf("%d",&Temp[0].Date.Month);
			}while(Temp[0].Date.Month < 1 || Temp[0].Date.Month > 12);
	    	
	    	do
	    	{
	    		printf("Entrez l'ann%ce de naissance : ",130);
	    		scanf("%d",&Temp[0].Date.Year);
			}while(Temp[0].Date.Year > 2021 || Temp[0].Date.Year < 1930);
			
			age = 2024 - Temp[0].Date.Year ;
			age1 = 2024 - Temp[0].Date.Year - 1;
			
			if(age1 != Temp[0].Age && age != Temp[0].Age)
			{
				printf("L'\xB6ge fourni ne correspond pas \x85 l'ann%ce de naissance. Veuillez r%cessayer.\n",130,130);
			}
			else
			{
				t[pos] = Temp[0];
			}
			free(Temp);
			printf("\xC9tudiant modifi\x82 avec succ\x8Es !\n");
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
				printf("\xC9tudiant supprim\x82 avec succ\x8Es !\n");
			}
			else
			{
				printf("\x90tudiant introuvable \n");
			}
	    }
}
void Lister(Student *t, int Nbr)
{
    int i;
	system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");

    printf("\xBA %-20s \xBA %-10s \xBA %-8s \xBA %-12s \xBA\n", "Nom", "NU", "Age", "Date");

    printf("\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9\n");

    for (i=0;i<Nbr;i++)
    {
    	printf("\xBA %-20s \xBA %-10d \xBA %-8d \xBA %02d/%02d/%-6d \xBA\n", t[i].Nom, t[i].NU, t[i].Age, t[i].Date.Day, t[i].Date.Month, t[i].Date.Year);
    }
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
}

