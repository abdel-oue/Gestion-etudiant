#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "GestionsEtudiant.h"
#include "Module.h"
#include "Notes.h"
#include "Fichiers.h"
#include "Settings.h"

void menu1() // MEnu
{
	printf("----MENU---- \n 1) Gestion d'\x82tudiants \n 2) Fichiers \n 3) Param%ctres \n 4) Quitter \n",130,138);
}
void menu2() // Menu Etudiant
{
	printf("----MENU ETUDIANT---- \n 1) Ajouter \n 2) Modifier \n 3) Supprimer \n 4) Lister \n 5) Gestion des notes et des modules \n 6) Retour \n");
}
void menu3() // Menu Fichier
{
	printf("----MENU FICHIER---- \n 1) Sauvegarder texte \n 2) Charger texte \n 3) Sauvegarder binaire \n 4) Charger binaire \n 5) Afficher un fichier \n 6) Supprimer un fichier \n 7) Lister tous les fichiers \n 8) Retour \n");
}
void menu4() // Menu Notes
{	
	printf("----MENU NOTES---- \n 1) Ajouter des notes \n 2) Calculer la moyenne \n 3) Modification des notes \n 4) Statistiques des notes \n 5) Distribution des notes \n 6) Modifier Les Modules \n 7) Charger Notes \n 8) Sauvegarder Notes \n 9) Retour \n");
}
void menu5() // Menu Settings
{
	printf("----SETTINGS---- \n 1) Modifier les param%ctres d'affichage \n 2) Changer la langue du programme \n 3) Pr%cf%crences de l'utilisateur \n 4) %c propos du projet \n 5) Retour \n",138,130,130,183);
}



main()   
{
	FILE *f= NULL;
	Student *t;
	int choix,choix2,choix3,a;
	bool Premierefois = true;
	int Numero,Nbr=0,NbrSemestres=0;
	char Nom[50];
	do
	{
		// system("color 80");
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
										Ajouter(t,Nbr);
							break;
							case 2:
										printf("Saisir le Numero Unique");
										scanf("%d",&Numero);
										Modifier(t,Nbr,Numero);
							break;
							case 3: 
										printf("Saisir le Numero Unique");
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
							case 1 :	ListFichier(1,Nom); // option 1 pour saisir un nom et 0 pour rien saisir 
										Savetxt(t,Nbr,Nom,NbrSemestres);
							break;
							case 2 :
										ListFichier(1,Nom);
										Loadtxt(t,Nbr,Nom,NbrSemestres,Premierefois);
							break;
							case 3 :	ListFichier(1,Nom);
										Savebin(t,Nbr,Nom);
							break;
								
							case 4 :	ListFichier(1,Nom);
										Loadbin(t,Nbr,Nom);
							break;
							case 5 :
									ListFichier(1,Nom);
									AfficherFichier(Nom);
							break;
							case 6 : 	
									ListFichier(1,Nom);
									SupprimerFichier(Nom);	
							break;
							case 7 :	ListFichier(0,Nom);
							break;
						}
						getch();
						system("cls"); 
					}while(choix2<8);
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
								case 1 :	break;
								case 2 :	break;
								case 3 :	break;
								case 4 :	break;	
						}
						getch();
						system("cls");
					}while(choix2<5);
					system("cls");
		}
	}while(choix<4);
}
