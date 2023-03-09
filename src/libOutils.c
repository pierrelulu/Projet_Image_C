#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "libOutils.h"

/* calcul1 : produit entre N et M basés sur * et / par 2 uniquement */
int calcul1(int N, int M)
{
	int tempN = N, tempM = M;
	int S2 = 0;

	printf("Entre dans calcul1\n");

	while (tempN != 1)
	{
		if (tempN % 2 == 1)
			S2 += tempM;
		tempN /= 2;
		tempM *= 2;
	}
	S2 = S2 + tempM;
	/* fin du calcul */

	printf("Sortie\n");

	return(S2);
}

int arrangements(int n, int k)
{
	return (factorielle(n) / factorielle(n - k));
}

int combinaisons(int n, int k)
{
	return(arrangements(n, k) / factorielle(k));
}

int factorielle(int n)
{
	int res = 1;

	for (int i = n; i>0; i--)
		res *= i;

	return(res);
}

void affichageCombinatoire(int n, int k)
{
	printf("A(%d,%d) = %d\n", n, k, arrangements(n, k));
	printf("C(%d,%d) = %d\n", n, k, combinaisons(n, k));
}

void miseTableauAuCarre(int tIn[], int n, int tOut[])
{
	for (int i = 0; i < n; i++)
		tOut[i] = tIn[i] * tIn[i];
}

void affichageTableauInt(int t[], int n)
{
	printf("\naffichage tableau ---------\n");
	for (int i = 0; i < n; i++)
		printf("%d ", t[i]);
	printf("\nfin affichage tableau -----\n");
}

void initialisationAleatoireTableauInt(int t[], int n, int valMin, int valMax)
{
	/* srand((unsigned)time(NULL)); */
	for (int i = 0; i < n; i++)
		t[i] = valMin + rand() % (valMax + 1 - valMin);
}

int minTableauInt(int tab[], int n)
{
	int min = tab[0];
	for (int i = 1; i<n; i++)
		if (tab[i] < min)
			min = tab[i];

	return(min);
}

int maxTableauInt(int tab[], int n)
{
	int max = tab[0];
	for (int i = 1; i<n; i++)
		if (tab[i] > max)
			max = tab[i];

	return(max);
}

int minTableauIntIndice(int tab[], int n)
{
	int i = 0;
	while (tab[i] == 0)
	{
		i++;
	}
	return(i);
}

int maxTableauIntIndice(int tab[], int n)
{
	int i = n-1;
	while (tab[i] == 0)
	{
		i--;
	}
	return(i);
}

void copieTableauInt(int t1[], int t2[], int n)
{
	for (int i = 0; i<n; i++)
		t2[i] = t1[i];
}

void triEchangeTableauInt(int tab[], int n)
{
	for (int i = 0; i<n; i++)
	{
		int indMin = i;
		for (int j = i; j<n; j++)
			if (tab[j] < tab[indMin])
				indMin = j;
		if (i != indMin)
		{
			int temp = tab[indMin];
			tab[indMin] = tab[i];
			tab[i] = temp;
		}
	}
}

void histogramme(int t[], int n, int hist[])
{
	for (int i = 0; i < 256; i++)
	{
		hist[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		hist[t[i]]++;
	}
}

int OTSU(int t[], int n)
{
	//Lexique local
	int H[256] = { 0 };
	int min, max;
	int S, i, seuil_resultant = 0;
	float w1, w2, M1, M2, Vs_carre = 0, Vs_0 = 0;
	//Algorithme local
	histogramme(t, n, H);
	min = minTableauIntIndice(H, 256);
	max = maxTableauIntIndice(H, 256);
	printf("min indice histo = %d\n", min);
	printf("max indice histo = %d\n", max);
	
	for (S = min; S < max ; S++)
	{
		w1 = w2 = M1 = M2 = 0;
		for (i = min; i <= S; i++)
		{
			w1 += H[i];
			M1 += i * H[i];
		}
		M1 /= w1;
		w1 /= n;

		for (i = (S+1); i <= max; i++)
		{
			w2 += H[i];
			M2 += i * H[i];
		}
		M2 /= w2;
		w2 /= n;

		Vs_carre = w1 * w2 * pow((M1-M2),2);
		printf("Vs_carre = %.2f\n", Vs_carre);
		if (Vs_carre > Vs_0)
		{
			Vs_0 = Vs_carre;
			seuil_resultant = S;
		}
	}
	printf("Seuil OTSU : %d\n", seuil_resultant);
	return seuil_resultant;
}

void affichageCouleur(COULEUR c)
{
	//Lexique local

	//Algorithme local
	printf("%s -> (%d,%d,%d)\n", c.couleur, c.R, c.G, c.B);
}

double distanceEuclidienne(COULEUR c1, COULEUR c2)
{
	//Lexique local
	double ecart, d;
	//Algorithme local
	ecart = (double)(c1.R - c2.R) * (c1.R - c2.R);
	d = ecart;
	ecart = (double)(c1.G - c2.G) * (c1.G - c2.G);
	d += ecart;
	ecart = (double)(c1.B - c2.B) * (c1.B - c2.B);
	d += ecart;
	d = sqrt(d);

	return d;
}

POINT lecturePoint(void)
{
	//Lexique local
	POINT p;
	//Algorithme local
	printf("Entrez une abscisse reelle pour le point : \n");
	scanf("%f", &p.abscisse);
	printf("Entrez une ordonnee reelle pour le point : \n");
	scanf("%f", &p.ordonnee);
	return p;
}

void affichePoint(POINT p)
{
	//Lexique local

	//Algorithme local
	printf("Le point a pour coordonees : (%.2f, %.2f)\n", p.abscisse, p.ordonnee);
}

float distancePoints(POINT p1, POINT p2)
{
	//Lexique local
	float distance;
	//Algorithme local
	distance = sqrt(pow((p1.abscisse - p2.abscisse), 2) + pow((p1.ordonnee - p2.ordonnee), 2));
	return distance;
}

POINT milieuPoints(POINT p1, POINT p2)
{
	//Lexique local
	POINT milieu;
	//Algorithme local
	milieu.abscisse = (p1.abscisse + p2.abscisse) / 2.0;
	milieu.ordonnee = (p1.ordonnee + p2.ordonnee) / 2.0;
	return milieu;
}

void generationAleatoirePoints(POINT t[], int n, float min, float max)
{
	//Lexique local

	//Algorithme local
	for (int i = 0; i < n; i++)
	{
		t[i].abscisse = min + (max - min) * rand()/ RAND_MAX;
		t[i].ordonnee = min + (max - min) * rand() / RAND_MAX;
	}
}

POINT centreGravitePoints(POINT t[], int n)
{
	//Lexique local
	POINT centre = {0, 0};
	//Algorithme local
	for (int i = 0; i < n; i++)
	{
		centre.abscisse += t[i].abscisse;
		centre.ordonnee += t[i].ordonnee;
	}
	centre.abscisse /= n;
	centre.ordonnee /= n;
	return centre;
}

void afficheComplexe(COMPLEXE c)
{
	//Lexique local
	//Algorithme local
	if (c.Re != 0) //Partie réelle non nulle
	{
		
		if (c.Im < 0)
		{
			printf("%.2f-j%.2f\n", c.Re, -c.Im);
		}
		if (c.Im > 0)
		{
			printf("%.2f+j%.2f\n", c.Re, c.Im);
		}
		if (c.Im == 0)
		{
			printf("%.2f\n", c.Re);
		}
	}
	else //Partie réelle nulle
	{
		if (c.Im < 0)
		{
			printf("-j%.2f\n", -c.Im);
		}
		if (c.Im > 0)
		{
			printf("j%.2f\n", c.Im);
		}
		if (c.Im == 0)
		{
			printf("0");
		}
	}
}

COMPLEXE lectureComplexe(void)
{
	//Lexique local
	COMPLEXE z;
	//Algorithme local
	printf("Entrez la partie reelle du complexe : \n");
	scanf("%lf", &z.Re);
	printf("Entrez la partie imaginaire du complexe : \n");
	scanf("%lf", &z.Im);
	return z;
}

COMPLEXE conjugeComplexe(COMPLEXE c)
{
	//Lexique local
	COMPLEXE conjug;
	//Algorithme local
	conjug.Re = c.Re;
	conjug.Im = -c.Im;
	return conjug;
}

double moduleComplexe(COMPLEXE c)
{
	//Lexique local
	double module;
	//Algorithme local
	module = sqrt(pow(c.Re, 2) + pow(c.Im, 2));
	return module;
}

COMPLEXE additionComplexe(COMPLEXE c1, COMPLEXE c2)
{
	//Lexique local
	COMPLEXE c_add;
	//Algorithme local
	c_add.Re = c1.Re + c2.Re;
	c_add.Im = c1.Im + c2.Im;
	return c_add;
}

COMPLEXE multiplicationComplexe(COMPLEXE c1, COMPLEXE c2)
{
	//Lexique local
	COMPLEXE c_mult;
	//Algorithme local
	c_mult.Re = c1.Re * c2.Re - c1.Im * c2.Im;
	c_mult.Im = c1.Re * c2.Im + c1.Im * c2.Re;
	return c_mult;
}

void echangeInt(int* pa, int* pb)
{
	//Lexique local
	int inter;
	//Algorithme local

	inter = *pb;
	*pb = *pa;
	*pa = inter;
}

TEMPS decompositionT(int tps)
{
	//Lexique local
	TEMPS tmp;
	//Algorithme local
	tmp.h = tps / 3600;
	tmp.m = (tps % 3600) / 60;
	tmp.s = (tps % 3600) % 60;
	return tmp;
}

void decomposition(int tps, int* h, int* m, int* s)
{
	//Lexique local
	//Algorithme local
	*h = tps / 3600;
	*m = (tps % 3600) / 60;
	*s = (tps % 3600) % 60;
}

void lectureTemps(int* tps)
{
	//Lexique local
	//Algorithme local
	printf("Temps en secondes : \n");
	scanf("%d", tps);
}

void rechercheAbscissesExtremes(POINT tab[], int n, float* absMin, float* absMax)
{
	//Lexique local
	//Algorithme local
	*absMin = tab[0].abscisse;
	for (int i = 1; i < n; i++)
		if (tab[i].abscisse < *absMin)
			*absMin = tab[i].abscisse;

	*absMax = tab[0].abscisse;
	for (int i = 1; i < n; i++)
		if (tab[i].abscisse > *absMax)
			*absMax = tab[i].abscisse;
}

void recherchePointsExtremes(POINT tab[], int n, POINT* ptDistMin, POINT* ptDistMax)
{
	//Lexique local
	POINT centre;
	float min, max;
	POINT p_min, p_max;
	//Algorithme local
	centre = centreGravitePoints(tab, n);
	//affichePoint(centre);

	min = distancePoints(centre, tab[0]);
	//printf("min : %.2f\n", min);
	max = distancePoints(centre, tab[0]);
	//printf("max : %.2f\n", max);
	for (int i = 1; i < n; i++)
	{
		//printf("iteration %d : \n", i);
		//affichePoint(tab[i]);
		if (distancePoints(centre, tab[i]) < min)
		{
			min = distancePoints(centre, tab[i]);
			//printf("distance min : %.2f\n", min);
			*ptDistMin = tab[i];
		}
		if (distancePoints(centre, tab[i]) > max)
		{
			max = distancePoints(centre, tab[i]);
			//printf("distance max : %.2f\n", max);
			*ptDistMax = tab[i];
		}
	}	
}

int* AllocationMemoireInt(int n, int* t)
{
	//Lexique local
	int* tDyn = NULL;
	//Algorithme local
	tDyn = (int*)calloc(n, sizeof(t));
	return tDyn;
}

void AllocationMemoireIntT(TABLEAU_INT t)
{
	//Lexique local
	//Algorithme local
	t.t = (int*)calloc(t.n, sizeof(t.t));
}

char tirageLettre(void)
{
	//Lexique local
	char c;
	//Algorithme local
	c = 'a' + ('z' - 'a') * rand() / RAND_MAX;
	return c;
}

char* tirageMot(int taille)
{
	//Lexique local
	char* Mot = (char*)calloc(taille+1, sizeof(char));
	//Algorithme local
	for (int i = 0; i < taille; i++)
	{
		Mot[i] = tirageLettre();
	}
	Mot[taille] = '\0';
	return Mot;
}

char* copieMot(char* mot1, int taille)
{
	//Lexique local
	char* Mot = (char*)calloc(taille + 1, sizeof(mot1));
	//Algorithme local
	for (int i = 0; i < taille+1; i++)
	{
		Mot[i] = mot1[i];
	}
	return Mot;
}

void transformMotMajuscule(char* mot)
{
	//Lexique local
	//Algorithme local
	for (int i = 0; mot[i] != '\0';i++)
	{
		if ((mot[i] >= 'a') && (mot[i] <= 'z'))
		{
			mot[i] -= 32;
		}
	}
}
void transformMotMinuscule(char* mot)
{
	//Lexique local
	//Algorithme local
	for (int i = 0; mot[i] != '\0';i++)
	{
		if ((mot[i] >= 'A') && (mot[i] <= 'Z'))
		{
			mot[i] += 32;
		}
	}
}

void multiplicationVoyellesMot(char* mot1, int taille1, int coef, char* mot2, int* taille2)
{
	//Lexique local
	*taille2 = 0;
	//Algorithme local
	int j = 0;
	mot2 = realloc(mot2, 1 + taille1*coef * sizeof(char));
	for (int i = 0; mot1[i] != '\0'; i++)
	{
		mot2[*taille2] = mot1[i];
		if ((mot1[i] == 'a') ||
			(mot1[i] == 'e') ||
			(mot1[i] == 'i') ||
			(mot1[i] == 'o') ||
			(mot1[i] == 'u') ||
			(mot1[i] == 'y') ||
			(mot1[i] == 'A') ||
			(mot1[i] == 'E') ||
			(mot1[i] == 'I') ||
			(mot1[i] == 'O') ||
			(mot1[i] == 'U') ||
			(mot1[i] == 'Y'))
		{
			for (int k = *taille2; k < *taille2 + coef;k++)
			{
				mot2[k] = mot1[i];
			}
			*taille2 += coef;
			
		}
		else
		{
			mot2[(* taille2)++] = mot1[i];
		}
	}
	mot2[(* taille2)++] = '\0';
	mot2 = realloc(mot2, (*taille2) * sizeof(char));
}

MOT generationMot(int n)
{
	//Lexique local
	MOT mot;
	mot.longueur = n;
	mot.data = (char*)calloc(n + 1, sizeof(char));
	//Algorithme local
	for (int i = 0; i < n; i++)
	{
		mot.data[i] = tirageLettre();
	}
	mot.data[n] = '\0';
	return mot;
}

void libereMot(MOT mot)
{
	//Lexique local
	//Algorithme local
	free(mot.data);
	mot.data = NULL;
}

MOT* tiragePhrase(int nbMots)
{
	//Lexique local
	int alea;
	MOT* phrase = (MOT*)calloc(nbMots + 1, sizeof(MOT));
	//Algorithme local
	for (int i = 0; i < nbMots; i++)
	{
		alea = 1 + (15 - 1) * rand() / RAND_MAX;
		phrase[i] = generationMot(alea);
		phrase[i].data[alea + 1] = ' ';
	}
	phrase[nbMots].data[alea+2] = '.';
	return phrase;
}

void affichageMatrice(MATRICE matrice)
{
	//Lexique local
	//Algorithme local
	for (int i = 0; i < matrice.hauteur; i++)
	{
		printf("|\t");
		for (int j = 0; j < matrice.largeur; j++)
		{
			printf("%d\t", matrice.valeurs[i][j]);
		}
		printf("|\t\n");
	}
}

MATRICE initialisationMatrice(int hauteur, int largeur, int min, int max)
{
	//Lexique local
	MATRICE mat = {hauteur, largeur, NULL};
	//Algorithme local

	mat.valeurs = (int**)malloc(mat.hauteur * sizeof(int*));
	if (mat.valeurs == NULL)
		printf("Pb allocation matrice.\n");
	else
	{
		int i;
		for (i = 0; i < mat.hauteur; i++)
			mat.valeurs[i] = (int*)malloc(mat.largeur * sizeof(int));
		if (mat.valeurs[i] == NULL)
			printf("Pb allocation ligne %d.", i);
	}

	for (int i = 0; i < hauteur; i++)
	{
		initialisationAleatoireTableauInt(mat.valeurs[i],largeur,min,max);
	}
	return mat;
}

void liberationMatrice(MATRICE* matrice)
{
	//Lexique local
	int i;
	//Algorithme local
	for (i = 0; i < matrice->hauteur; i++)
		free(matrice->valeurs[i]);
	free(matrice->valeurs);
	matrice->valeurs = NULL;
}

int traceMatrice(MATRICE matrice)
{
	//Lexique local
	int trace = 0;
	//Algorithme local
	if (matrice.hauteur == matrice.largeur)
	{
		for (int i = 0; i < matrice.hauteur; i++)
		{
			trace += matrice.valeurs[i][i];
		}
	}
	return trace;
}

MATRICE allocationMatrice(int hauteur, int largeur)
{
	//Lexique local
	MATRICE mat = { hauteur, largeur, NULL };

	//Algorithme local
	mat.valeurs = (int**)malloc(mat.hauteur * sizeof(int*));
	if (mat.valeurs == NULL)
		printf("Pb allocation matrice.\n");
	else
	{
		int i;
		for (i = 0; i < mat.hauteur; i++)
			mat.valeurs[i] = (int*)malloc(mat.largeur * sizeof(int));
		if (mat.valeurs[i] == NULL)
			printf("Pb allocation ligne %d.", i);
	}
	return mat;
}

MATRICE additionMatrice(MATRICE m1, MATRICE m2)
{
	//Lexique local
	MATRICE matrice = allocationMatrice(m1.hauteur, m2.largeur);
	//Algorithme local
	if ((m1.largeur == m2.largeur) && (m1.hauteur == m2.hauteur))
	{
		for (int i = 0; i < matrice.hauteur; i++)
		{
			for (int j = 0; j < matrice.largeur; j++)
			{
				matrice.valeurs[i][j] = m1.valeurs[i][j] + m2.valeurs[i][j];
			}
		}
	}
	return matrice;
}

MATRICE multiplicationMatrice(MATRICE m1, MATRICE m2)
{
	//Lexique local
	MATRICE matrice = allocationMatrice(m1.hauteur, m2.largeur);
	//Algorithme local
	if (m1.largeur == m2.hauteur)
	{
		for (int i = 0; i < m2.hauteur; i++)
		{
			for (int j = 0; j < m1.largeur; j++)
			{
				for (int k = 0; k < m1.largeur; k++)
				{
					matrice.valeurs[i][j] = +m1.valeurs[i][k] * m2.valeurs[k][j];
				}
			}
		}
	}
	return matrice;
}

iMATRICE allocation_iMatrice(int hauteur, int largeur)
{
	//Lexique local
	iMATRICE mat = { hauteur, largeur, NULL, NULL};
	//Algorithme local
	mat.valeurs = (int*)malloc(mat.hauteur * mat.largeur * sizeof(int));
	mat.ptLignes = (int**)malloc(mat.hauteur*sizeof(int*));
	for (int j = 0; j < hauteur; j++)
	{
		mat.ptLignes[j] = &mat.valeurs[j * largeur]; //ça marche, demande à Loris pour l'autre méthode
	}
	return mat;

}

void remplissageAleatoire_iMatrice(iMATRICE matrice, int valMin, int valMax)
{
	//Lexique local
	//Algorithme local
	initialisationAleatoireTableauInt(matrice.valeurs, matrice.largeur * matrice.hauteur, valMin, valMax);
}

void affichage_iMatrice(iMATRICE matrice) {
	//Lexique local
	//Algorithme local
	for (int i = 0; i < matrice.hauteur; i++) {
		for (int j = 0; j < matrice.largeur; j++) {
			printf("%d\t", matrice.valeurs[i * matrice.largeur + j]);
		}
		printf("\n");
	}
}

void liberation_iMatrice(iMATRICE* ptMatrice)
{
	//Lexique local
	//Algorithme local
	free(ptMatrice->ptLignes);
	free(ptMatrice->valeurs);

	ptMatrice->ptLignes = NULL;
	ptMatrice->valeurs = NULL;
}

//EVAL 2
int carre(int x)
{
	//Lexique local
	//Algorithme local
	return(x * x);
}

int fonction1(int T[], int n)
{
	//Lexique local
	int compteur = 0, j = 0;
	int a = 2; //Nombre à supprimer dans le tableau
	//Algorithme local
	for (int i = 0; i < n; i++)
		if (T[i] != a)
		{
			T[j] = T[i];
			j = j + 1;
		}
		else
			compteur += 1;
	n -= compteur;
	return n; //Retourne la nouvelle taille pratique du tableau
}

int minTableauIntViaHisto(int T[], int n)
{
	//Lexique local
	int i = 0;
	//Algorithme local
	while (T[i] == 0)
	{
		i++;
	}
	return i;
}

int maxTableauIntViaHisto(int T[], int n)
{
	//Lexique local
	int i = n-1;
	//Algorithme local
	while (T[i] == 0)
	{
		i--;
	}
	return i;
}

int trace(int T[], int N)
{
	//Lexique local
	int res = 0;
	//Algorithme local
	for (int i = 0; i < N;i+= sqrt(N)+1)
	{
		res += T[i];
	}
	return res;
}

int puissance(int x, int n)
{
	//Lexique local
	int res = 1;
	//Algorithme local
	for (int i = 0; i < n;i++)
	{
		res = res * x;
	}
	return res;
}

int evalPolynome(int P[], int n, int x)
{
	//Lexique local
	int eval = 0;
	//Algorithme local
	for (int i = 0; i < n; i++)
	{
		eval += P[i]*puissance(x, i);
	}
	return eval;
}

int evalPolynomeV2(int P[], int n, int x)
{
	//Lexique local
	int eval = P[n-1]*x;
	//Algorithme local
	for (int i = n-2; i > 0; i--)
	{
		eval += P[i];
		eval *= x;
	}
	eval += P[0];
	return eval;
}

INT_TABLEAU question1(int n)
{
	//Lexique local
	INT_TABLEAU tab;
	tab.longueur = n;
	tab.data = (char*)malloc(n * sizeof(char));
	//Algorithme local
	return tab;
}

INT_TABLEAU question2(int n, int valMin, int valMax)
{
	//Lexique local
	INT_TABLEAU tab;
	tab.longueur = n;
	tab.data = (int*)malloc(tab.longueur * sizeof(int));
	//Algorithme local
	initialisationAleatoireTableauInt(tab.data, n, valMin, valMax);
	return tab;
}

DISQUE question3(int r)
{
	//Lexique local
	DISQUE disk;
	//Algorithme local
	disk.rayon = r;
	disk.perimetre = 2 * acos(-1) * r;
	disk.surface = acos(-1) * r * r;
	return disk;
}

void question4(DISQUE d)
{
	//Lexique local
	//Algorithme local
	printf("rayon : %d -> P = %.2lf et S = %.2lf\n", d.rayon, d.perimetre, d.surface);
	
}

DISQUE* question5(INT_TABLEAU rayons)
{
	//Lexique local
	DISQUE* disk;
	disk = (DISQUE*)malloc(rayons.longueur * sizeof(DISQUE));
	//Algorithme local
	for (int i = 0; i < rayons.longueur; i++)
	{
		disk[i] = question3(rayons.data[i]);
	}
	return disk;
}

