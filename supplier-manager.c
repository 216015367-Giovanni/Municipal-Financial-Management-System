#include <stdio.h>

// Structure for storing supplier information
struct Supplier
{
    int id;
    char name[50];
    char email[50];
    char telephone[20];
    char location[50];
};

int main()
{
    struct Supplier supplier[50];

    int choice;
    int count = 0;
    int i;
    int searchID;
    int found;

    do
    {
        printf("\n===== SUPPLIER MANAGEMENT SYSTEM =====\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Add Supplier
        if (choice == 1)
        {
            printf("\n--- Add Supplier ---\n");

            printf("Enter Supplier ID: ");
            scanf("%d", &supplier[count].id);

            printf("Enter Supplier Name: ");
            scanf(" %[^\n]", supplier[count].name);

            printf("Enter Email: ");
            scanf(" %[^\n]", supplier[count].email);

            printf("Enter Telephone Number: ");
            scanf(" %[^\n]", supplier[count].telephone);

            printf("Enter Town/Location: ");
            scanf(" %[^\n]", supplier[count].location);

            count++;

            printf("\nSupplier added successfully!\n");
        }

        // Display Suppliers
        else if (choice == 2)
        {
            printf("\n--- Supplier List ---\n");

            if (count == 0)
            {
                printf("No suppliers available.\n");
            }
            else
            {
                for (i = 0; i < count; i++)
                {
                    printf("\nSupplier %d\n", i + 1);
                    printf("ID: %d\n", supplier[i].id);
                    printf("Name: %s\n", supplier[i].name);
                    printf("Email: %s\n", supplier[i].email);
                    printf("Telephone: %s\n", supplier[i].telephone);
                    printf("Location: %s\n", supplier[i].location);
                }
            }
        }

        // Search Supplier
        else if (choice == 3)
        {
            printf("\n--- Search Supplier ---\n");

            printf("Enter Supplier ID: ");
            scanf("%d", &searchID);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (supplier[i].id == searchID)
                {
                    printf("\nSupplier Found!\n");
                    printf("ID: %d\n", supplier[i].id);
                    printf("Name: %s\n", supplier[i].name);
                    printf("Email: %s\n", supplier[i].email);
                    printf("Telephone: %s\n", supplier[i].telephone);
                    printf("Location: %s\n", supplier[i].location);

                    found = 1;
                }
            }

            if (found == 0)
            {
                printf("Supplier not found.\n");
            }
        }

        // Compare Suppliers
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

            // Find first supplier
            for (i = 0; i < count; i++)
            {
                if (supplier[i].id == id1)
                {
                    first = i;
                }

                if (supplier[i].id == id2)
                {
                    second = i;
                }
            }

            if (first == -1 || second == -1)
            {
                printf("One or both suppliers were not found.\n");
            }
            else
            {
                printf("\n--- Supplier 1 ---\n");
                printf("ID: %d\n", supplier[first].id);
                printf("Name: %s\n", supplier[first].name);
                printf("Email: %s\n", supplier[first].email);
                printf("Telephone: %s\n", supplier[first].telephone);
                printf("Location: %s\n", supplier[first].location);

                printf("\n--- Supplier 2 ---\n");
                printf("ID: %d\n", supplier[second].id);
                printf("Name: %s\n", supplier[second].name);
                printf("Email: %s\n", supplier[second].email);
                printf("Telephone: %s\n", supplier[second].telephone);
                printf("Location: %s\n", supplier[second].location);
            }
        }

        // Exit
        else if (choice == 5)
        {
            printf("\nGoodbye!\n");
        }

        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}