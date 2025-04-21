	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	// fseek(f,0,SEEK_END) moves the cursor to the end of the file
	// fseek(f,0,SEEK_SET) moves the cursor to the start of the file	
void ListFichier(int option,char Nom[30])
	{
		system("cls");
		printf("List des fichiers disponibles : \n");
		system("dir /b *.txt"); // lister tous les fichier .txt
		if(option == 1)
		{
		printf("Entrez le nom d'un fichier (ou l'emplacement d'un fichier) : ");
		scanf("%s",Nom);
		}
	}
void SupprimerFichier(char Nom[30])
	{
		if(remove(Nom) == 0)
		{
			printf("Supprim\x82 avec succ\x8As !");
		}
		else
		{
			printf("Impossible de supprimer le fichier");
		}
	}
void Savetxt(Student *t, int Nbr, char Nom[30],int NbrSemestres) 
{
	//nous avons modifié la procédure pour permettre à l'utilisateur de choisir s'il souhaite créer le fichier. 
	//si nous utilisions le mode "a" seulement, cela créerait un fichier même si l'utilisateur ne le souhaite pas.
    int j,i,k,vam=1,S,NbrM;
    long fpos;
    
    FILE *f = fopen(Nom, "r");
    if (f == NULL)
	{
        system("cls");
        printf("Fichier introuvable.\nVoulez-vous cr%cer un nouveau fichier nomme '%s'?\n 1-Oui | 2-Non \n",130, Nom);
        scanf("%d", &vam);
    }
    
    	fclose(f);
    	
    if(vam == 1) f = fopen(Nom, "a"); // if(){f = fopen(Nom, "a");}
    
    if (f != NULL) 
	{
		fseek(f,0,SEEK_END);
		fpos = ftell(f);
		fseek(f,0,SEEK_SET);
		printf("%d",fpos);
		for (i=0;i<Nbr;i++) 
			{
				if(i == 0 && fpos != 0) // fichier n'est pas vide alors -->
					{
					        fprintf(f,"\n");
					}
					
				if(i == 0 && fpos == 0) // fichier vide alors -->
					{
						fprintf(f,"%d",NbrSemestres);
						for(j=0;j<NbrSemestres;j++)
						    {
						       	fprintf(f," %d",t[i].S[j].NombreModules);
							}
						for(j=0;j<NbrSemestres;j++)
				        {
				        	NbrM = t[0].S[j].NombreModules;
				        	for(k=0;k<NbrM;k++)
				        	{
				        		fprintf(f," %s",t[i].S[j].M[k].NomModule);
							}
						}
							fprintf(f,"\n");
					}
					
					
				        fprintf(f, "%s %d %d %d %d %d", t[i].Nom, t[i].NU, t[i].Age, t[i].Date.Day, t[i].Date.Month, t[i].Date.Year);
				        for(j=0;j<NbrSemestres;j++)
				        {
				        	NbrM = t[0].S[j].NombreModules;
				        	for(k=0;k<NbrM;k++)
				        	{
				        		fprintf(f," %.2f %d",t[i].S[j].M[k].Note,t[i].S[j].M[k].Check);
							}
						}
				        if (i != Nbr -1) 
						{
				            fprintf(f,"\n");
				        }
	        }
		printf("Done !");
    } 
	else 
	{
        printf("Impossible d'ouvrir le fichier.");
    }
    fclose(f);
}
void Loadtxt(Student *&t, int &Nbr,char Nom[30],int &NbrSemestres,bool Premierefois)
	{
		int i,j,NbrM,S=0,cp=0,oldNbr;
		long fpos;
		FILE *f = NULL;
		f = fopen(Nom,"r");
		
		oldNbr = Nbr;
		
		if(f == NULL)
		{
			printf("Erreur impossible d'ouvrir le fichier.\n");
		}
		else
		{	
			if(Nbr == 0)
			{
				t = (Student*)malloc(sizeof(Student));
			}
				while(!feof(f))
				{
					fseek(f,0,SEEK_END);
					fpos = ftell(f);
					fseek(f,0,SEEK_SET); // position du pointeur
					
					if(fpos == 0)
					{
						fscanf(f,"%d ",&NbrSemestres);
						t.S = (Semestre*)malloc(sizeof(Semestre)*NbrSemestres); // dynamique
						
						for(i=0;i<NbrSemestres;i++)
						{
							fscanf(f,"%d ",&t[0].S[i].NombreModules);
						}
						for(i=0;i<NbrSemestres;i++)
				        {
				        	NbrM = t[0].S[i].NombreModules;
				        	t.S[i].M = (Module*)malloc(sizeof(Module)*NbrM);
				        	for(j=0;j<NbrM;j++)
				        	{
				        		fscanf(f,"%s ",t[Nbr].S[i].M[j].NomModule);
							}
						}
					}
						fscanf(f, "%s %d %d %d %d %d", t[Nbr].Nom, &t[Nbr].NU, &t[Nbr].Age, &t[Nbr].Date.Day, &t[Nbr].Date.Month, &t[Nbr].Date.Year);
					for(i=0;i<NbrSemestres;i++)
				        {
				        	NbrM = t[0].S[i].NombreModules;
				        	for(j=0;j<NbrM;j++)
				        	{
				        		//fseek(f,fpos,SEEK_SET);
				        		fscanf(f," %f %d",&t[Nbr].S[i].M[j].Note,&t[Nbr].S[i].M[j].Check);
							}
						}
					// pour que les étudiants avec le même numéro unique ne soient pas chargés 
					S = 0;
					for(i=0;i<oldNbr;i++)
					{
						if(t[Nbr].NU == t[i].NU)
						{
							S = 1;
						}
					}
					if(S == 1)
					{
						cp++;
					}
					else
					{
						Nbr++;
						t = (Student*)realloc(t, sizeof(Student)*(Nbr+1));
						Premierefois = false;
						// realloc(t, sizeof(Student) * (Nbr + 1)) ??? 
					}
				}
			if(cp != 0)
			{
				printf("L'inscription a %cchou\x82 pour %d \x82tudiants (Raison : m\x88mes identifiants uniques).\n",130, cp); // cp-1 car ligne compte aussi la dernière ligne du programme '\n'
			}
			printf("Done ! ");
		}
		fclose(f);
	}
void Savebin(Student *t,int Nbr, char Nom[30])
{
	FILE *f = fopen(Nom,"ab");
	int Dim =1;
	
	if(f == NULL)
	{
		printf("Impossible d'ouvrir le fichier.");
	}
	else
	{
			fwrite(&Nbr,sizeof(int),Dim,f);
			fwrite(t,sizeof(Student),Nbr,f);
			fclose(f);
			printf("Done ! ");
	}
}
void Loadbin(Student *&t,int &Nbr,char Nom[30])
{
	FILE *f = fopen(Nom,"rb");
	Student *TEMP;
	int NbrT;
	int Dim =1,i;

	if(f == NULL)
	{
		printf("Impossible d'ouvrir le fichier.");
	}
	else
	{
		fread(&NbrT,sizeof(int),1,f);
		TEMP = (Student *)malloc(Nbr * sizeof(Student));
		fread(TEMP,sizeof(Student),NbrT,f);
		for(i=0;i<NbrT;i++)
		{
			t[Nbr] = TEMP[i];
			realloc(t,sizeof(Student)*(Nbr+1));
			Nbr++;
		}
		free(TEMP);
		fclose(f);
		printf("Done ! ");
	}
}
void AfficherFichier(char Nom[30])
{
	char A[20];
	int B,C,D,E,F;
	FILE *f=fopen(Nom,"r");
	if(f == NULL)
	{
		printf("Impossible d'ouvrir le fichier.");
	}
	else
	{
		system("cls");
		while(!feof(f))
		{
			fscanf(f, "%s %d %d %d %d %d", A, &B, &C, &D, &E, &F);
			printf("%s NU%d (%d/%d/%d) Age : %d\n",A,B,D,E,F,C);
		}
	}
	
}

/*int FichierVide(char Nom[30]) // 1 fichier vide
	{
	    FILE *fichier = fopen(Nom, "r");
	    if (fichier == NULL) 
		{
	        printf("Erreur");
	        return -1;
	    }
	    else
	    {
	    	
		    fseek(fichier, 0, SEEK_END); // Déplace le pointeur de fichier à la fin du fichier
		    if (ftell(fichier) == 0) // Vérifiez si le pointeur de fichier est à la position 0 (le début du fichier)
			{
		        fclose(fichier);
		        return 1;  // Fichhire est vide
		    } else 
			{
		        fclose(fichier);
		        return 0;  // fichier n'est pas vide
		    }
		}
	
	    
}*/
