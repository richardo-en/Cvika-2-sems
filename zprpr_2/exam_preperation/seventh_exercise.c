#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char c;
    struct node *next;
} node_t;

void append(node_t **head, int n);

int main(int argc, char const *argv[])
{
    node_t *head, *current;
    head = (node_t *)malloc(sizeof(node_t));
    head->next = NULL;
    current = head;
    int n;
    printf("Input count of characters you want to add:\n");
    scanf(" %d", &n);
    //append vals
    append(&head, n);
    while (current->next != NULL)
    {
        printf("%c\n", current->c);
        current = current->next;
    }
    printf("\n\n");
    //append to beginning of linked list
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->c = 'A';
    new_node->next = head;
    head = new_node;
    current = new_node;
    //appending to the end of list
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (node_t *)malloc(sizeof(node_t));
    current = current->next;
    current->c = ('A' + 1 + n);
    current->next = NULL;
    //print out list
    current = head;
    while (current != NULL)
    {
        printf("%c\n", current->c);
        current = current->next;
    }
    return 0;
}

void append(node_t **head, int n)
{
    node_t *current = (*head);
    char s = 'B';
    for (int k = 0; k < n; k++)
    {
        current->c = (s + k);
        if (n-1 == k)
        {
            current->next = NULL;
        }else{
            current->next = (node_t *)malloc(sizeof(node_t));
            current = current->next;
            current->next = NULL;
        }
    }
}