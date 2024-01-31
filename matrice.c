#include <stdio.h>

#define MAX_SOMMET 7

void initmatrice(int adjacencyMatrix[MAX_SOMMET][MAX_SOMMET]) {
    for (int i = 0; i < MAX_SOMMET; i++) {
        for (int j = 0; j < MAX_SOMMET; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void remplir(int adjacencyMatrix[MAX_SOMMET][MAX_SOMMET], int point1, int point2) {
    adjacencyMatrix[point1][point2] = 1;
    adjacencyMatrix[point2][point1] = 1;
}

void affiche(int adjacencyMatrix[MAX_SOMMET][MAX_SOMMET]) {
    for (int i = 0; i < MAX_SOMMET; i++) {
        for (int j = 0; j < MAX_SOMMET; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrice[MAX_SOMMET][MAX_SOMMET];
    initmatrice(matrice);

    int numEdges;

    // Saisie du nombre d'arêtes
    printf("Entrez le nombre d'aretes : ");
    scanf("%d", &numEdges);

    // Saisie des relations entre les arêtes
    printf("Entrez les relations entre les aretes (format : sommet1 sommet2) :\n");
    for (int i = 0; i < numEdges; i++) {
        int point1, point2;
        printf("Relation %d : ", i + 1);
        scanf("%d %d", &point1, &point2);
        remplir(matrice, point1 - 1, point2 - 1);
    }

    // Affichage de la matrice d'adjacence
    printf("\nVoici la Matrice d'adjacence de votre graphe :\n");
    affiche(matrice);

    return 0;
}
