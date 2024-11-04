// AIM: Implement sparse matrix using array

// THEORY: Sparse matrices are those matrices that have the majority of their elements
// equal to zero. In other words, the sparse matrix can be defined as the matrix that has
// a greater number of zero elements than the non-zero elements. Representing a sparse
// matrix by a 2D array leads to the wastage of lots of memory. This is because zeroes in
// the matrix are of no use, so storing zeroes with non-zero elements is wastage of
// memory. To avoid such wastage, we can store only non-zero elements. If we store only
// non-zero elements, it reduces the traversal time and the storage space. 

// ALGORITHM:
// Step 1)Define the variables to take input for row and column count.
// Step 2)Initialize all the elements of the 2D-array as zero.
// Step 3)Take the number of elements, the element and their insertion position as input.
// Step 4)Insert the elements in the matrix using for loop.
// Step 5)Print the sparse matrix. 

// CODE:


#include <stdio.h>

// Define the maximum size for the sparse matrix representation
#define MAX 100

// Structure to store each element of the sparse matrix
struct SparseMatrix {
    int row;
    int col;
    int value;
};

// Function to create sparse matrix representation
void createSparseMatrix(int matrix[][MAX], int rows, int cols, struct SparseMatrix sparse[], int *size) {
    *size = 0;  // Initialize size of sparse matrix representation

    // Traverse through the original matrix and store non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[*size].row = i;
                sparse[*size].col = j;
                sparse[*size].value = matrix[i][j];
                (*size)++;
            }
        }
    }
}

// Function to display the sparse matrix
void displaySparseMatrix(struct SparseMatrix sparse[], int size) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    int matrix[MAX][MAX];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    struct SparseMatrix sparse[MAX];
    int size;

    createSparseMatrix(matrix, rows, cols, sparse, &size);

    printf("\nSparse Matrix Representation:\n");
    displaySparseMatrix(sparse, size);

    return 0;
}
