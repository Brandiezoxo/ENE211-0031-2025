#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{
    char operator;
    double first, second;

    printf("=====================================\n");
    printf("   Welcome to my Simple Calculator!\n");
    printf("=====================================\n\n");

    printf("Please choose an operator (+, -, *, /, %%): ");
    scanf(" %c", &operator);

    printf("Great! Now enter two numbers, separated by a space: ");
    scanf("%lf %lf", &first, &second);

    printf("\n");

    switch(operator)
    {
    case '+':
        printf("%.2lf + %.2lf = %.2lf\n", first, second, first + second);
        break;
    case '-':
        printf("%.2lf - %.2lf = %.2lf\n", first, second, first - second);
        break;
    case '*':
        printf("%.2lf * %.2lf = %.2lf\n", first, second, first * second);
        break;
    case '/':
        if(second != 0.0)
            printf("%.2lf / %.2lf = %.2lf\n", first, second, first / second);
        else
            printf("Oops! Division by zero is not possible. Please try again with a different second number.\n");
        break;
    case '%':
        if(second != 0.0)
            printf("%.2lf %% %.2lf = %.2lf\n", first, second, fmod(first, second));
        else
            printf("Oops! Division by zero is not possible. Please try again with a different second number.\n");
        break;
    default:
        printf("Sorry, that operator is not recognised. Please use +, -, *, / or %%.\n");
    }

    printf("\nThank you for using my calculator. Have a wonderful day!\n");
    return 0;
}
