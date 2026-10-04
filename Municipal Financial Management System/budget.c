#include <stdio.h>
#include "budget.h"

void budgetManagement()
{
    int numberOfDepartments;

    double expenditure;
    double remainingBudget;
    double departmentBudget;

    char departmentName[40];

    printf("\n========================================\n");
    printf("          BUDGET MANAGEMENT\n");
    printf("========================================\n");

    printf("Enter Number Of Departments: ");
    scanf("%d", &numberOfDepartments);

    if (numberOfDepartments < 0)
    {
        printf("invaid number of departments.\n");
        return;
    }

    for (int i = 1; i <= numberOfDepartments; i++)
    {
        getchar();

        printf("\nEnter Department Name: ");
        fgets(departmentName, sizeof(departmentName), stdin);

        printf("Enter Allocated Budget: ");
        scanf("%lf", &departmentBudget);
        if (departmentBudget < 0)
        {
            printf("Invalid allocated budget. Budget cannot be negative.\n");
            return;
        }

        printf("Enter Expenditure: ");
        scanf("%lf", &expenditure);

        if (expenditure < 0)
        {
            printf("Invalid expenditure. Expenditure cannot be negative.\n");
            return;
        }

        remainingBudget = departmentBudget - expenditure;

        printf("\n============= OUTPUT =============\n");

        printf("Department Name: %s", departmentName);
        printf("Allocated Budget: %.2lf\n", departmentBudget);
        printf("Expenditure: %.2lf\n", expenditure);
        printf("Remaining Budget: %.2lf\n", remainingBudget);

        if (expenditure <= departmentBudget)
        {
            printf("Status: WITHIN BUDGET\n");
        }
        else
        {
            printf("Status: EXCEEDED BUDGET\n");
            printf("%s has exceeded its allocated budget.\n",
                   departmentName);
        }
    }

    printf("\nBudget Management completed.\n");
}