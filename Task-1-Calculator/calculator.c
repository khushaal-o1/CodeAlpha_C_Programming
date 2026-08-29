#include <stdio.h>

int main()
{
    int choice;
    double num1, num2, result;

    do
    {
        printf("\n");
        printf("========================================\n");
        printf("          CODEALPHA CALCULATOR          \n");
        printf("========================================\n");
        printf("                                        \n");
        printf("   [1]  Addition                        \n");
        printf("   [2]  Subtraction                     \n");
        printf("   [3]  Multiplication                  \n");
        printf("   [4]  Division                        \n");
        printf("   [5]  Exit                            \n");
        printf("                                        \n");
        printf("----------------------------------------\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4)
        {
            printf("\n");
            printf("Enter first number  : ");
            scanf("%lf", &num1);

            printf("Enter second number : ");
            scanf("%lf", &num2);
        }

        printf("\n----------------------------------------\n");

        switch (choice)
        {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("Result: %.2lf x %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                if (num2 != 0)
                {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                else
                {
                    printf("ERROR: Division by zero is not allowed.\n");
                }
                break;

            case 5:
                printf("Thank you for using CodeAlpha Calculator!\n");
                printf("Program closed successfully.\n");
                break;

            default:
                printf("Invalid option. Please choose from 1 to 5.\n");
        }

        printf("----------------------------------------\n");

        if (choice != 5)
        {
            printf("\nPress ENTER to continue...");
            getchar();
            getchar();
        }

    } while (choice != 5);

    return 0;
}
