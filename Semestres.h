#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void ChoisirSemestre(int NbrSemestres,int &Sem);

void menu8()
{
	printf("----MENU SEMESTRES---- \n 1) Ajouter un semestre \n 2) Supprimer le contenue d'un semestre \n 3) Lister tout les semestres \n 4) Retour \n");
}

void AjouterSemestre(Student *t,int Nbr,int &NbrSemestres)
{
	int i;
	for(i=0;i<Nbr;i++)
	{
		t[i].S = (Semestre*)realloc(t[Nbr].S,sizeof(Semestre)*(NbrSemestres+1));
		t[i].S[NbrSemestres].NombreModules = 0;
	}
	NbrSemestres++;
	printf("Ajout\x82 avec succ\x8As \n");
}
void SupprimerSemestre(Student *t,int Nbr,int NbrSemestres)
{
	int Sem,choix,i;
	
	ChoisirSemestre(NbrSemestres,Sem);
	
	printf("Etes-vous sûr de vouloir supprimer le contenu de semestre %d ? \n 1 - Oui | 2 - Non",Sem+1 );
	scanf("%d",&choix);
	
	if(choix == 1)
	{
		for(i=0;i<Nbr;i++)
		{
			free(t[Nbr].S[Sem].M);
			t[Nbr].S[Sem].NombreModules = 0;
		}
		printf("Done !");
	}
	
}
void ListerSemestres(Student *t,int Nbr,int NbrSemestres)
{
	int i;
	printf("List des Semestres : \n");
	for(i=0;i<NbrSemestres;i++)
	{
		printf("%d - Semestre %d (S%d) , Nombre de Modules : %d\n",i+1,i+1,i+1,t[0].S[i].NombreModules);
	}
}
void MenuSemestres(Student *t,int Nbr,int &NbrSemestres)
{
	int choix;
	system("cls");
	do
	{ 
		
		menu8();
		printf("Entrez votre choix :");
		scanf("%d",&choix);
			switch(choix)
			{
				case 1 : AjouterSemestre(t,Nbr,NbrSemestres);
				break;  
				case 2 : SupprimerSemestre(t,Nbr,NbrSemestres);
				break;
				case 3 : ListerSemestres(t,Nbr,NbrSemestres);
				break;
				default : break;		
			}
	getch();
	system("cls");
	}while(choix<4);
}
