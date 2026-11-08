/*
 * EEC 2202: Structured Programming
 * Assignment 3 - Functions
 * Task 1: Simulated ATM System
 */

#include <stdio.h>
#include <stdbool.h>

#define CORRECT_PIN   1234
#define MAX_ATTEMPTS  3

/* The account balance. Every function can see it. */
double balance = 5000.00;

/* ---------- Helper: throw away leftover characters after a bad input ---------- */
void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* keep reading until the end of the line */
    }
}

/* ---------- Requirement 1: Login ---------- */
bool login(void)
{
    int pin;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS)
    {
        printf("Enter your PIN: ");

        if (scanf("%d", &pin) != 1)
        {
            clearInputBuffer();   /* user typed letters, not a number */
            pin = -1;             /* a value that can never match */
        }

        if (pin == CORRECT_PIN)
        {
            printf("\nLogin successful. Welcome!\n");
            return true;
        }

        attempts++;
        printf("Wrong PIN. Attempts left: %d\n\n", MAX_ATTEMPTS - attempts);
    }

    printf("Too many failed attempts. Access denied.\n");
    return false;
}

/* ---------- Requirement 2: Menu ---------- */
void showMenu(void)
{
    printf("\n===== ATM MENU =====\n");
    printf("1. Balance Inquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

/* ---------- Requirement 3: Operations ---------- */
void checkBalance(void)
{
    printf("\nYour current balance is: %.2f\n", balance);
}

void deposit(double amount)
{
    /* Requirement 5: amount must be positive */
    if (amount <= 0)
    {
        printf("\nInvalid amount. Deposit must be greater than zero.\n");
        return;
    }

    balance += amount;
    printf("\nDeposited %.2f successfully.\n", amount);
    printf("New balance: %.2f\n", balance);
}

void withdraw(double amount)
{
    /* Requirement 5: amount must be positive */
    if (amount <= 0)
    {
        printf("\nInvalid amount. Withdrawal must be greater than zero.\n");
        return;
    }

    /* Requirement 5: cannot take out more than we have */
    if (amount > balance)
    {
        printf("\nInsufficient funds. Your balance is %.2f\n", balance);
        return;
    }

    balance -= amount;
    printf("\nWithdrew %.2f successfully.\n", amount);
    printf("New balance: %.2f\n", balance);
}

/* ---------- Main program ---------- */
int main(void)
{
    int choice;
    double amount;

    printf("=== SIMULATED ATM ===\n\n");

    /* Stop the program if login fails */
    if (!login())
    {
        return 1;
    }

    /* Requirement 4: keep showing the menu until the user picks Exit */
    do
    {
        showMenu();

        if (scanf("%d", &choice) != 1)
        {
            clearInputBuffer();
            choice = 0;   /* will fall into the default case below */
        }

        switch (choice)
        {
            case 1:
                checkBalance();
                break;

            case 2:
                printf("Enter amount to deposit: ");
                if (scanf("%lf", &amount) != 1)
                {
                    clearInputBuffer();
                    amount = -1;   /* treated as invalid by deposit() */
                }
                deposit(amount);
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                if (scanf("%lf", &amount) != 1)
                {
                    clearInputBuffer();
                    amount = -1;   /* treated as invalid by withdraw() */
                }
                withdraw(amount);
                break;

            case 4:
                printf("\nThank you for using our ATM. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please enter 1, 2, 3 or 4.\n");
        }

    } while (choice != 4);

    return 0;
}
