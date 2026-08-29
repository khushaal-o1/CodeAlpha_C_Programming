#include <stdio.h>

#define MAX 10

static void clearInputBuffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

static int readInt(const char *prompt, int *value)
{
    printf("%s", prompt);
    if (scanf("%d", value) != 1) {
        clearInputBuffer();
        return 0;
    }
    clearInputBuffer();
    return 1;
}

static int readDimensions(const char *name, int *rows, int *cols)
{
    printf("\n%s\n", name);
    if (!readInt("Rows    : ", rows) || !readInt("Columns : ", cols)) {
        printf("Invalid input. Rows and columns must be whole numbers.\n");
        return 0;
    }
    if (*rows < 1 || *rows > MAX || *cols < 1 || *cols > MAX) {
        printf("Invalid dimensions. Use values from 1 to %d.\n", MAX);
        return 0;
    }
    return 1;
}

static int inputMatrix(int matrix[MAX][MAX], int rows, int cols, const char *name)
{
    int i, j;
    printf("\nEnter values for Matrix %s:\n", name);
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            char prompt[40];
            snprintf(prompt, sizeof prompt, "%s[%d][%d] = ", name, i + 1, j + 1);
            if (!readInt(prompt, &matrix[i][j])) {
                printf("Invalid matrix value. Please use whole numbers.\n");
                return 0;
            }
        }
    }
    return 1;
}

static void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; ++i) {
        printf(" |");
        for (j = 0; j < cols; ++j) {
            printf(" %5d", matrix[i][j]);
        }
        printf(" |\n");
    }
}

static void matrixAddition(void)
{
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rows, cols, i, j;

    printf("\n========== MATRIX ADDITION ==========\n");
    if (!readDimensions("Matrix size", &rows, &cols) ||
        !inputMatrix(a, rows, cols, "A") ||
        !inputMatrix(b, rows, cols, "B")) {
        return;
    }

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\nA + B:\n");
    displayMatrix(result, rows, cols);
}

static void matrixMultiplication(void)
{
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2, i, j, k;

    printf("\n======= MATRIX MULTIPLICATION =======\n");
    if (!readDimensions("First matrix", &rows1, &cols1) ||
        !readDimensions("Second matrix", &rows2, &cols2)) {
        return;
    }
    if (cols1 != rows2) {
        printf("Multiplication is not possible: columns of A must equal rows of B.\n");
        return;
    }
    if (!inputMatrix(a, rows1, cols1, "A") ||
        !inputMatrix(b, rows2, cols2, "B")) {
        return;
    }

    for (i = 0; i < rows1; ++i) {
        for (j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (k = 0; k < cols1; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("\nA x B:\n");
    displayMatrix(result, rows1, cols2);
}

static void matrixTranspose(void)
{
    int matrix[MAX][MAX], transpose[MAX][MAX];
    int rows, cols, i, j;

    printf("\n========= MATRIX TRANSPOSE =========\n");
    if (!readDimensions("Matrix size", &rows, &cols) ||
        !inputMatrix(matrix, rows, cols, "A")) {
        return;
    }
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }
    printf("\nTranspose:\n");
    displayMatrix(transpose, cols, rows);
}

int main(void)
{
    int choice = 0;
    do {
        printf("\n==========================================\n");
        printf("       CODEALPHA MATRIX OPERATIONS\n");
        printf("==========================================\n");
        printf(" [1] Matrix Addition\n [2] Matrix Multiplication\n");
        printf(" [3] Matrix Transpose\n [4] Exit\n");

        if (!readInt("Select an option: ", &choice)) {
            printf("Invalid input. Please enter a number from 1 to 4.\n");
            continue;
        }
        switch (choice) {
        case 1: matrixAddition(); break;
        case 2: matrixMultiplication(); break;
        case 3: matrixTranspose(); break;
        case 4: printf("Thank you for using the program!\n"); break;
        default: printf("Invalid choice. Please select 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}
