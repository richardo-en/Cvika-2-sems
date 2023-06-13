#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { PIECE, KILOGRAM } UnitType;

typedef struct item {
    char name[50];
    char manufacturer[50];
    int count;
    float price;
    UnitType unit;
    struct item* next;
} Item;

Item* createItem(char* name, char* manufacturer, int count, float price, UnitType unit) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    strcpy(newItem->name, name);
    strcpy(newItem->manufacturer, manufacturer);
    newItem->count = count;
    newItem->price = price;
    newItem->unit = unit;
    newItem->next = NULL;
    return newItem;
}

void addItem(Item** head, Item* newItem) {
    Item* curr = *head;
    Item* prev = NULL;

    while (curr != NULL && strcmp(curr->name, newItem->name) < 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL && strcmp(curr->name, newItem->name) == 0) {
        curr->count += newItem->count;
        free(newItem);
    } else {
        newItem->next = curr;
        if (prev == NULL) {
            *head = newItem;
        } else {
            prev->next = newItem;
        }
    }
}



void deleteItem(Item** head, char* name) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Item* curr = *head;
    Item* prev = NULL;
    while (curr != NULL && strcmp(name, curr->name) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("%s not found in list\n", name);
        return;
    }

    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
    printf("%s deleted from list\n", name);
}

void printList(Item* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("%-20s%-20s%-10s%-10s%s\n", "Name", "Manufacturer", "Count", "Price", "Unit");
    printf("--------------------------------------------------------------------\n");
    Item* curr = head;
    while (curr != NULL) {
        printf("%-20s%-20s%-10d%-10.2f", curr->name, curr->manufacturer, curr->count, curr->price);
        if (curr->unit == PIECE) {
            printf("piece(s)\n");
        } else {
            printf("kilogram(s)\n");
        }
        curr = curr->next;
    }
}

int main() {
    Item* head = NULL;

    addItem(&head, createItem("Apples", "Farmer's Market", 10, 1.99, KILOGRAM));
    addItem(&head, createItem("Bananas", "Supermarket", 5, 0.50, KILOGRAM));
    addItem(&head, createItem("Bread", "Bakery", 2, 3.50, PIECE));
    addItem(&head, createItem("Milk", "Dairy Co.", 3, 1.50, PIECE));
    addItem(&head, createItem("Eggs", "Farm", 12, 2.50, PIECE));

    int choice;
    char name[50], manufacturer[50];
    int count;
    float price;
    UnitType unit;

    do {
        printf("\n");
        printf("1. Add item\n");
        printf("2. Delete item\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name of item: ");
                scanf("%s", name);
                printf("Enter manufacturer: ");
                scanf("%s", manufacturer);
                printf("Enter count: ");
                scanf("%d", &count);
                printf("Enter price: ");
                scanf("%f", &price);
                printf("Enter unit (0 for piece, 1 for kilogram): ");
                scanf("%d", (int*)&unit);
                addItem(&head, createItem(name, manufacturer, count, price, unit));
                printf("%s added to list\n", name);
                break;
            case 2:
                printf("Enter name of item: ");
                scanf("%s", name);
                deleteItem(&head, name);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    Item* curr = head;
    while (curr != NULL) {
        Item* temp = curr->next;
        free(curr);
        curr = temp;
    }

    return 0;
}
