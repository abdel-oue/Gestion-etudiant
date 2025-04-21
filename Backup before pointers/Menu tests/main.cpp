#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void menu1() // MEnu
{
	printf("\t\t\t\t\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\n");
	printf("\t\t\t\t\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0MENU\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0 \n\t\t\t\t\xB0\xB0 1) Gestion d'\x82tudiants\t\t\xB0 \n\t\t\t\t\xB0\xB0 2) Fichiers\t\t\t\t\xB0 \n\t\t\t\t\xB0\xB0 3) Param%ctres\t\t\t\xB0 \n\t\t\t\t\xB0\xB0 4) Quitter\t\t\t\t\xB0 \n",130,138);
	printf("\t\t\t\t\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\n\t\t\t\t");

}
void menu2() // Menu Etudiant
{
	printf("\t\t\t\t\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\n");
	printf("\t\t\t\t\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0MENU ETUDIANT\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0");
	printf("\n\t\t\t\t\xB0\xB0 1) Ajouter\t\t\t\t\xB0 \n\t\t\t\t\xB0\xB0 2) Modifier\t\t\t\t\xB0 \n\t\t\t\t\xB0\xB0 3) Supprimer\t\t\t\t\xB0 \n\t\t\t\t\xB0\xB0 4) Lister\t\t\t\t\xB0 \n\t\t\t\t\xB0\xB0 5) Gestion de note\t\t\t\xB0 \n\t\t\t\t\xB0\xB0 6) Retour\t\t\t\t\xB0 \n");
	printf("\t\t\t\t\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\n\t\t\t\t");

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
	int choix,choix2,choix3,a;
	int Numero,Nbr=0;
	char Nom[50];
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
										
							break;
							case 2:
										
							break;
							case 3: 
										
							break;
							case 4: 
										
							break;
							case 5:
										
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
							case 1 :	
							break;  
							case 2 :
										
							break;
							case 3 :	
							break;
										
							case 4 :	
							break;
							case 5 :
										
							break;
							case 6 : 	
									
							break;
							case 7 :	
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

