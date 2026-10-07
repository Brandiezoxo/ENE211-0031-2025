#include <stdio.h>

int main(void)
{
    int n, i;
    int regNo, marks;
    char name[50];
    char grade;
    const char *status;

    printf("=== Student Grading System (switch) ===\n");
    printf("How many students? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\n--- Student %d of %d ---\n", i, n);

        printf("Enter registration number: ");
        scanf("%d", &regNo);

        printf("Enter name: ");
        scanf(" %49[^\n]", name);

        do
        {
            printf("Enter marks (0-100): ");
            scanf("%d", &marks);
            if (marks < 0 || marks > 100)
            {
                printf("Invalid marks! Must be between 0 and 100.\n");
            }
        } while (marks < 0 || marks > 100);

        /* switch works on whole numbers, so use marks / 10 */
        switch (marks / 10)
        {
            case 10:
            case 9:
            case 8:
            case 7:
                grade = 'A';
                status = "Pass";
                break;
            case 6:
                grade = 'B';
                status = "Pass";
                break;
            case 5:
                grade = 'C';
                status = "Pass";
                break;
            case 4:
                grade = 'D';
                status = "Pass";
                break;
            default:
                grade = 'F';
                status = "Fail";
        }

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
