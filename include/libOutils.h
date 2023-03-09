#pragma once

/* structures de type */
typedef struct couleur {
	char couleur[20];
	int R;
	int G;
	int B;
} COULEUR;

typedef struct point
{
	float abscisse;
	float ordonnee;
} POINT;

typedef struct complexe
{
	double Re;
	double Im;
} COMPLEXE;

typedef struct temps
{
	int h;
	int m;
	int s;
}TEMPS;

typedef struct tableau_int
{
	int n;
	int *t;
}TABLEAU_INT;

typedef struct mot
{
	int longueur;
	char* data;
}MOT;

typedef struct matrice {
	int hauteur;
	int largeur;
	int** valeurs;
} MATRICE;

typedef struct iMatrice {
	int hauteur;
	int largeur;
	int* valeurs;
	int** ptLignes;
} iMATRICE;

typedef struct disque
{
	int rayon;
	double surface;
	double perimetre;
} DISQUE;


typedef struct int_tableau
{
	int longueur;
	int* data;
}INT_TABLEAU;
/* calcul du produit entre N et M */
/* N et M en entrée */
int calcul1(int N, int M);

/* fonctions */
int factorielle(int n);
int arrangements(int n, int k);
int combinaisons(int n, int k);

/* procédures -> fonctions type void en retour */
void affichageCombinatoire(int n, int k);

/* tableaux statiques */
void miseTableauAuCarre(int tIn[], int n, int tOut[]);

void affichageTableauInt(int t[], int n);
void initialisationAleatoireTableauInt(int t[], int n, int valMin, int valMax);

int minTableauInt(int tab[], int n);
int maxTableauInt(int tab[], int n);
int minTableauIntIndice(int tab[], int n);
int maxTableauIntIndice(int tab[], int n);
void copieTableauInt(int t1[], int t2[], int n);
void triEchangeTableauInt(int t[], int n);
void histogramme(int t[], int n, int hist[]);
int OTSU(int t[], int n);

void affichageCouleur(COULEUR c);
double distanceEuclidienne(COULEUR c1, COULEUR c2);

POINT lecturePoint(void);
void affichePoint(POINT p);
float distancePoints(POINT p1, POINT p2);
POINT milieuPoints(POINT p1, POINT p2);
void generationAleatoirePoints(POINT t[], int n, float min, float max);
POINT centreGravitePoints(POINT t[], int n);

void afficheComplexe(COMPLEXE c);
COMPLEXE lectureComplexe(void);
COMPLEXE conjugeComplexe(COMPLEXE c);
double moduleComplexe(COMPLEXE c);
COMPLEXE additionComplexe(COMPLEXE c1, COMPLEXE c2);
COMPLEXE multiplicationComplexe(COMPLEXE c1, COMPLEXE c2);

void echangeInt(int* pa, int* pb);
TEMPS decompositionT(int tps);
void decomposition(int tps, int* h, int* m, int* s);
void lectureTemps(int* tps);
void rechercheAbscissesExtremes(POINT tab[], int n, float* absMin, float* absMax);
void recherchePointsExtremes(POINT tab[], int n, POINT* ptDistMin, POINT* ptDistMax);

int* AllocationMemoireInt(int n, int *t);
void AllocationMemoireIntT(TABLEAU_INT t);

char tirageLettre(void);
char* tirageMot(int taille);
char* copieMot(char* mot1, int taille);
void transformMotMajuscule(char* mot);
void transformMotMinuscule(char* mot);
void multiplicationVoyellesMot(char* mot1, int taille1, int coef, char* mot2, int* taille2);

MOT generationMot(int n);
void libereMot(MOT mot);
MOT* tiragePhrase(int nbMots);

void affichageMatrice(MATRICE matrice);
MATRICE initialisationMatrice(int hauteur, int largeur, int min, int max);
MATRICE allocationMatrice(int hauteur, int largeur);
void liberationMatrice(MATRICE *matrice);
int traceMatrice(MATRICE matrice);
MATRICE additionMatrice(MATRICE m1, MATRICE m2);
MATRICE multiplicationMatrice(MATRICE m1, MATRICE m2);

iMATRICE allocation_iMatrice(int hauteur, int largeur);
void remplissageAleatoire_iMatrice(iMATRICE matrice, int valMin, int valMax);
void affichage_iMatrice(iMATRICE matrice);
void liberation_iMatrice(iMATRICE* ptMatrice);

//EVAL 2
int carre(int x);
int fonction1(int T[], int n);
int minTableauIntViaHisto(int T[], int n);
int maxTableauIntViaHisto(int T[], int n);
int trace(int T[], int N);
int puissance(int x, int n);
int evalPolynome(int P[], int n, int x);
int evalPolynomeV2(int P[], int n, int x);

//ENTRAINEMENT EVAL 2
INT_TABLEAU question1(int n);
INT_TABLEAU question2(int n, int valMin, int valMax);
DISQUE question3(int r);
void question4(DISQUE d);
DISQUE* question5(INT_TABLEAU rayons);

