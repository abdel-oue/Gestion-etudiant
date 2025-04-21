#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// after gestionsnotes et fichiers
void menu13()
{
	printf("----PARAM%cTRES D'AFFICHAGE----\n 1. Changer la couleur de fond \n 2. Changer la couleur du texte \n 3. R%cinitialiser les couleurs par d%cfaut \n 4. Retour \n",212,130,130);
}
void menu14()
{
	printf("----CHOISIR LA COULEUR DE FOND----\n");
    printf("0 = Noir        8 = Gris\n");
    printf("1 = Bleu        9 = Bleu clair\n");
    printf("2 = Vert        A = Vert clair\n");
    printf("3 = Bleu-gris   B = Cyan\n");
    printf("4 = Rouge       C = Rouge clair\n");
    printf("5 = Violet      D = Violet clair\n");
    printf("6 = Jaune       E = Jaune clair\n");
    printf("7 = Blanc       F = Blanc brillant\n");
}
void Couleurfond(char text,char &choix)
{
	char command[20];
		
			system("cls");
			menu14();
			printf("Entrez votre choix :");
			getchar();
			scanf("%c",&choix);
			
			sprintf(command, "color %c%c", choix,text);
			system(command);
}
void Couleurtext(char &text,char choix)
{
	char command[20];
		
			system("cls");
			menu14();
			printf("Entrez votre choix :");
			getchar();
			scanf("%c",&text);
			
			sprintf(command, "color %c%c", choix,text);
			system(command);
}
void Colors()
{
		int choix;
		char text='7';
		char fond='0';
		do
		{
			system("cls");
			menu13();
			printf("Entrez votre choix :");
			scanf("%d",&choix);
			switch(choix)
			{
				case 1: Couleurfond(text,fond);
				break;
				case 2: Couleurtext(text,fond);
				break;
				case 3:	system("Color 07");
						printf("Done !");
				break;
				default: break;
			}
		}while(choix < 4);
}
void Apropos()
{
	system("cls");
	printf("%ctablissement : ESISA \nEncadrer par : Mr.Iraqi Mehdi \nFait par: OUEGDHIRI Abdelaziz & GNAOUI Safae",144);
}


