#include <stdio.h>
#define MAX 10 // Maximum size of the set

// Function to check if the relation is reflexive
int isReflexive(int rel[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        // Reflexive means every (i, i) must be 1
        if (rel[i][i] != 1)
            return 0;
    }
    return 1;
}

// Function to check if the relation is anti-symmetric
int isAntiSymmetric(int rel[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Anti-symmetric: if (i, j) and (j, i) both exist, i must be equal to j
            if (i != j && rel[i][j] == 1 && rel[j][i] == 1)
                return 0;
        }
    }
    return 1;
}

// Function to check if the relation is transitive
int isTransitive(int rel[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If there is a path from i to j
            if (rel[i][j]) {
                for (int k = 0; k < n; k++) {
                    // and a path from j to k, then there must be a path from i to k
                    if (rel[j][k] && !rel[i][k])
                        return 0;
                }
            }
        }
    }
    return 1;
}

// Function to print the relation matrix (hasse diagram)
void printRelationMatrix(int rel[MAX][MAX], int n) {
    printf("\nHasse Diagram (Relation Matrix):\n   ");
    for (int i = 0; i < n; i++)
        printf("%d ", i); // Print column headers
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d| ", i); // Print row headers
        for (int j = 0; j < n; j++) {
            printf("%d ", rel[i][j]); // Print relation values
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n; // Number of elements in the set
    int relation[MAX][MAX]; // 2D matrix to store relation

    // Input: number of elements in the set
    printf("Enter number of elements in set (max %d): ", MAX);
    scanf("%d", &n);

    // Input: relation matrix (0 or 1)
    printf("Enter the relation matrix (%d x %d):\n", n, n);
    printf("Enter 1 if (i, j) is in relation, else 0:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &relation[i][j]);
        }
    }

    // Check each property of a poset
    int reflexive = isReflexive(relation, n);
    int antisymmetric = isAntiSymmetric(relation, n);
    int transitive = isTransitive(relation, n);

    // Final result
    if (reflexive && antisymmetric && transitive) {
        printf("\n The relation is a POSET (Partially Ordered Set).\n");
        printRelationMatrix(relation, n); // Show hasse diagram
    } else {
        printf("\n The relation is NOT a POSET.\n");

        // Print reasons why it is not a poset
        if (!reflexive)
            printf(" - It is not Reflexive.\n");
        if (!antisymmetric)
            printf(" - It is not Anti-symmetric.\n");
        if (!transitive)
            printf(" - It is not Transitive.\n");
    }

    return 0;
}


