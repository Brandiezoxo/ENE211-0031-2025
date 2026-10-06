#include <stdio.h>

int main(void)
{
    int marks;

    printf("Enter marks (0-100): ");

    if (scanf("%d", &marks) != 1)
    {
        printf("Numbers only.\n");
        return 1;
    }

    if (marks < 0 || marks > 100)
    {
        printf("Marks must be between 0 and 100.\n");
    }
    else if (marks >= 70)
    {
        printf("Grade: A\n");
    }
    else if (marks >= 60)
    {
        printf("Grade: B\n");
    }
    else if (marks >= 50)
    {
        printf("Grade: C\n");
    }
    else if (marks >= 40)
    {
        printf("Grade: D\n");
    }
    else
    {
        printf("Grade: E (Fail)\n");
    }

    return 0;
}
