#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void menu9() // Supprimer tout les notes d'un module 
{
	printf("----MENU NOTES---- \n 1) Ajouter des Notes \n 2) Supprimer des Notes \n 3) Modifier des Notes \n 4) Statistiques des notes \n 5) Afficher tout les notes \n 6) Moyenne des \x82tudiants \n 7) Rechoisir un semestre \n 8) Retour \n");
}
void Rechoisir(Student *t,int NbrSemestres,int &NbrModules,int &Sem);
void ChoisirModule(Student *t,int NbrModules,int Sem,int &Module);
void ChoisirSemestre(int NbrSemestres,int &Sem);

void AfficherNotes(Student *t,int Nbr,int Sem,int NbrModules)
{
	int i,j;
	system("cls");
	printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    for (i = 0; i < NbrModules; i++) 
	{
        printf("\xCB");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    }
    printf("\xBB\n\xBA %-20s \xBA %-8s ", "Nom", "ID");
    for (i = 0; i < NbrModules; i++) 
	{
        printf("\xBA %-9s ", t[0].S[Sem].M[i].NomModule);
    }
    printf("\xBA\n\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    for (i = 0; i < NbrModules; i++) 
	{
        printf("\xCE");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    }
    printf("\xB9\n");
    
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
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    for (i = 0; i < NbrModules; i++) 
	{
        printf("\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    }
    printf("\xBC\n");
}

void ModifierNotes(Student *&t,int Nbr,int Sem,int NbrModules,bool option)
{
	int pos,Num,i;
	system("cls");
	
	ChoisirModule(t,NbrModules,Sem,pos);
	
	system("cls");
	printf("------ %s ------ \n",t[0].S[Sem].M[pos].NomModule);
	
	for(i=0;i<Nbr;i++)
	{
		if(t[i].S[Sem].M[pos].Check == true)
		{
			printf("%d - Nom : %s\t | Note : %.2f \n",i+1,t[i].Nom,t[i].S[Sem].M[pos].Note);
		}
		else
		{
			printf("%d - Nom : %s\t | Note : N/A \n",i+1,t[i].Nom);
		}
	}
	do
	{
		printf("Saisir le numero de l'etudiant : ");
		scanf("%d",&Num);
	}while(Num > Nbr || Num < 1);
	Num = Num-1;
	do
	{
		printf("Saisir la note de l'etudiant : ");
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
				Min = t[j].S[Sem].M[i].Note;
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
	
	ChoisirModule(t,NbrModules,Sem,pos);
	
	system("cls");
	printf("------ %s ------ \n",t[0].S[Sem].M[pos].NomModule);
	
	for(i=0;i<Nbr;i++)
	{
		printf("%d - Nom : %s\t | Note : %.2f \n",i+1,t[i].Nom,t[i].S[Sem].M[pos].Note);
	}
	do
	{
		printf("Saisir le numero de l'etudiant : ");
		scanf("%d",&Num);
	}while(Num > Nbr || Num < 1);
	
	Num = Num-1;
	
	t[Num].S[Sem].M[pos].Check = false;
		
	printf("Done !");
}
void MoyenneE(Student *t,int Nbr,int Sem,int NbrModules)
{
	int i,j;
	float Moyenne,NbrM=NbrModules; // pour la division
	printf("----------------MOYENNE DES ETUDIANTS-----------------\n");
	for(i=0;i<Nbr;i++)
	{
		Moyenne = 0;
		for(j=0;j<NbrModules;j++)
		{
			if(t[i].S[Sem].M[j].Check == true)
			{
				Moyenne = Moyenne + t[i].S[Sem].M[j].Note; // coefficient
			}
		}
		Moyenne = Moyenne / NbrM;
		printf("Nom : %-10s | ID : %-10d | Moyenne : %-5.2f |\n",t[i].Nom,t[i].NU,Moyenne);
		
	}
}
void MenuNotes(Student *t,int Nbr,int NbrSemestres)
{
	int choix,i,Sem,NbrModules;
	system("cls");
	
	ChoisirSemestre(NbrSemestres,Sem);
	NbrModules = t[0].S[Sem].NombreModules; // t[0].S[Sem].NombreModules 
	
	system("cls");
	do
	{ 
		
		menu9();
		printf("Entrez votre choix :");
		scanf("%d",&choix);
			switch(choix)
			{
				case 1 :	ModifierNotes(t,Nbr,Sem,NbrModules,1); // check == true pour laffichage
				break;  
				case 2 :	SupprimerNotes(t,Nbr,Sem,NbrModules);
				break;
				case 3 : 	ModifierNotes(t,Nbr,Sem,NbrModules,0);
				break;
				case 4 : 	system("cls");
							StatistiqueNotes(t,Nbr,Sem,NbrModules);
				break;
				case 5 : 	system("cls");
							AfficherNotes(t,Nbr,Sem,NbrModules);
				break;
				case 6 : 	system("cls");
							MoyenneE(t,Nbr,Sem,NbrModules);
				break;
				case 7 : 	Rechoisir(t,NbrSemestres,NbrModules,Sem);
				break;
				default : break;		
			}
	getch();
	system("cls");
	}while(choix<8);
}

