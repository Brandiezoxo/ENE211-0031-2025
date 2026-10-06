#include <stdio.h>
#include <stdlib.h>

#define CORRECT_PIN 9999
#define MAX_ATTEMPTS 3


int readPin(void)
{
    int pin;
    int result;

    while ((result = scanf("%d", &pin)) != 1)
    {
        if (result == EOF) exit(1);          // input closed, stop
        printf("Numbers only. Try again: ");
        while (getchar() != '\n');           // throw away the bad characters
    }
    return pin;
}

int main(void)
{
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS)
    {
        printf("Enter pin: ");
        int userPin = readPin();

        if (userPin < 1000 || userPin > 9999)
        {
            printf("Enter a four digit pin\n");
        }
        else if (userPin == CORRECT_PIN)
        {
            printf("Access Granted\n");
            return 0;
        }
        else
        {
            attempts++;
            printf("Access Denied. Attempts left: %d\n", MAX_ATTEMPTS - attempts);
        }
    }

    printf("Too many wrong attempts. You are locked out.\n");
    return 0;
}
