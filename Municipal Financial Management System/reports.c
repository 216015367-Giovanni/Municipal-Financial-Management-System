#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "assets.h"

void reportsMenu(int employeeID[], char employeeName[][50],
                 char department[][50], float basicSalary[],
                 float housingAllowance[], float transportAllowance[],
                 int employeeCount)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("              REPORTS\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("0. Return to Main Menu\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int i;

            printf("\n========== EMPLOYEE REPORT ==========\n");

            if (employeeCount == 0)
            {
                printf("No employees available.\n");
                break;
            }

            printf("Total Employees: %d\n", employeeCount);

            printf("\nEmployee Details:\n");

            for (i = 0; i < employeeCount; i++)
            {
                printf("\nEmployee %d\n", i + 1);
                printf("-----------------------------\n");
                printf("Employee ID: %d\n", employeeID[i]);
                printf("Name: %s\n", employeeName[i]);
                printf("Department: %s\n", department[i]);
                printf("Basic Salary: N$%.2f\n", basicSalary[i]);
                printf("Housing Allowance: N$%.2f\n",
                       housingAllowance[i]);
                printf("Transport Allowance: N$%.2f\n",
                       transportAllowance[i]);
                printf("Total Salary: N$%.2f\n",
                       basicSalary[i] + housingAllowance[i] + transportAllowance[i]);
            }

            break;
        }
        case 2:
        {
            printf("\n========== BUDGET REPORT ==========\n");
            printf("Budget report is available.\n");
            break;
        }

        case 3:
        {
            printf("\n========== SUPPLIER REPORT ==========\n");
            printf("Supplier Report\n");
            printf("-----------------------------\n");

            printf("The registered suppliers can be viewed through\n");
            printf("the Supplier Management module.\n");

            break;
        }
        case 4:
        {
            printf("\n========== ASSET REPORT ==========\n");

            if (assetCount == 0)
            {
                printf("No assets available.\n");
            }
            else
            {
                printf("Total Assets: %d\n\n", assetCount);

                for (int i = 0; i < assetCount; i++)
                {
                    printf("Asset ID: %d\n", assets[i].assetID);
                    printf("Asset Name: %s\n", assets[i].assetName);
                    printf("Asset Type: %s\n", assets[i].assetType);
                    printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
                    printf("Department: %s\n", assets[i].department);
                    printf("Condition: %s\n", assets[i].condition);
                    printf("-----------------------------\n");
                }
            }

            break;
        }

        case 0:
            printf("\nReturning to Main Menu...\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);
}