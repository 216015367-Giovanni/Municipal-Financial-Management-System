#include <stdio.h>
#include "employees.h"

#define MAX_EMPLOYEES 100

int addEmployee(int employeeID[], char employeeName[][50],
                char department[][50], float basicSalary[],
                float housingAllowance[], float transportAllowance[],
                int employeeCount)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee limit reached.\n");
        return employeeCount;
    }

    printf("\n========== ADD EMPLOYEE ==========\n");

    printf("Enter Employee ID: ");
    scanf("%d", &employeeID[employeeCount]);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", employeeName[employeeCount]);

    printf("Enter Department: ");
    scanf(" %[^\n]", department[employeeCount]);

    printf("Enter Basic Salary: ");
    scanf("%f", &basicSalary[employeeCount]);

    printf("Enter Housing Allowance: ");
    scanf("%f", &housingAllowance[employeeCount]);

    printf("Enter Transport Allowance: ");
    scanf("%f", &transportAllowance[employeeCount]);

    employeeCount++;

    printf("\nEmployee added successfully!\n");

    return employeeCount;
}

int displayEmployees(int employeeID[], char employeeName[][50],
                     char department[][50], float basicSalary[],
                     float housingAllowance[], float transportAllowance[],
                     int employeeCount)
{
    int i;

    if (employeeCount == 0)
    {
        printf("\nNo employees found.\n");
        return 0;
    }

    printf("\n========== EMPLOYEE LIST ==========\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("-----------------------------\n");
        printf("ID: %d\n", employeeID[i]);
        printf("Name: %s\n", employeeName[i]);
        printf("Department: %s\n", department[i]);
        printf("Basic Salary: %.2f\n", basicSalary[i]);
        printf("Housing Allowance: %.2f\n", housingAllowance[i]);
        printf("Transport Allowance: %.2f\n", transportAllowance[i]);
    }

    return employeeCount;
}

int searchEmployee(int employeeID[], char employeeName[][50],
                   char department[][50], float basicSalary[],
                   float housingAllowance[], float transportAllowance[],
                   int employeeCount)
{
    int searchID;
    int i;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchID);

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeID[i] == searchID)
        {
            printf("\n========== EMPLOYEE FOUND ==========\n");
            printf("Employee ID: %d\n", employeeID[i]);
            printf("Name: %s\n", employeeName[i]);
            printf("Department: %s\n", department[i]);
            printf("Basic Salary: %.2f\n", basicSalary[i]);
            printf("Housing Allowance: %.2f\n", housingAllowance[i]);
            printf("Transport Allowance: %.2f\n", transportAllowance[i]);

            return 1;
        }
    }

    printf("\nEmployee not found.\n");

    return 0;
}

float calculateSalary(int employeeID[], float basicSalary[],
                      float housingAllowance[], float transportAllowance[],
                      int employeeCount)
{
    int searchID;
    int i;
    float totalSalary;

    printf("\nEnter Employee ID: ");
    scanf("%d", &searchID);

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeID[i] == searchID)
        {
            totalSalary = basicSalary[i] + housingAllowance[i] + transportAllowance[i];

            printf("\n========== SALARY INFORMATION ==========\n");
            printf("Basic Salary: %.2f\n", basicSalary[i]);
            printf("Housing Allowance: %.2f\n", housingAllowance[i]);
            printf("Transport Allowance: %.2f\n", transportAllowance[i]);

            return totalSalary;
        }
    }

    printf("\nEmployee not found.\n");

    return -1;
}

int displayEmployeeInformation(int employeeID[], char employeeName[][50],
                               char department[][50], float basicSalary[],
                               float housingAllowance[], float transportAllowance[],
                               int employeeCount)
{
    int searchID;
    int i;

    printf("\nEnter Employee ID: ");
    scanf("%d", &searchID);

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeID[i] == searchID)
        {
            printf("\n========== EMPLOYEE INFORMATION ==========\n");
            printf("Employee ID: %d\n", employeeID[i]);
            printf("Name: %s\n", employeeName[i]);
            printf("Department: %s\n", department[i]);
            printf("Basic Salary: %.2f\n", basicSalary[i]);
            printf("Housing Allowance: %.2f\n", housingAllowance[i]);
            printf("Transport Allowance: %.2f\n", transportAllowance[i]);

            return 1;
        }
    }

    printf("\nEmployee not found.\n");

    return 0;
}