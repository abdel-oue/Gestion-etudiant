#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void menu9()
{
	printf("----MENU NOTES---- \n 1) Ajouter des Notes \n 2) Modifier des Notes \n 3) Supprimer tout les notes d'un module \n 4) Statistiques des notes \n 5) Afficher tout les notes \n 6) Rechoisir un semestre \n 7) Retour \n");
}

void MenuNotes(Student *t,int Nbr,int NbrSemestres,int &NbrModules)
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
