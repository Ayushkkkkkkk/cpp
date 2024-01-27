#include <stdio.h>
#include <stdlib.h>

int main() {
    int numRows, numCols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &numRows);
    printf("Enter the number of columns: ");
    scanf("%d", &numCols);

    // Allocate memory for the 2D array (array of pointers)
    int **matrix = (int **)malloc(numRows * sizeof(int *));
    
    // Allocate memory for each row (array of integers)
    for (int i = 0; i < numRows; i++) {
        matrix[i] = (int *)malloc(numCols * sizeof(int));
    }

    // Input values into the 2D array
    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the entered matrix
    printf("\nEntered matrix:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the memory for each row
    for (int i = 0; i < numRows; i++) {
        free(matrix[i]);
    }

    // Free the memory for the array of pointers
    free(matrix);

    return 0;
}
