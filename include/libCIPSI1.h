/* librairie IPSI1 */
//Pierre lulu

typedef struct point
{
	float abscisse;
	float ordonnee;
} POINT;

typedef struct image {
	int   Nblig;
	int   Nbcol;
	unsigned char*  data;
	unsigned char** pixel;
} IMAGE;

typedef struct rgb {
	unsigned char R;
	unsigned char G;
	unsigned char B;
} RGB;

typedef struct imageRGB {
	int   Nblig;
	int   Nbcol;
	RGB*  data;
	RGB** pixel;
} IMAGERGB;

typedef struct signatures {
	int		min;
	int		max;
	double	moyenne;
	double	ecartType;
	int		mediane;
} SIGNATURES;

typedef struct signature_composantes_connexes {
	int surface;
	float perimetre;
	float compacite;
	int bord;
	POINT CG;
	float rayon;
	float a_i;
	float b_i;
	float a_j;
	float b_j;
} SIGNATURE_COMPOSANTE_CONNEXE;


IMAGE allocationImage(int Nblig, int Nbcol);
void initialisationAleatoireImage(IMAGE img, int ngMin, int ngMax);

void sauvegardeImage(IMAGE img, const char *type, const char *out);
void liberationImage(IMAGE *im);

IMAGE lectureImage(const char *nom);

IMAGERGB allocationImageRGB(int Nblig, int Nbcol);
IMAGERGB lectureImageRGB(const char *nom);

void sauvegardeImageRGB(IMAGERGB img, const char *type, const char *out);
void liberationImageRGB(IMAGERGB *im);

IMAGE planImage(IMAGERGB img, int plan);
IMAGE luminanceImage(IMAGERGB img, float r, float g, float b);
IMAGE inverseImage(IMAGE img);
IMAGE seuillageImage(IMAGE img, int sInf, int sSup);

int* histogrammeImage(IMAGE img, int choix, int n);
int* histogrammeImageRGB(IMAGERGB img, int choix, int n);
IMAGE expansionImage(IMAGE img, int outMin, int outMax);
IMAGE egalisationImage(IMAGE img);
SIGNATURES statistiquesImage(IMAGE img);

IMAGE seuillageOtsu(IMAGE img);

IMAGE labelImage(IMAGE img, int *nbComp); /* image label + nb composantes connexes */

IMAGERGB colorisationImage(IMAGE img, char* table);

IMAGE bruitAleatoireImage(IMAGE img, int amplitude);
IMAGERGB masqueImage(IMAGE img, IMAGERGB masque);


IMAGE erosionImage(IMAGE img, int voisinage);
IMAGE dilatationImage(IMAGE img, int voisinage);
IMAGE ouvertureImage(IMAGE img, int voisinage);
IMAGE fermetureImage(IMAGE img, int voisinage);
SIGNATURE_COMPOSANTE_CONNEXE* signaturesImage(IMAGE img, int nbComp);
void afficheSignatureComposanteConnexe(SIGNATURE_COMPOSANTE_CONNEXE* tab_sign, int nbComp);
void sauvegardeSignaturesImage(SIGNATURE_COMPOSANTE_CONNEXE* sig, int nbComp);

//EVALUATION 3
typedef struct tab_resistance {
	int nombre;
	float* data;
}TAB_RESISTANCE;

TAB_RESISTANCE allocTabResistance(int nb);
float resistanceEquivalente(TAB_RESISTANCE tab, int type);
TAB_RESISTANCE lectureData(const char* nom);
void enregistreData(const char* nom, TAB_RESISTANCE tab);

void regression(POINT* tab, int n, float* a, float* b);
void sortieRegression(const char* nom, POINT* pts, int n);
POINT* imageVersPoints(IMAGE img, int* n, char axe);
IMAGE imageSortieRegression(IMAGE img, char axe);
