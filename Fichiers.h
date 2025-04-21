#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
	// fseek(f,0,SEEK_END) moves the cursor to the end of the file
	// fseek(f,0,SEEK_SET) moves the cursor to the start of the file
void menu11()
{
		printf("----OPTIONS DE SAUVEGARDE---- \n 1) Enregistrer les nouveaux \x82tudiants dans le fichier \n 2) Modifier le fichier entier (semestres, modules) \n 3) Revenir au menu principal \n ");
}
int FichierVide(char Nom[30]) // 1 fichier vide
	{
	    FILE *fichier = fopen(Nom, "r");
	    if (fichier == NULL) 
		{
	        return -1;
	    }
	    else
	    {
		    fseek(fichier, 0, SEEK_END); // Déplace le pointeur de fichier à la fin du fichier
		    if (ftell(fichier) == 0) // Vérifiez si le pointeur de fichier est à la position 0 (le début du fichier)
			{ // ftell donne la position du pointeur
		        fclose(fichier);
		        return 1;  // Fichhire est vide
		    } 
			else 
			{
		        fclose(fichier);
		        return 0;  // fichier n'est pas vide
		    }
		}	    
}
void ListFichier(int option,int option2,char Nom[30])
	{
		system("cls");
		printf("List des fichiers disponibles : \n");
		if(option2 == 1)
		{
			system("dir /b *.bin"); // lister tous les fichier .bin
		}
		else if(option2 == 0)
		{
			system("dir /b *.txt"); // lister tous les fichier .txt
		}
		else
		{
			system("dir /b *.txt"); // lister tous les fichier .txt
			system("dir /b *.bin"); // lister tous les fichier .bin
		}
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
    int Choix=1;
    long fpos;
    
    FILE *f = fopen(Nom, "r");
    if (f == NULL)
	{
        system("cls");
        printf("Fichier introuvable.\nVoulez-vous cr%cer un nouveau fichier nomme '%s'?\n 1-Oui | 2-Non \n",130, Nom);
        scanf("%d", &vam);
    }
	fclose(f);
    
    if(FichierVide(Nom) == 0) // fichier pas vide
    {
    	system("cls");
    	menu11();
	    printf("Saisir votre choix :");
	    scanf("%d",&Choix);
	}
    if(vam == 1)
    {
    	if(Choix == 1)
    	{
    		f = fopen(Nom, "a"); // if(){f = fopen(Nom, "a");}
		}
		else
		{
			f = fopen(Nom, "w");
		}
	}
    if (f != NULL) 
	{
		fseek(f,0,SEEK_END);
		fpos = ftell(f);
		fseek(f,0,SEEK_SET);
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
   		 printf("Sauvegarde termin%ce avec succ\x8as!\n",130); // é: \x82, è: \x8A
    } 
	else 
	{
        printf("Impossible d'ouvrir le fichier.");
    }
    fclose(f);
}
void Loadtxt(Student *&t, int &Nbr,char Nom[30],int &NbrSemestres,bool &Premierefois)
	{
		int i,j,NbrM[10],S=0,cp=0,oldNbr;
		int elem,allo=0;
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
					if(allo == 0) // scan la premier ligne
					{
						fscanf(f,"%d ",&NbrSemestres);
						
						t[Nbr].S = (Semestre*)malloc(sizeof(Semestre)*NbrSemestres);
						
						for(i=0;i<NbrSemestres;i++)
						{
							fscanf(f,"%d ",&t[Nbr].S[i].NombreModules);
						}
						
							for(i=0;i<NbrSemestres;i++)
						    {
						    	NbrM[i] = t[Nbr].S[i].NombreModules;
						        t[Nbr].S[i].M = (Module*)malloc(sizeof(Module)*NbrM[i]); // allocation de memoire pour tout le monde
						        for(j=0;j<NbrM[i];j++)
								{
									fscanf(f,"%s ",t[Nbr].S[i].M[j].NomModule);
								}
							}
					}
					else // allocation de memoire pour tout le monde // allo == 1
					{
						t[Nbr].S = (Semestre*)malloc(sizeof(Semestre)*NbrSemestres);
						for(i=0;i<NbrSemestres;i++)
						{
					        t[Nbr].S[i].M = (Module*)malloc(sizeof(Module)*NbrM[i]); 
						}
					}
					if(allo == 1)
					{
						for(i=0;i<NbrSemestres;i++)
						{
							for(j=0;j<NbrM[i];j++)
							{
								strcpy(t[Nbr].S[i].M[j].NomModule,t[0].S[i].M[j].NomModule); // copie des nom de modules , nombre de module , .. 
							}
						}
					}
					allo = 1;
						fscanf(f, "%s %d %d %d %d %d", t[Nbr].Nom, &t[Nbr].NU, &t[Nbr].Age, &t[Nbr].Date.Day, &t[Nbr].Date.Month, &t[Nbr].Date.Year);
					for(i=0;i<NbrSemestres;i++)
				        {
				        	for(j=0;j<NbrM[i];j++)
				        	{
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
						t= (Student*)realloc(t, sizeof(Student)*(Nbr+1));
						Premierefois = false;
					}
				}
			if(cp != 0)
			{
				printf("L'inscription a %cchou\x82 pour %d \x82tudiants (Raison : m\x88mes identifiants uniques).\n",130, cp); // cp-1 car ligne compte aussi la dernière ligne du programme '\n'
			}
			else
			{
				printf("Chargement termin\x82 avec succ\x8as!\n"); // é: \x82, è: \x8A
			}
		}
		fclose(f);
	}
void Savebin(Student *t,int Nbr,int NbrSemestres,char Nom[30])
{
	int i,j,k,NbrM;
	
	FILE *f = fopen(Nom,"ab");
	
	if(f == NULL)
	{
		printf("Impossible d'ouvrir le fichier.");
	}
	else
	{
			fwrite(&Nbr,sizeof(int),1,f);
			fwrite(&NbrSemestres,sizeof(int),1,f);
			// on ecrit elem par elem
			for(i=0;i<Nbr;i++)
			{
				//fwrite(&t[i],sizeof(Student),1,f);
				fwrite(t[i].Nom,sizeof(char),30,f);
		        fwrite(&t[i].NU,sizeof(int),1,f);
		        fwrite(&t[i].Age,sizeof(int),1,f);
		        fwrite(&t[i].Date,sizeof(Date),1,f);
		    }  
		    for(i=0;i<Nbr;i++)
			{
				for(j=0;j<NbrSemestres;j++)
				{
					fwrite(&t[0].S[j].NombreModules,sizeof(int),1,f);
					NbrM = t[0].S[j].NombreModules;
					for(k=0;k<NbrM;k++)
					{
						fwrite(t[i].S[j].M[k].NomModule,sizeof(char),30,f);
		                fwrite(&t[i].S[j].M[k].Note,sizeof(float),1,f);
		                fwrite(&t[i].S[j].M[k].Check,sizeof(int),1,f);
					}
				}
			}
			fclose(f);
			printf("Sauvegarde termin%ce avec succ\x8as!\n",130); // é: \x82, è: \x8A
	}
}
void Loadbin(Student *&t,int &Nbr,int &NbrSemestres,char Nom[30],bool &Premierefois)
{
	int i,j,k,NbrM;
	FILE *f = fopen(Nom,"rb");

	if(f == NULL)
	{
		printf("Impossible d'ouvrir le fichier.");
	}
	else
	{
			fread(&Nbr,sizeof(int),1,f);
		    fread(&NbrSemestres,sizeof(int),1,f);
		
		    t = (Student*)malloc(sizeof(Student) * Nbr);
		
		    for (i = 0; i < Nbr; i++) 
			{
		        fread(t[i].Nom,sizeof(char),30,f);
		        fread(&t[i].NU,sizeof(int),1,f);
		        fread(&t[i].Age,sizeof(int),1,f);
		        fread(&t[i].Date,sizeof(Date),1,f);
			}
			
			for (i=0;i<Nbr;i++) 
			{
		        t[i].S = (Semestre*)malloc(sizeof(Semestre) * NbrSemestres);
		        for (j=0;j<NbrSemestres;j++) 
				{
		            fread(&t[i].S[j].NombreModules,sizeof(int),1,f);
		            NbrM = t[i].S[j].NombreModules;
		            t[i].S[j].M = (Module*)malloc(sizeof(Module)*NbrM);
		            for (k =0;k<NbrM;k++) 
					{
		                fread(t[i].S[j].M[k].NomModule,sizeof(char),30,f);
		                fread(&t[i].S[j].M[k].Note,sizeof(float),1,f);
		                fread(&t[i].S[j].M[k].Check,sizeof(int),1,f);
		            }
		        }
			}
		    Premierefois = false; 
		    
		fclose(f);
    	printf("Chargement termin\x82 avec succ\x8as!\n"); // é: \x82, è: \x8A
	}
}
