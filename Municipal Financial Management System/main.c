#include <stdio.h>

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

#define MAX_EMPLOYEES 100

int main()
{
    int employeeID[MAX_EMPLOYEES];
    char employeeName[MAX_EMPLOYEES][50];
    char department[MAX_EMPLOYEES][50];
    float basicSalary[MAX_EMPLOYEES];
    float housingAllowance[MAX_EMPLOYEES];
    float transportAllowance[MAX_EMPLOYEES];

    int employeeCount = 0;
    int choice;

    do
    {

        printf("\n========================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("0. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n')
            {
                /* Clear invalid input */
            }

            continue;
        }

        switch (choice)
        {
        case 1:
            employeeCount = addEmployee(

                employeeID,
                employeeName,
                department,
                basicSalary,
                housingAllowance,
                transportAllowance,
                employeeCount);
            break;

        case 2:
            budgetManagement();
            break;

        case 3:
            supplierManagement();
            break;

        case 4:
            assetManagement();
            break;

        case 5:
            reportsMenu(employeeID, employeeName, department,
                        basicSalary, housingAllowance,
                        transportAllowance, employeeCount);
            break;

        case 0:
            printf("Exiting system...\n");
            break;

        default:
            printf("Invalid choice. Please choose between 0 and 5.\n");
        }
    } while (choice != 0);

    return 0;
}