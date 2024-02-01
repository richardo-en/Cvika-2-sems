#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char ch;
    struct node *next;
}node_t;

void append(node_t **head);
void reverse(node_t **head);

int main(int argc, char const *argv[])
{
    node_t *head;
    head = (node_t*)malloc(sizeof(node_t));
    head->next = NULL;
    append(&head);
    reverse(&head);
    node_t *curr = head;
    while (curr != NULL)
    {
        printf("%c\n" , curr->ch);
        curr = curr->next;
    }
    return 0;
}

void append(node_t **head){
    node_t *curr = *head;
    char f = 'A';
    for (int i = 0; i < 7; i++)
    {
        curr->ch = (f+i);
        if (i != 6)
        {
            curr->next = (node_t*)malloc(sizeof(node_t));
            curr = curr->next;
        }else{
            curr->next = NULL;
        }
    }
    curr = *head;
}

void reverse(node_t **head){
    node_t *prev = NULL;
    node_t *curr = *head;
    node_t *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}