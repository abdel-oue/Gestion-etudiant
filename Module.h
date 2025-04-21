#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


void MenuNotes(Student *t,int Nbr,int NbrSemestres);
void MenuSemestres(Student *t,int Nbr,int &NbrSemestres);

void menu6()
{
	printf("----MENU---- \n 1) Gestion des Notes \n 2) Gestion des Modules \n 3) Gestion des Semestres \n 4) Retour \n");
}
void menu7()
{
	printf("----MENU MODULES---- \n 1) Ajouter un module \n 2) Supprimer un module \n 3) Modifier un module \n 4) Lister tout les modules \n 5) Recherche d'un module \n 6) Rechoisir un semestre \n 7) Retour \n");
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
void ChoisirSemestre(int NbrSemestres,int &Sem)
{
	ListSemestres(NbrSemestres);
	do
	{
		printf("Choisir un semestre (Veuillez entrer un numero) : ");
		scanf("%d",&Sem);
	}while(Sem<1 || Sem>NbrSemestres);
	Sem = Sem-1; // car choix = 1 --->>> S[0]
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
void ChoisirModule(Student *t,int NbrModules,int Sem,int &Module)
{
	ListModules(t,NbrModules,Sem);
	do
	{
		printf("Saisir le numero du module : ");
		scanf("%d",&Module);
	}while(Module < 1 && Module > NbrModules);
	Module = Module-1;
}
void Copytout(Student *&t,int Nbr,int oldNbr,int NbrSemestres) 
{
	int i,j,NbrM,k;
	for(i=oldNbr;i<Nbr;i++)
	{
		for(j=0;j<NbrSemestres;j++)
		{
			NbrM = t[0].S[j].NombreModules; // nombre module par semestre
			for(k=0;k<NbrM;k++)
			{
				strcpy(t[i].S[j].M[k].NomModule,t[0].S[j].M[k].NomModule);
			}
		}
	}
}
void LoadModulesDefault(Student *&t,int x,int option,int NbrSemestres)
{
	int i;
	t[x].S = (Semestre*)malloc(sizeof(Semestre)*NbrSemestres);
	
	for(i=0;i<NbrSemestres;i++)
	{
		t[x].S[i].M = (Module*)malloc(sizeof(Module)*t[0].S[i].NombreModules);
	}
	
	if(option == 1)
	{
		strcpy(t[x].S[0].M[0].NomModule,"Math"); // Default pour S1
		strcpy(t[x].S[0].M[1].NomModule,"Algo"); // Default pour S1
		strcpy(t[x].S[0].M[2].NomModule,"Prog C"); // Default pour S1
		strcpy(t[x].S[0].M[3].NomModule,"Anglais"); // Default pour S1
		
		strcpy(t[x].S[1].M[0].NomModule,"C++"); // Default pour S2
		strcpy(t[x].S[1].M[1].NomModule,"Python"); // Default pour S2
		strcpy(t[x].S[1].M[2].NomModule,"Proba"); // Default pour S2
		strcpy(t[x].S[1].M[3].NomModule,"TEC"); // Default pour S2
	}

	
}
// 1) Ajouter un module
void AjouterModule(Student *&t,int Nbr,int Sem,int &NbrModules)
{
	int i;
	char NModule[30];
	
	printf("Saisir le nom du module : ");
	scanf(" %[^\n]",NModule); // // %[^\n] lit les caractères jusqu'à ce qu'une nouvelle ligne soit rencontrée
	
	for(i=0;i<Nbr;i++)
	{
		if(NbrModules == 0)
		{
			t[i].S[Sem].M = (Module*)malloc(sizeof(Module));
		}
		else
		{
			t[i].S[Sem].M = (Module*)realloc(t[i].S[Sem].M,sizeof(Module)*(NbrModules+1));
		}
		strcpy(t[i].S[Sem].M[NbrModules].NomModule,NModule);
	}
	printf("Module ajout/x82 avec succ/x8As : %s !\n", NModule);
	NbrModules++;
}
// 2) Supprimer un module
void SupprimerModule(Student *&t,int Nbr,int Sem,int &NbrModules)
{
	int i,j;
	int pos;
	
	if(NbrModules == 0)
	{
		printf("Erreur : Il n'y a pas de module dans ce semestre");
	}
	else
	{
		system("cls");
		
		ChoisirModule(t,NbrModules,Sem,pos);
		
			for(i=0;i<Nbr;i++)
			{
				for(j=pos;j<NbrModules-1;j++)
				{
					t[i].S[Sem].M[j] = t[i].S[Sem].M[j+1];
				}
				
				if(NbrModules==1)
				{
					free(t[i].S[Sem].M);
				}
				else
				{
					t[i].S[Sem].M = (Module*)realloc(t[i].S[Sem].M,sizeof(Module)*(NbrModules-1));
				}
			}
		NbrModules--;
		printf("Module supprim/x82 avec succ/x8As ! \n");
	}
}
// 3) Modifier un module
void ModifierModule(Student *&t,int Nbr,int Sem,int NbrModules)
{
	int i,pos,S;
	
	system("cls");
	
	ChoisirModule(t,NbrModules,Sem,pos);
	
	
	printf("Saisir le nouveau nom du module :");
	scanf(" %[^\n]",t[0].S[Sem].M[pos].NomModule);
	
	printf("Voulez-vous r\x82initialiser toutes les notes? \n 1-Oui | 2-Non \n");
	scanf("%d",&S);
	for(i=0;i<Nbr;i++)
	{
		strcpy(t[i].S[Sem].M[pos].NomModule,t[0].S[Sem].M[pos].NomModule);
		if(S == 1)
		{
			t[i].S[Sem].M[pos].Note = 0;
			t[i].S[Sem].M[pos].Check = false;
		}
	}
	printf("Module modifi/x82 avec succ/x8As !\n");
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
				break;
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
	    
		ChoisirSemestre(NbrSemestres,Sem);
		
		NbrModules = t[0].S[Sem].NombreModules;
}
void MenuModules(Student *t,int Nbr,int NbrSemestres)
{
	int choix,i,Sem,NbrModules;
	system("cls");
	
	ChoisirSemestre(NbrSemestres,Sem);
	
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
				case 4 : ListModules(t,NbrModules,Sem);
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
	int oldNbr;
	int choix;
	if(Nbr != 0) // si tableau vide alors afficher erreur
	{
		if(Premierefois == true)
		{
			NbrSemestres = 2;
			t[0].S[0].NombreModules = 4;	
			t[0].S[1].NombreModules = 4; // les modules par default
			Premierefois = false;
		}
		else
		{
			Copytout(t,Nbr,oldNbr,NbrSemestres); // si l'utilisateur revient et ajoute un nouvel étudiant, les anciens modules s'appliqueront également au nouvel étudiant
		}
		system("cls");
		do
		{ 
			menu6();
			printf("Entrez votre choix :");
			scanf("%d",&choix);
				switch(choix)
				{
					case 1 : MenuNotes(t,Nbr,NbrSemestres);
					break;  
					case 2 : MenuModules(t,Nbr,NbrSemestres);
					break;
					case 3 : MenuSemestres(t,Nbr,NbrSemestres);
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
	oldNbr = Nbr;
}
