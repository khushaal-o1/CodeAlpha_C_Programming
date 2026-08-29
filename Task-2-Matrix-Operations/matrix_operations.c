#include <stdio.h>

#define MAX 10

void printLine()
{
    printf("==========================================\n");
}

void inputMatrix(int matrix[MAX][MAX], int rows, int cols, const char name[])
{
    int i, j;

    printf("\nEnter values for %s:\n", name);
    printf("------------------------------------------\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%s[%d][%d] = ", name, i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    printf("\n");

    for (i = 0; i < rows; i++)
    {
        printf("   |");

        for (j = 0; j < cols; j++)
        {
            printf(" %5d", matrix[i][j]);
        }

        printf(" |\n");
    }
}

void matrixAddition()
{
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rows, cols, i, j;

    printf("\n");
    printLine();
    printf("              MATRIX ADDITION             \n");
    printLine();

    printf("\nRows    : ");
    scanf("%d", &rows);

    printf("Columns : ");
    scanf("%d", &cols);

    inputMatrix(a, rows, cols, "A");
    inputMatrix(b, rows, cols, "B");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nMatrix A:");
    displayMatrix(a, rows, cols);

    printf("\nMatrix B:");
    displayMatrix(b, rows, cols);

    printf("\nA + B:");
    displayMatrix(result, rows, cols);
}

void matrixMultiplication()
{
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2;
    int i, j, k;

    printf("\n");
    printLine();
    printf("          MATRIX MULTIPLICATION            \n");
    printLine();

    printf("\nFirst Matrix\n");
    printf("Rows    : ");
    scanf("%d", &rows1);

    printf("Columns : ");
    scanf("%d", &cols1);

    printf("\nSecond Matrix\n");
    printf("Rows    : ");
    scanf("%d", &rows2);

    printf("Columns : ");
    scanf("%d", &cols2);

    if (cols1 != rows2)
    {
        printf("\n------------------------------------------\n");
        printf("ERROR: Multiplication is not possible.\n");
        printf("Columns of Matrix A must equal rows of Matrix B.\n");
        printf("------------------------------------------\n");
        return;
    }

    inputMatrix(a, rows1, cols1, "A");
    inputMatrix(b, rows2, cols2, "B");

    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < cols2; j++)
        {
            result[i][j] = 0;

            for (k = 0; k < cols1; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nMatrix A:");
    displayMatrix(a, rows1, cols1);

    printf("\nMatrix B:");
    displayMatrix(b, rows2, cols2);

    printf("\nA x B:");
    displayMatrix(result, rows1, cols2);
}

void matrixTranspose()
{
    int matrix[MAX][MAX], transpose[MAX][MAX];
    int rows, cols, i, j;

    printf("\n");
    printLine();
    printf("              MATRIX TRANSPOSE            \n");
    printLine();

    printf("\nRows    : ");
    scanf("%d", &rows);

    printf("Columns : ");
    scanf("%d", &cols);

    inputMatrix(matrix, rows, cols, "A");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nOriginal Matrix:");
    displayMatrix(matrix, rows, cols);

    printf("\nTranspose Matrix:");
    displayMatrix(transpose, cols, rows);
}

int main()
{
    int choice;

    do
    {
        printf("\n");
        printLine();
        printf("        CODEALPHA MATRIX OPERATIONS        \n");
        printLine();

        printf("\n");
        printf("   [1]  Matrix Addition\n");
        printf("   [2]  Matrix Multiplication\n");
        printf("   [3]  Matrix Transpose\n");
        printf("   [4]  Exit\n");

        printf("\n------------------------------------------\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                matrixAddition();
                break;

            case 2:
                matrixMultiplication();
                break;

            case 3:
                matrixTranspose();
                break;

            case 4:
                printf("\n");
                printLine();
                printf("      Thank you for using the program!     \n");
                printLine();
                break;

            default:
                printf("\nInvalid choice. Please select 1 to 4.\n");
        }

        if (choice != 4)
        {
            printf("\nPress ENTER to return to the menu...");
            getchar();
            getchar();
        }

    } while (choice != 4);

    return 0;
}
