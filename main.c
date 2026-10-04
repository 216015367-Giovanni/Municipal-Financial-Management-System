#include 

int main(void) {
    int choice;
    while (1) {
        printf("\n=== MUNICIPAL FINANCIAL MANAGEMENT SYSTEM ===\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        
        if (choice == 6) {
            printf("Exiting system...\n");
            break;
        }
    }
    return 0;
}
