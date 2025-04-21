#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void menu9() // Supprimer tout les notes d'un module 
{
	printf("----MENU NOTES---- \n 1) Ajouter des Notes \n 2) Supprimer des Notes \n 3) Modifier des Notes \n 4) Statistiques des notes \n 5) Afficher tout les notes \n 6) Rechoisir un semestre \n 7) Retour \n");
}
void Rechoisir(Student *t,int NbrSemestres,int &NbrModules,int &Sem);
void ListModules(Student *t,int NbrModules,int Sem);

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
void AfficherNotes(Student *t,int Nbr,int Sem,int NbrModules) // par chat gpt
{
	int i,j;
	system("cls");
	    printf("\xC9");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCB");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    for (i = 0; i < NbrModules; i++) 
	{
        printf("\xCB");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    }
    printf("\xBB\n");

    // Print headers
    printf("\xBA %-20s \xBA %-8s ", "Nom", "ID");
    for (i = 0; i < NbrModules; i++) 
	{
        printf("\xBA %-9s ", t[0].S[Sem].M[i].NomModule);
    }
    printf("\xBA\n");

    // Print middle border
    printf("\xCC");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCE");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    for (i = 0; i < NbrModules; i++) 
	{
        printf("\xCE");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    }
    printf("\xB9\n");

    // Print student data
    for (i = 0; i < Nbr; i++) 
	{
        printf("\xBA %-20s \xBA %-8d ", t[i].Nom, t[i].NU);
        for (j = 0; j < NbrModules; j++) 
		{
        	if(t[i].S[Sem].M[j].Check == true) // Supprimer cette ligne pour afficher tout les notes
        	{
        		printf("\xBA %7.2f   ", t[i].S[Sem].M[j].Note);
			}
			else
			{
				printf("\xBA    %-7s", "N/A");
			}
        }
        printf("\xBA\n");
    }

    // Print bottom border
    printf("\xC8");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCA");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    for (i = 0; i < NbrModules; i++) 
	{
        printf("\xCA");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    }
    printf("\xBC\n");
}

void ModifierNotes(Student *&t,int Nbr,int Sem,int NbrModules,bool option)
{
	int pos,Num,i;
	system("cls");
	
	ListModules(t,NbrModules,Sem);
	printf("Saisir le numero du module :");
	do
	{
		scanf("%d",&pos);
	}while(pos > NbrModules || pos < 1);
	pos = pos-1;
	
	
	system("cls");
	printf("------ %s ------ \n",t[0].S[Sem].M[pos].NomModule);
	
	for(i=0;i<Nbr;i++)
	{
		printf("%d - Nom : %s\t | Note : %.2f \n",i+1,t[i].Nom,t[i].S[Sem].M[pos].Note);
	}
	
	printf("Saisir le numero de l'etudiant : ");
	do
	{
		scanf("%d",&Num);
	}while(Num > Nbr || Num < 1);
	Num = Num-1;
	printf("Saisir la note de l'etudiant : ");
	do
	{
		scanf("%f",&t[Num].S[Sem].M[pos].Note);
	}while(20 < t[Num].S[Sem].M[pos].Note || t[Num].S[Sem].M[pos].Note < 0);
	
	if(option == 1)
	{
		t[Num].S[Sem].M[pos].Check = true;
	}
	printf("Done !");
}
void StatistiqueNotes(Student *t,int Nbr,int Sem,int NbrModules)
{
	int i,j,Max,Min,pc=0;
	float cp=0,Moyenne;
	float Nbrfloat=Nbr;
	float NbrModulesfloatttt=NbrModules;
	float cal,TauxReu,TauxEch;
	
	printf("Module          | Max Note | Min Note |  Moyenne  | Reussite |   Echec  |\n");
    printf("----------------------------------------------------------------------\n");
    
	for(i=0;i<NbrModules;i++)
	{
		Max = t[0].S[Sem].M[i].Note;
		Min = t[0].S[Sem].M[i].Note;
		Moyenne = 0;
		cp =0;
		for(j=0;j<Nbr;j++)
		{
			if(Max < t[j].S[Sem].M[i].Note) // 1) Note la plus élevée
			{
				Max = t[j].S[Sem].M[i].Note;
			}
			if(Min >= t[j].S[Sem].M[i].Note) // 2) Note la plus basse
			{
				if(t[j].S[Sem].M[i].Check == true)
				{
					Min = t[j].S[Sem].M[i].Note;
				}
			}
			if(t[j].S[Sem].M[i].Note >= 10) // Le taux de réussite et Taux d'échec
			{
				cp = cp +1 ;
			}
			Moyenne = t[j].S[Sem].M[i].Note + Moyenne; // moyenne
		}
		
		Moyenne = Moyenne/Nbrfloat;
		cal = ( cp /Nbrfloat );
		TauxReu = cal * 100;
		TauxEch = 100 - TauxReu;
		
	printf("%-10s \t| %8d | %8d |  %7.2f  | %7.2f%% | %7.2f%% | \n", t[0].S[Sem].M[i].NomModule, Max, Min, Moyenne, TauxReu, TauxEch);
	}
	
}
void SupprimerNotes(Student *&t,int Nbr,int Sem,int &NbrModules)
{
	int pos,Num,i;
	system("cls");
	
	ListModules(t,NbrModules,Sem);
	printf("Saisir le numero du module :");
	do
	{
		scanf("%d",&pos);
	}while(pos > NbrModules || pos < 1);
	pos = pos-1;
	
	
	system("cls");
	printf("------ %s ------ \n",t[0].S[Sem].M[pos].NomModule);
	
	for(i=0;i<Nbr;i++)
	{
		printf("%d - Nom : %s\t | Note : %.2f \n",i+1,t[i].Nom,t[i].S[Sem].M[pos].Note);
	}
	
	printf("Saisir le numero de l'etudiant : ");
	do
	{
		scanf("%d",&Num);
	}while(Num > Nbr || Num < 1);
	
	Num = Num-1;
	
		t[Num].S[Sem].M[pos].Check = false;
		
	printf("Done !");
}
void MenuNotes(Student *t,int Nbr,int NbrSemestres)
{
	int choix,i,Sem,NbrModules;
	system("cls");
	
	ListSemestres(NbrSemestres);
	printf("Choisir un semestre (Veuillez entrer un numero) : ");
	do
	{
		scanf("%d",&Sem);
	}while(Sem > NbrSemestres || Sem < 1);
	Sem = Sem-1; // car choix = 1 --->>> S[0]
	NbrModules = t[0].S[Sem].NombreModules; // t[0].S[Sem].NombreModules 
	
	system("cls");
	do
	{ 
		
		menu9();
		printf("Entrez votre choix :");
		scanf("%d",&choix);
			switch(choix)
			{
				case 1 : ModifierNotes(t,Nbr,Sem,NbrModules,1); // check == true pour laffichage
				break;  
				case 2 : SupprimerNotes(t,Nbr,Sem,NbrModules);
				break;
				case 3 : ModifierNotes(t,Nbr,Sem,NbrModules,0);
				break;
				case 4 : StatistiqueNotes(t,Nbr,Sem,NbrModules);
				break;
				case 5 : AfficherNotes(t,Nbr,Sem,NbrModules);
				break;
				case 6 : Rechoisir(t,NbrSemestres,NbrModules,Sem);
				break;
				default : break;		
			}
	getch();
	system("cls");
	}while(choix<7);
}
/*void AfficherNotes(Student *t,int Nbr,int Sem,int NbrModules) // par chat gpt
{
	int i,j;
	system("cls");
	printf("\xC9");
	for(i=0;i<NbrModules;i++)
	{
		printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	}
	printf("\n");
	printf("\xB2\xB2 Nom \xB2 ID \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	for(i=0;i<NbrModules;i++)
	{
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
	printf("\n");
	for(j=0;j<NbrModules;j++)
		{
			printf(" %s \xB2\xB2\xB2",t[0].S[Sem].M[j].NomModule);
		}
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n");
	for(i=0;i<Nbr;i++)
	{
		printf("\xB2\xB2 %s\t \xB2\xB2 %d\t \t\xB2\xB2\xB2",t[i].Nom,t[i].NU);
		for(j=0;j<NbrModules;j++)
		{
			printf(" %.2f \xB2\xB2\xB2",t[i].S[Sem].M[j].Note);
		}
		printf("\n");
	}
}*/
