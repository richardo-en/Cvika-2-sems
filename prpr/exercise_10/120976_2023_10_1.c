#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enumerated type for item type
typedef enum {
    PIECE,
    KILOGRAM
} ItemType;

// Union to store either piece count or weight in kilograms
typedef union {
    int pieces;
    float kilograms;
} Quantity;

// Structure for grocery item
typedef struct GroceryItem {
    char *name;
    char *manufacturer;
    Quantity quantity;
    float unitPrice;
    ItemType type;
    struct GroceryItem *next;
} GroceryItem;

// Function to add a new grocery item to the linked list
void add_item(GroceryItem **head, char *name, char *manufacturer, Quantity quantity, float unitPrice, ItemType type) {
    GroceryItem *newItem = malloc(sizeof(GroceryItem));
    newItem->name = strdup(name);
    newItem->manufacturer = strdup(manufacturer);
    newItem->quantity = quantity;
    newItem->unitPrice = unitPrice;
    newItem->type = type;

    GroceryItem *current = *head;
    GroceryItem *prev = NULL;

    // Find the correct position in the linked list based on the item name
    while (current != NULL && strcmp(name, current->name) > 0) {
        prev = current;
        current = current->next;
    }

    // Insert the new item into the linked list
    if (prev == NULL) {
        newItem->next = *head;
        *head = newItem;
    } else {
        newItem->next = current;
        prev->next = newItem;
    }
}

// Function to delete a grocery item from the linked list
void delete_item(GroceryItem **head, char *name) {
    GroceryItem *current = *head;
    GroceryItem *prev = NULL;

    // Find the item in the linked list based on the item name
    while (current != NULL && strcmp(name, current->name) != 0) {
        prev = current;
        current = current->next;
    }

    // Delete the item from the linked list
    if (current != NULL) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }

        free(current->name);
        free(current->manufacturer);
        free(current);
    }
}

// Function to print information about grocery items
void print_items(GroceryItem *head) {
    GroceryItem *current = head;

    while (current != NULL) {
        printf("Name: %s, Manufacturer: %s, ", current->name, current->manufacturer);

        if (current->type == PIECE) {
            printf("Quantity: %d pieces, ", current->quantity.pieces);
        } else if (current->type == KILOGRAM) {
            printf("Quantity: %.2f kg, ", current->quantity.kilograms);
        }

        printf("Unit Price: %.2f\n", current->unitPrice);

        current = current->next;
    }
}

// Function to free memory allocated for the linked list
void free_list(GroceryItem *head) {
    GroceryItem *current = head;
    while (current != NULL) {
        GroceryItem *next = current->next;
        free(current->name);
        free(current->manufacturer);
        free(current);
        current = next;
    }
}

int main() {
    GroceryItem *groceryList = NULL;

    // Example usage:
    add_item(&groceryList, "Apple", "FruitCo", (Quantity){.pieces = 10}, 0.50, PIECE);
    add_item(&groceryList, "Banana", "FruitCo", (Quantity){.pieces = 5}, 0.30, PIECE);
    add_item(&groceryList, "Potato", "VeggieCo", (Quantity){.kilograms = 2.5}, 1.20, KILOGRAM);

    printf("Initial Grocery List:\n");
    print_items(groceryList);

    delete_item(&groceryList, "Banana");

    printf("\nAfter deleting 'Banana':\n");
    print_items(groceryList);

    // Free allocated memory
    free_list(groceryList);

    return 0;
}
