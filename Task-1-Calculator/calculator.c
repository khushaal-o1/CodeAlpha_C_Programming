#include <stdio.h>

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

static int readDouble(const char *prompt, double *value)
{
    printf("%s", prompt);
    if (scanf("%lf", value) != 1) {
        clearInputBuffer();
        return 0;
    }
    clearInputBuffer();
    return 1;
}

int main(void)
{
    int choice = 0;
    double num1, num2, result;

    do {
        printf("\n========================================\n");
        printf("          CODEALPHA CALCULATOR\n");
        printf("========================================\n");
        printf(" [1] Addition\n [2] Subtraction\n [3] Multiplication\n");
        printf(" [4] Division\n [5] Exit\n");
        printf("----------------------------------------\n");

        if (!readInt("Select an option: ", &choice)) {
            printf("Invalid input. Please enter a number from 1 to 5.\n");
            continue;
        }

        if (choice >= 1 && choice <= 4) {
            if (!readDouble("Enter first number : ", &num1) ||
                !readDouble("Enter second number: ", &num2)) {
                printf("Invalid input. Please enter numeric values.\n");
                continue;
            }
        }

        switch (choice) {
        case 1:
            result = num1 + num2;
            printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result: %.2f x %.2f = %.2f\n", num1, num2, result);
            break;
        case 4:
            if (num2 == 0.0) {
                printf("Error: division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
            }
            break;
        case 5:
            printf("Thank you for using CodeAlpha Calculator!\n");
            break;
        default:
            printf("Invalid option. Please choose from 1 to 5.\n");
        }
    } while (choice != 5);

    return 0;
}
