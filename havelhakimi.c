#include <stdio.h>
#include <stdbool.h>

void trierDecroissant(int arr[], int n) {
    // Simple tri à bulles en ordre décroissant
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Échanger arr[j] et arr[j+1] s'ils ne sont pas dans le bon ordre
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void afficherSequenceDegres(int degrees[], int n) {
    printf("Sequence de Degres :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", degrees[i]);
    }
    printf("\n");
}

void havelHakimiVersSequenceDegres(int adjMatrix[][100], int n, int degrees[]) {
    // Initialiser la séquence de degrés avec des zéros
    for (int i = 0; i < n; i++) {
        degrees[i] = 0;
    }

    // Calculer les degrés à partir de la matrice d'adjacence
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            degrees[i] += adjMatrix[i][j];
        }
    }

    // Trier la séquence de degrés par ordre non croissant
    trierDecroissant(degrees, n);
}

int grapheExiste(int a[], int n) {
    // Effectuer les opérations jusqu'à ce qu'une
    // des conditions d'arrêt soit rencontrée
    while (1) {
        // Trier le tableau par ordre non décroissant
        trierDecroissant(a, n);

        // Vérifier si tous les éléments sont égaux à 0
        if (a[0] == 0 && a[n - 1] == 0) {
            return 1; // Vrai
        }

        // Stocker le premier élément dans une variable
        // et le supprimer du tableau
        int v = a[0];
        for (int i = 0; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;

        // Vérifier si suffisamment d'éléments sont présents dans le tableau
        if (v > n) {
            return 0; // Faux
        }

        // Soustraire le premier élément des v éléments suivants
        for (int i = 0; i < v; i++) {
            a[i] -= 1;

            // Vérifier si un élément négatif est rencontré après la soustraction
            if (a[i] < 0) {
                return 0; // Faux
            }
        }
    }
}

int main() {
    int sequenceDegres[100] = {0}; // En supposant un maximum de 100 sommets
    int n; // Nombre de sommets

    // Entrer le nombre de sommets
    printf("Entrez le nombre de sommets : ");
    scanf("%d", &n);

    int matriceAdjacence[100][100];

    // Entrer la matrice d'adjacence pour un graphe non orienté
    printf("Entrez la matrice d'adjacence (0 ou 1) :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriceAdjacence[i][j]);
        }
    }

    printf("Matrice d'Adjacence :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriceAdjacence[i][j]);
        }
        printf("\n");
    }

    havelHakimiVersSequenceDegres(matriceAdjacence, n, sequenceDegres);
    
    printf("Sequence de Degres : ");
    afficherSequenceDegres(sequenceDegres, n);

    if (grapheExiste(sequenceDegres, n)) {
        printf("Oui\n");
    } else {
        printf("Non\n");
    }

    return 0;
}
