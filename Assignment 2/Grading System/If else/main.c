#include <stdio.h>

int main(void)
{
    int n, i;
    int regNo, marks;
    char name[50];
    char grade;
    const char *status;

    printf("=== Student Grading System (if-else) ===\n");
    printf("How many students? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\n--- Student %d of %d ---\n", i, n);

        printf("Enter registration number: ");
        scanf("%d", &regNo);

        printf("Enter name: ");
        scanf(" %49[^\n]", name);   /* reads names with spaces */

        /* Keep asking until marks are valid */
        do
        {
            printf("Enter marks (0-100): ");
            scanf("%d", &marks);
            if (marks < 0 || marks > 100)
            {
                printf("Invalid marks! Must be between 0 and 100.\n");
            }
        } while (marks < 0 || marks > 100);

        /* Grade using if-else if */
        if (marks >= 70)
        {
            grade = 'A';
        }
        else if (marks >= 60)
        {
            grade = 'B';
        }
        else if (marks >= 50)
        {
            grade = 'C';
        }
        else if (marks >= 40)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }

        /* Pass or fail using if-else */
        if (marks >= 40)
        {
            status = "Pass";
        }
        else
        {
            status = "Fail";
        }

        /* Display the result immediately */
        printf("\n----------------------------------\n");
        printf("        STUDENT INFORMATION\n");
        printf("----------------------------------\n");
        printf("Registration No: %d\n", regNo);
        printf("Name: %s\n", name);
        printf("Marks: %d\n", marks);
        printf("Grade: %c\n", grade);
        printf("Status: %s\n", status);
        printf("----------------------------------\n");
    }

    return 0;
}
