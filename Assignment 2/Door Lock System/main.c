#include <stdio.h>
#include <string.h>

/* Cross-platform delay: Sleep() on Windows, sleep() on Linux/Mac */
#ifdef _WIN32
    #include <windows.h>
    #define wait_one_second() Sleep(1000)
#else
    #include <unistd.h>
    #define wait_one_second() sleep(1)
#endif

#define MAX_ATTEMPTS 3
#define PIN_LENGTH   4
#define LOCKOUT_SECS 5

int main(void)
{
    const char correctPin[] = "1234";   /* the secret PIN */
    char input[50];                     /* what the user types (as text) */
    int attempts;
    int accessGranted = 0;
    int choice;
    int i, len;

    printf("=== PIN-Based Door Lock System ===\n");

    /* Keep going until the user gets in */
    while (!accessGranted)
    {
        attempts = 0;

        /* The user gets 3 attempts per round */
        while (attempts < MAX_ATTEMPTS && !accessGranted)
        {
            printf("\nEnter your 4-digit PIN: ");
            scanf("%49s", input);
            len = strlen(input);

            /* Step 1: if-else-if to check the PIN length */
            if (len < PIN_LENGTH)
            {
                printf("PIN is too short (must be 4 digits)\n");
            }
            else if (len > PIN_LENGTH)
            {
                printf("PIN is too long (must be 4 digits)\n");
            }
            else
            {
                printf("PIN is exactly 4 digits\n");
            }

            /* Step 2: check if the PIN is correct */
            if (len == PIN_LENGTH && strcmp(input, correctPin) == 0)
            {
                accessGranted = 1;
                printf("Correct PIN!\n");
            }
            else
            {
                attempts++;
                if (attempts < MAX_ATTEMPTS)
                {
                    printf("Incorrect PIN. Attempts remaining: %d\n",
                           MAX_ATTEMPTS - attempts);
                }
            }
        }

        /* Step 3: too many wrong tries -> lockout with countdown */
        if (!accessGranted)
        {
            printf("\nSystem locked! Wait for %d seconds...\n", LOCKOUT_SECS);
            for (i = LOCKOUT_SECS; i >= 1; i--)
            {
                printf("%d... ", i);
                fflush(stdout);
                wait_one_second();
            }
            printf("\nYou can try again now.\n");
        }
    }

    /* Step 4: menu (only reached after the correct PIN) */
    do
    {
        printf("\n=== Device Menu ===\n");
        printf("1. Open Door\n");
        printf("2. Change Username\n");
        printf("3. Change PIN\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        /* If the user types a letter instead of a number */
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');  /* clear the bad input */
            choice = 0;                 /* will fall into default */
        }

        switch (choice)
        {
            case 1:
                printf("Access granted. Door unlocked\n");
                break;
            case 2:
                printf("Change username feature coming soon.\n");
                break;
            case 3:
                printf("Change PIN feature coming soon.\n");
                break;
            case 4:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
