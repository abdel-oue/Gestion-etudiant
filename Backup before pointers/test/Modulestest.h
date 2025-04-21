#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void menu6()
{
	printf("----MENU---- \n 1) Gestion des Notes \n 2) Gestion des Modules \n 3) Gestion des Semestres \n 4) Retour \n");
}
void menu7()
{
	printf("----MENU MODULES---- \n 1) Ajouter un module \n 2) Supprimer un module \n 3) Modifier un module \n 4) Lister tout les modules \n 5) Recherche d'un module \n 6) Rechoisir un semestre \n 7) Retour \n");
}
void menu8()
{
	printf("----MENU SEMESTRES---- \n 1) Ajouter un semestre \n 2) Supprimer le contenue d'un semestre \n 3) Lister tout les semestre \n 4) Modifier les information d'un semestre \n 5) Vue d'ensemble des semestres \n 6) Retour \n"); // Vue d'Ensemble des Semestres: Provide a summary view of all semesters, including key information such as start dates, end dates, and the number of courses offered.
}
void ListSemestres(int NbrSemestres)
{
	int i;
	printf("List des Semestres : \n");
	for(i=0;i<NbrSemestres;i++)
	{
		printf("%d - Semestre %d (S%d) \n",i+1,i+1,i+1);
	}
}
// 4) Lister tout les modules
void ListModules(Student *t,int NbrModules,int Sem) // pour un seul semestre
{
	int i;
	system("cls");
	printf("List des Modules : \n");
	for(i=0;i<NbrModules;i++)
	{
		printf("%d - %s (M%d) \n",i+1,t[0].S[Sem].M[i].NomModule,i+1);
	}
}
void Copytout(Student *&t,int Nbr,int NbrModules,int Sem) // ajouter et modifier
{
	int i,j;
	// Sem = choisir semestre
	// bool si lutilisateur choisie de saisir tout les notes a 0
	for(i=1;i<Nbr;i++)
	{
		for(j=0;j<NbrModules;j++)
		{
			strcpy(t[i].S[Sem].M[j].NomModule,t[0].S[Sem].M[j].NomModule);
		
		}
	}
}
void LoadModulesDefault(Student *&t,int x)
{
	strcpy(t[x].S[0].M[0].NomModule,"Math"); // Default for S1
	strcpy(t[x].S[0].M[1].NomModule,"Algo"); // Default for S1
	strcpy(t[x].S[0].M[2].NomModule,"Prog C"); // Default for S1
	strcpy(t[x].S[0].M[3].NomModule,"Anglais"); // Default for S1
	
	strcpy(t[x].S[1].M[0].NomModule,"C++"); // Default for S1
	strcpy(t[x].S[1].M[1].NomModule,"Python"); // Default for S1
	strcpy(t[x].S[1].M[2].NomModule,"Bases de Donnees"); // Default for S1
	strcpy(t[x].S[1].M[3].NomModule,"TEC"); // Default for S1
}
// 1) Ajouter un module
void AjouterModule(Student *&t,int Nbr,int Sem,int &NbrModules)
{
	int choix,i;
	char NModule[30];
	
	printf("Saisir le nom du module : ");
	scanf("%s",NModule);
	
	for(i=0;i<Nbr;i++)
	{
		strcpy(t[i].S[Sem].M[NbrModules].NomModule,NModule);
	}
	
	NbrModules++;
	
}
// 2) Supprimer un module
void SupprimerModule(Student *&t,int Nbr,int Sem,int &NbrModules)
{
	int choix,i,k,j;
	char NModule[30];
	
	system("cls");
	ListModules(t,NbrModules,Sem);
	printf("Saisir le nom du module : ");
	scanf("%s",NModule);
	
	for(i=0;i<NbrModules;i++)
	{
		if(strcmp(t[0].S[Sem].M[i].NomModule,NModule) == 0)
		{
			for(k=0;k<Nbr;k++)
			{
				for(j=i;j<NbrModules-1;j++)
				{
					t[k].S[Sem].M[j] = t[k].S[Sem].M[j+1];
				}
			}
			break;
		}
	}
	NbrModules--;
}
// 3) Modifier un module
void ModifierModule(Student *&t,int Nbr,int Sem,int NbrModules)
{
	int choix,i,pos;
	char NModule[30];
	
	system("cls");
	ListModules(t,NbrModules,Sem);
	printf("Saisir le nom du module : ");
	scanf("%s",NModule);
	
	for(i=0;i<NbrModules;i++)
	{
		if(strcmp(t[0].S[Sem].M[i].NomModule,NModule) == 0)
		{
			printf("Saisir le nouveau nom du module :");
			scanf("%s",t[0].S[Sem].M[i].NomModule);
			pos = i;
			break;
		}
	}
	for(i=0;i<Nbr;i++)
	{
		strcpy(t[i].S[Sem].M[pos].NomModule,t[0].S[Sem].M[pos].NomModule);
	}
	printf("Voulez-vous remettre la note du module a 0 ?\n 1-Oui | 2-Non \n");
	scanf("%d",&S);
	for(i=0;i<Nbr;i++)
	{
		strcpy(t[i].S[Sem].M[pos].NomModule,t[0].S[Sem].M[pos].NomModule);
		if(S == 1)
		{
			t[i].S[Sem].M[pos].Note = 0;
		}
	}
}
// 5) Recherche d'un module
int RechercheModule(Student *t,int NbrSemestres)
{
	int i,j;
	char NModule[30];
	int pos;
	printf("Saisir le nom d'un module : ");
	scanf("%s",NModule);
	pos = -1;
	for(i=0;i<NbrSemestres;i++)
	{
		for(j=0;j<t[0].S[i].NombreModules;j++)
		{
			if(strcmp(NModule,t[0].S[i].M[j].NomModule) == 0)
			{
				printf("Le module est dans le semestre %d (M%d - %s)\n",i+1,j+1,NModule);
				pos = 0;
			}
		}
	}
	if(pos == -1)
	{
		printf("Module Introuvable.\n");
	}
}
// 6) Rechoisir un semestre
void Rechoisir(Student *t,int NbrSemestres,int &NbrModules,int &Sem)
{
		system("cls");
		
	    t[0].S[Sem].NombreModules = NbrModules; // ancien numéro
		ListSemestres(NbrSemestres);
		printf("Choisir un semestre (Veuillez entrer un numero) : ");
		do
		{
			scanf("%d",&Sem);
		}while(Sem<1 || Sem>NbrSemestres);
		Sem = Sem-1; // car choix = 1 --->>> S[0]
		
		NbrModules = t[0].S[Sem].NombreModules;
}
void MenuModules(Student *t,int Nbr,int NbrSemestres,int &NbrModules)
{
	int choix,i,Sem;
	system("cls");
	
	ListSemestres(NbrSemestres);
	printf("Choisir un semestre (Veuillez entrer un numero) : ");
	scanf("%d",&Sem);
	Sem = Sem-1; // car choix = 1 --->>> S[0]
	NbrModules = t[0].S[Sem].NombreModules; // t[0].S[Sem].NombreModules 
	system("cls");
	do
	{ 
		
		menu7();
		printf("Entrez votre choix :");
		scanf("%d",&choix);
			switch(choix)
			{
				case 1 : AjouterModule(t,Nbr,Sem,NbrModules);
				break;  
				case 2 : SupprimerModule(t,Nbr,Sem,NbrModules);
				break;
				case 3 : ModifierModule(t,Nbr,Sem,NbrModules);
				break;
				case 4 : ListerToutModules(t,Sem,NbrModules);
				break;
				case 5 : RechercheModule(t,NbrSemestres);
				break;
				case 6 : Rechoisir(t,NbrSemestres,NbrModules,Sem);
				break;
				default : break;		
			}
	getch();
	system("cls");
	}while(choix<7);
	t[0].S[Sem].NombreModules = NbrModules;
}
void MenuGestion(Student *t,int Nbr,int &NbrSemestres,bool Premierefois)
{
	int choix;
	int NbrModules;
	if(Nbr != 0) // si tableau vide alors afficher erreur
	{
		if(Premierefois == true)
		{
			NbrSemestres = 2;
			t[0].S[0].NombreModules = 4;	
			t[0].S[1].NombreModules = 4; // les modules par default
			Premierefois = false;
		}
		system("cls");
		do
		{ 
			menu6();
			printf("Entrez votre choix :");
			scanf("%d",&choix);
				switch(choix)
				{
					case 1 : MenuNotes(t,Nbr,NbrSemestres,NbrModules);
					break;  
					case 2 : MenuModules(t,Nbr,NbrSemestres,NbrModules);
					break;
					case 3 : 
					break;
					default : break;						
				}
		}while(choix<4);
	}
	else
	{
		system("cls");
		printf("Erreur : Le tableau est vide");
	}
}
/*
void ListEtudiantN(Student *t,int Nbr)
{
	int i;
	system("cls");
	printf("Liste des %ctudiants : (0 to go back)\n",130);
	for(i=0;i<Nbr;i++)
	{
		printf("%d : %s %d\n",i+1,t[i].Nom,t[i].NU);
	}
}
void MenuChoisir(Student *t,int Nbr);
void menu4();


void MenuChoisir(Student *t,int Nbr,int &choix)
{
	ListEtudiantN(t,Nbr);
	printf("Choisir l'\x82tudiant :");
	scanf("%d",&choix); // choix = 1  ---- > t[0] 
	
}
void AjouterNotes(Student *t)
{
	int pos;
	MenuChoisir(t,Nbr,pos);
	pos--; // // pos = 1  ---- > t[0]
	if(pos != 0) // l'utilisateur n
	{
		
	} 
	
} //1

void MoyenneNotes(){} //2
void ModifierNotes(){} //3
void StatistiquesNotes(){} //4
void DistributionNotes(){} //5
void ModifierModules(Student *t,int Nbr)
{
	int i;
	for(i=0;i<Nbr;i++)
	{
		printf("Saisir un nom pour M1 (%s)",t[i].N.M1.NomM);
	}
}
void LoadNotes(){} //6
void SaveNotes(){} //7 
*/

