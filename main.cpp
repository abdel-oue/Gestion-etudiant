#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "GestionsEtudiant.h"
#include "Module.h"
#include "Notes.h"
#include "Semestres.h"
#include "Fichiers.h"
#include "Settings.h"

void menu1() //
{
	printf("----MENU---- \n 1) Gestion d'\x82tudiants \n 2) Fichiers \n 3) Param%ctres \n 4) Quitter \n",130,138);
}
void menu2() // Menu Etudiant
{
	printf("----MENU ETUDIANT---- \n 1) Ajouter \n 2) Modifier \n 3) Supprimer \n 4) Lister \n 5) Gestion des notes et des modules \n 6) Retour \n");
}
void menu3() // Menu Fichier
{
	printf("----MENU FICHIER---- \n 1) Sauvegarder texte \n 2) Charger texte \n 3) Sauvegarder binaire \n 4) Charger binaire \n 5) Supprimer un fichier \n 6) Lister tous les fichiers \n 7) Retour \n");
}
void menu5() // Menu Settings
{
	printf("----SETTINGS---- \n 1) Modifier les param%ctres d'affichage \n 2) %c propos du projet \n 3) Retour \n",138,183);
}
main()   
{
	FILE *f= NULL;
	Student *t;
	int choix,choix2,choix3,a;
	bool Premierefois = true;
	int Numero,Nbr=0,NbrSemestres=2;
	char Nom[50];
	do
	{
		do
		{
			menu1(); 
			printf("Entrez votre choix :");
			scanf("%d",&choix);
			switch(choix)
			{
				case 1:		
						system("cls");	
						do
						{
							menu2();
							printf("Entrez votre choix :");
							scanf("%d",&choix2);
							switch(choix2)
							{
								case 1:
											Ajouter(t,Nbr,Premierefois,NbrSemestres);
								break;
								case 2:		Lister(t,Nbr);
											printf("Saisir le Numero Unique : ");
											scanf("%d",&Numero);
											Modifier(t,Nbr,Numero);
								break;
								case 3: 	Lister(t,Nbr);
											printf("Saisir le Numero Unique : ");
											scanf("%d",&Numero);
											Supprimer(t,Nbr,Numero);
								break;
								case 4:
											Lister(t,Nbr);
								break;
								case 5:
											MenuGestion(t,Nbr,NbrSemestres,Premierefois);
								break;
								default:break;	
							}
							getch();
							system("cls");
									
						}while(choix2<6);
						system("cls");
				break;
					
				case 2:	
						system("cls");
						do
						{
							menu3();
							printf("Entrez votre choix :");
							scanf("%d",&choix2);
							switch(choix2)
							{
								case 1 :	ListFichier(1,0,Nom); // option 1 pour saisir un nom et 0 pour rien saisir 
											Savetxt(t,Nbr,Nom,NbrSemestres);
								break;
								case 2 :
											ListFichier(1,0,Nom);
											Loadtxt(t,Nbr,Nom,NbrSemestres,Premierefois);
								break;
								case 3 :	ListFichier(1,1,Nom);
											Savebin(t,Nbr,NbrSemestres,Nom);
								break;
									
								case 4 :	ListFichier(1,1,Nom);
											Loadbin(t,Nbr,NbrSemestres,Nom,Premierefois);
								break;
								case 5 :	ListFichier(1,2,Nom);
											SupprimerFichier(Nom);
								break;
								case 6 : 	ListFichier(0,2,Nom);
								break;
								
								default: break;
							}
							getch();
							system("cls"); 
						}while(choix2<7);
						system("cls");
					break;		
					
				case 3 : 
						system("cls");
						do
						{
							menu5();
							printf("Entrez votre choix :");
							scanf("%d",&choix2);
							switch(choix2)
							{
									case 1 : Colors();
									break;
									case 2 : Apropos();
									break;
									default: 
									break;
							}
							getch();
							system("cls");
						}while(choix2<3);
						system("cls");
			}
		}while(choix<4);
		
		system("cls");
		printf("\xD2tes-vous s\x96r de vouloir quitter ? \n 1-Oui | 2-Non | 3-Sauvegarder avant de quitter \n");
		scanf("%d",&choix);
		if(choix == 3)
		{
			system("cls");
			printf("----QUITTER ? ----\n");
			printf(" 1) Sauvegarder texte \n 2) Sauvegarder binaire \n 3) Quitter\nSaisir votre choix : ");
			scanf("%d",&choix2);
			
			if(choix2 == 1)
			{
				Savetxt(t,Nbr,Nom,NbrSemestres);
				printf("Done !");
			}
			else if(choix2 == 2)
			{
				Savebin(t,Nbr,NbrSemestres,Nom);
				printf("Done !");
			}
		}
		system("cls"); // choix == 2;
	}while(choix != 1 && choix != 3);
}
