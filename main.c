/* ============================================================
   PAP521S - PROGRAMMING IN PRACTICE
   PROJECT A: MUNICIPAL FINANCIAL MANAGEMENT SYSTEM (MFMS)

   main.c
   Holds the master data arrays (Employees, Budget, Suppliers,
   Assets), the main menu, and the sub-menu loop for each
   module. All actual processing is delegated to functions in
   the other modules, which receive the arrays as parameters --
   this keeps main() short and avoids one giant function, as
   required by Project A Section 9.

   Compile:
     gcc -std=c99 -Wall main.c employees.c budget.c suppliers.c assets.c reports.c utils.c -o mfms
   Run:
     ./mfms          (Linux/macOS)
     mfms.exe        (Windows)
   ============================================================ */

#include <stdio.h>
#include "config.h"
#include "utils.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

/* ---- Function prototypes for this file ---- */
void displayMainMenu(void);
void employeeMenu(int ids[], char names[][NAME_LEN], char depts[][DEPT_LEN],
                   float basic[], float housing[], float transport[], int *count);
void budgetMenu(char deptNames[][DEPT_LEN], float allocated[], float expenditure[],
                 int *count);
void supplierMenu(int ids[], char names[][SUP_NAME_LEN], char emails[][EMAIL_LEN],
                   char phones[][PHONE_LEN], char towns[][TOWN_LEN], int *count);
void assetMenu(int ids[], char names[][ASSET_NAME_LEN], char types[][ASSET_TYPE_LEN],
                float values[], char depts[][DEPT_LEN], char conditions[][CONDITION_LEN],
                int *count);

int main(void)
{
    /* ---------- Employee data (parallel arrays) ---------- */
    int   employeeIDs[MAX_EMPLOYEES];
    char  employeeNames[MAX_EMPLOYEES][NAME_LEN];
    char  employeeDepts[MAX_EMPLOYEES][DEPT_LEN];
    float basicSalary[MAX_EMPLOYEES];
    float housing[MAX_EMPLOYEES];
    float transport[MAX_EMPLOYEES];
    int   employeeCount = 0;

    /* ---------- Budget data (parallel arrays) ---------- */
    char  deptNames[MAX_DEPARTMENTS][DEPT_LEN];
    float allocated[MAX_DEPARTMENTS];
    float expenditure[MAX_DEPARTMENTS];
    int   deptCount = 0;

    /* ---------- Supplier data (parallel arrays) ---------- */
    int   supplierIDs[MAX_SUPPLIERS];
    char  supplierNames[MAX_SUPPLIERS][SUP_NAME_LEN];
    char  supplierEmails[MAX_SUPPLIERS][EMAIL_LEN];
    char  supplierPhones[MAX_SUPPLIERS][PHONE_LEN];
    char  supplierTowns[MAX_SUPPLIERS][TOWN_LEN];
    int   supplierCount = 0;

    /* ---------- Asset data (parallel arrays) ---------- */
    int   assetIDs[MAX_ASSETS];
    char  assetNames[MAX_ASSETS][ASSET_NAME_LEN];
    char  assetTypes[MAX_ASSETS][ASSET_TYPE_LEN];
    float assetValues[MAX_ASSETS];
    char  assetDepts[MAX_ASSETS][DEPT_LEN];
    char  assetConditions[MAX_ASSETS][CONDITION_LEN];
    int   assetCount = 0;

    int choice;

    do
    {
        displayMainMenu();
        choice = readValidInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                employeeMenu(employeeIDs, employeeNames, employeeDepts,
                             basicSalary, housing, transport, &employeeCount);
                break;

            case 2:
                budgetMenu(deptNames, allocated, expenditure, &deptCount);
                break;

            case 3:
                supplierMenu(supplierIDs, supplierNames, supplierEmails,
                             supplierPhones, supplierTowns, &supplierCount);
                break;

            case 4:
                assetMenu(assetIDs, assetNames, assetTypes, assetValues,
                          assetDepts, assetConditions, &assetCount);
                break;

            case 5:
                reportsMenu(employeeIDs, employeeNames, employeeDepts,
                            basicSalary, housing, transport, employeeCount,
                            deptNames, allocated, expenditure, deptCount,
                            supplierIDs, supplierNames, supplierTowns, supplierCount,
                            assetNames, assetValues, assetCount);
                break;

            case 6:
                printf("\nThank you for using the Municipal Financial Management System.\n");
                break;

            default:
                printf("\nInvalid choice. Please select an option between 1 and 6.\n");
        }

    } while (choice != 6);

    return 0;
}

/* Displays the main menu (Project A Section 3, Module 1). */
void displayMainMenu(void)
{
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
}

/* ---------------- Employee Management sub-menu ---------------- */
void employeeMenu(int ids[], char names[][NAME_LEN], char depts[][DEPT_LEN],
                   float basic[], float housing[], float transport[], int *count)
{
    int choice;

    do
    {
        printf("\n------- EMPLOYEE MANAGEMENT -------\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Back to Main Menu\n");

        choice = readValidInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                addEmployee(ids, names, depts, basic, housing, transport, count);
                break;
            case 2:
                displayEmployees(ids, names, depts, basic, housing, transport, *count);
                break;
            case 3:
                searchEmployeeMenu(ids, names, depts, basic, housing, transport, *count);
                break;
            case 4:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please select an option between 1 and 4.\n");
        }

    } while (choice != 4);
}

/* ---------------- Budget Management sub-menu ---------------- */
void budgetMenu(char deptNames[][DEPT_LEN], float allocated[], float expenditure[],
                 int *count)
{
    int choice;

    do
    {
        printf("\n------- BUDGET MANAGEMENT -------\n");
        printf("1. Enter Department Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Back to Main Menu\n");

        choice = readValidInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                enterBudget(deptNames, allocated, expenditure, count);
                break;
            case 2:
                displayBudgets(deptNames, allocated, expenditure, *count);
                break;
            case 3:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please select an option between 1 and 3.\n");
        }

    } while (choice != 3);
}

/* ---------------- Supplier Management sub-menu ---------------- */
void supplierMenu(int ids[], char names[][SUP_NAME_LEN], char emails[][EMAIL_LEN],
                   char phones[][PHONE_LEN], char towns[][TOWN_LEN], int *count)
{
    int choice;

    do
    {
        printf("\n------- SUPPLIER MANAGEMENT -------\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");

        choice = readValidInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                addSupplier(ids, names, emails, phones, towns, count);
                break;
            case 2:
                displaySuppliers(ids, names, emails, phones, towns, *count);
                break;
            case 3:
                searchSupplierMenu(ids, names, emails, phones, towns, *count);
                break;
            case 4:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please select an option between 1 and 4.\n");
        }

    } while (choice != 4);
}

/* ---------------- Asset Management sub-menu ---------------- */
void assetMenu(int ids[], char names[][ASSET_NAME_LEN], char types[][ASSET_TYPE_LEN],
                float values[], char depts[][DEPT_LEN], char conditions[][CONDITION_LEN],
                int *count)
{
    int choice;

    do
    {
        printf("\n------- ASSET MANAGEMENT -------\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back to Main Menu\n");

        choice = readValidInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                addAsset(ids, names, types, values, depts, conditions, count);
                break;
            case 2:
                displayAssets(ids, names, types, values, depts, conditions, *count);
                break;
            case 3:
                searchAssetMenu(ids, names, types, values, depts, conditions, *count);
                break;
            case 4:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please select an option between 1 and 4.\n");
        }

    } while (choice != 4);
}
