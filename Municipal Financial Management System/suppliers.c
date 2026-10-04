#include <stdio.h>
#include "suppliers.h"

#define MAX_SUPPLIERS 50

struct Supplier
{
    int id;
    char name[50];
    char email[50];
    char telephone[20];
    char location[50];
};

static struct Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

void supplierManagement(void)
{
    int choice;
    int i;
    int searchID;
    int found;

    do
    {
        printf("\n========================================\n");
        printf("       SUPPLIER MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("0. Return to Main Menu\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (supplierCount >= MAX_SUPPLIERS)
            {
                printf("\nSupplier limit reached.\n");
                continue;
            }

            printf("\n--- Add Supplier ---\n");

            printf("Enter Supplier ID: ");
            scanf("%d", &suppliers[supplierCount].id);

            printf("Enter Supplier Name: ");
            scanf(" %[^\n]", suppliers[supplierCount].name);

            printf("Enter Email: ");
            scanf(" %[^\n]", suppliers[supplierCount].email);

            printf("Enter Telephone Number: ");
            scanf(" %[^\n]", suppliers[supplierCount].telephone);

            printf("Enter Town/Location: ");
            scanf(" %[^\n]", suppliers[supplierCount].location);

            supplierCount++;

            printf("\nSupplier added successfully!\n");
        }

        else if (choice == 2)
        {
            printf("\n--- Supplier List ---\n");

            if (supplierCount == 0)
            {
                printf("No suppliers available.\n");
            }
            else
            {
                for (i = 0; i < supplierCount; i++)
                {
                    printf("\nSupplier %d\n", i + 1);
                    printf("-----------------------------\n");
                    printf("ID: %d\n", suppliers[i].id);
                    printf("Name: %s\n", suppliers[i].name);
                    printf("Email: %s\n", suppliers[i].email);
                    printf("Telephone: %s\n", suppliers[i].telephone);
                    printf("Location: %s\n", suppliers[i].location);
                }
            }
        }

        else if (choice == 3)
        {
            printf("\n--- Search Supplier ---\n");
            printf("Enter Supplier ID: ");
            scanf("%d", &searchID);

            found = 0;

            for (i = 0; i < supplierCount; i++)
            {
                if (suppliers[i].id == searchID)
                {
                    printf("\nSupplier Found!\n");
                    printf("ID: %d\n", suppliers[i].id);
                    printf("Name: %s\n", suppliers[i].name);
                    printf("Email: %s\n", suppliers[i].email);
                    printf("Telephone: %s\n", suppliers[i].telephone);
                    printf("Location: %s\n", suppliers[i].location);

                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                printf("\nSupplier not found.\n");
            }
        }

        else if (choice == 4)
        {
            int id1, id2;
            int first = -1;
            int second = -1;

            printf("\n--- Compare Suppliers ---\n");

            printf("Enter first Supplier ID: ");
            scanf("%d", &id1);

            printf("Enter second Supplier ID: ");
            scanf("%d", &id2);

            for (i = 0; i < supplierCount; i++)
            {
                if (suppliers[i].id == id1)
                {
                    first = i;
                }

                if (suppliers[i].id == id2)
                {
                    second = i;
                }
            }

            if (first == -1 || second == -1)
            {
                printf("\nOne or both suppliers were not found.\n");
            }
            else
            {
                printf("\n--- Supplier 1 ---\n");
                printf("ID: %d\n", suppliers[first].id);
                printf("Name: %s\n", suppliers[first].name);
                printf("Email: %s\n", suppliers[first].email);
                printf("Telephone: %s\n", suppliers[first].telephone);
                printf("Location: %s\n", suppliers[first].location);

                printf("\n--- Supplier 2 ---\n");
                printf("ID: %d\n", suppliers[second].id);
                printf("Name: %s\n", suppliers[second].name);
                printf("Email: %s\n", suppliers[second].email);
                printf("Telephone: %s\n", suppliers[second].telephone);
                printf("Location: %s\n", suppliers[second].location);
            }
        }

        else if (choice == 0)
        {
            printf("\nReturning to Main Menu...\n");
        }

        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);
}