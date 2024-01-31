#include <stdio.h>

// Fonction pour initialiser le graphe avec le nombre de sommets donné
void initializeGraph(int vertices, int adj_matrix[vertices][vertices]) {
    printf("Veuillez entrer les valeurs de la matrice adjacente du graphe :\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("Veuillez entrer la valeur de adj_matrix[%d][%d] : ", i, j);
            scanf("%d", &adj_matrix[i][j]);
        }
    }
}

// Fonction pour vérifier s'il existe un cycle  eulérien ou une chaîne eulérienne dans le graphe
void hasEulerianPath(int vertices, int adj_matrix[vertices][vertices]) {
    int odd_degrees = 0;

    // Vérifier si le graphe est connexe
    for (int i = 0; i < vertices; i++) {
        int sum = 0;
        for (int j = 0; j < vertices; j++) {
            sum += adj_matrix[i][j];
        }
        if (sum == 0) {
            printf("Le graphe n'est pas connexe, il n'a ni cycle  eulerien ni chaine eulerienne\n");
            return;
        }
    }

    // Compter le nombre de sommets de degré impair
    for (int i = 0; i < vertices; i++) {
        int sum = 0;
        for (int j = 0; j < vertices; j++) {
            sum += adj_matrix[i][j];
        }
        if (sum % 2 != 0) {
            odd_degrees++;
        }
    }

    // Si le nombre de sommets de degré impair est 0 ou 2, le graphe a un cycle  eulérien
    if (odd_degrees == 0) {
        printf("Le graphe a un cycle eulerien\n");
    }
    // Si le nombre de sommets de degré impair est 2, le graphe a une chaîne eulérienne
    else if (odd_degrees == 2) {
        printf("Le graphe a une chaine eulerienne\n");
    }
    // Sinon, le graphe n'a ni cycle  eulérien ni chaîne eulérienne
    else {
        printf("Le graphe n'a ni cycle eulerien ni chaine eulerienne\n");
    }
}

int main() {
    int vertices;
    printf("Veuillez entrer le nombre de sommets du graphe : ");
    scanf("%d", &vertices);

    int adj_matrix[vertices][vertices];
    initializeGraph(vertices, adj_matrix);
    hasEulerianPath(vertices, adj_matrix);

    return 0;
}
