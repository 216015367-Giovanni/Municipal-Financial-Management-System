#include <stdio.h>
#include <string.h>

#define MAX_ASSETS 100

typedef struct
{
    int assetID;
    char assetName[50];
    char assetType[30];
    float purchaseValue;
    char department[50];
    char condition[30];
} Asset;

Asset assets[MAX_ASSETS];
int assetCount = 0;

void addAsset(void)
{
    if (assetCount >= MAX_ASSETS)
    {
        printf("\nAsset register is full.\n");
        return;
    }

    printf("\n========== ADD ASSET ==========\n");

    printf("Enter Asset ID: ");
    scanf("%d", &assets[assetCount].assetID);
    getchar();

    printf("Enter Asset Name: ");
    fgets(assets[assetCount].assetName, 50, stdin);
    assets[assetCount].assetName[
        strcspn(assets[assetCount].assetName, "\n")
    ] = '\0';

    printf("Enter Asset Type: ");
    fgets(assets[assetCount].assetType, 30, stdin);
    assets[assetCount].assetType[
        strcspn(assets[assetCount].assetType, "\n")
    ] = '\0';

    do
    {
        printf("Enter Purchase Value (N$): ");
        scanf("%f", &assets[assetCount].purchaseValue);
        getchar();

        if (assets[assetCount].purchaseValue < 0)
        {
            printf("Purchase value cannot be negative.\n");
        }

    } while (assets[assetCount].purchaseValue < 0);

    printf("Enter Department: ");
    fgets(assets[assetCount].department, 50, stdin);
    assets[assetCount].department[
        strcspn(assets[assetCount].department, "\n")
    ] = '\0';

    printf("Enter Condition: ");
    fgets(assets[assetCount].condition, 30, stdin);
    assets[assetCount].condition[
        strcspn(assets[assetCount].condition, "\n")
    ] = '\0';

    assetCount++;

    printf("\nAsset added successfully.\n");
}

void displayAssets(void)
{
    int i;

    if (assetCount == 0)
    {
        printf("\nNo assets have been registered.\n");
        return;
    }

    printf("\n========== ASSET REGISTER ==========\n");

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("-----------------------------\n");
        printf("Asset ID       : %d\n", assets[i].assetID);
        printf("Asset Name     : %s\n", assets[i].assetName);
        printf("Asset Type     : %s\n", assets[i].assetType);
        printf("Purchase Value : N$ %.2f\n", assets[i].purchaseValue);
        printf("Department     : %s\n", assets[i].department);
        printf("Condition      : %s\n", assets[i].condition);
    }
}

void searchAsset(void)
{
    int searchID;
    int i;
    int found = 0;

    if (assetCount == 0)
    {
        printf("\nNo assets have been registered.\n");
        return;
    }

    printf("\n========== SEARCH ASSET ==========\n");
    printf("Enter Asset ID: ");
    scanf("%d", &searchID);

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].assetID == searchID)
        {
            printf("\nAsset found.\n");
            printf("-----------------------------\n");
            printf("Asset ID       : %d\n", assets[i].assetID);
            printf("Asset Name     : %s\n", assets[i].assetName);
            printf("Asset Type     : %s\n", assets[i].assetType);
            printf("Purchase Value : N$ %.2f\n", assets[i].purchaseValue);
            printf("Department     : %s\n", assets[i].department);
            printf("Condition      : %s\n", assets[i].condition);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nAsset not found.\n");
    }
}

void assetManagement(void)
{
    int choice;

    do
    {
        printf("\n================================\n");
        printf("        ASSET MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Exit\n");
        printf("================================\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                addAsset();
                break;

            case 2:
                displayAssets();
                break;

            case 3:
                searchAsset();
                break;

            case 4:
                printf("\nGoodbye.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);
}

int main(void)
{
    assetManagement();

    return 0;
}
