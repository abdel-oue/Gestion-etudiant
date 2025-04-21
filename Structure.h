#define MAX 20

struct Module
{
	char NomModule[30];
	int Note;	
};
struct Semestre
{
	Module M[MAX];
	int NombreModules;	
};
struct Student
{
    int NU;
    char Nom[20];
    int Age;
    struct 
    {
    	int Day;
	    int Month;
	    int Year;	
	} Date;
    Semestre S[MAX];
};

